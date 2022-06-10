/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_var_env_utile.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:53:40 by einterdi          #+#    #+#             */
/*   Updated: 2022/06/08 20:41:54 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*return_key(char *str, int *i)
{
	char	*res;

	res = NULL;
	(*i)++;
	while (str[*i] == '_'
		|| (str[*i] >= 'a' && str[*i] <= 'z')
		|| (str[*i] >= 'A' && str[*i] <= 'Z')
		|| (str[*i] >= '0' && str[*i] <= '9')
		|| str[*i] >= '?')
	{
		res = ft_strmicrojoin(&res, str[*i]);
		(*i)++;
	}
	res = ft_strmicrojoin(&res, '=');
	return (res);
}

char	*return_var_env(char *str, int i)
{
	char	*key;
	char	*res;
	int		y;

	y = 0;
	key = return_key(str, &i);
	if (key[0] == '?' && key[1] == '=' && key[2] == '\0')
	{
		return (ft_itoa(g_term.dernier_ret));
	}
	while (g_term.env && g_term.env[y].key)
	{
		if (ft_strncmp(g_term.env[y].key, key
				, ft_strlen(g_term.env[y].key)) == 0)
		{
			res = ft_strdup(g_term.env[y].var);
			key = free_tab((void **)&key);
			return (res);
		}
		y++;
	}
	key = free_tab((void **)&key);
	return (NULL);
}

int	change_cmd(char **str, char *var_env, int i)
{
	char	*tmp;
	char	*tmp_2;

	(*str)[i] = '\0';
	tmp = ft_strdup(*str);
	(*str)[i] = '$';
	if (var_env)
		tmp_2 = ft_strjoin(tmp, var_env);
	else
		tmp_2 = ft_strdup(tmp);
	tmp = free_tab((void **)&tmp);
	while ((*str)[i] && ((*str)[i] == '_' || (*str)[i] == '$'
		|| ((*str)[i] >= 'a' && (*str)[i] <= 'z')
		|| ((*str)[i] >= 'A' && (*str)[i] <= 'Z')
		|| ((*str)[i] >= '0' && (*str)[i] <= '9')
		|| (*str)[i] == '?'))
		i++;
	if ((*str)[i])
		tmp = ft_strjoin(tmp_2, &((*str)[i]));
	else
		tmp = ft_strdup(tmp_2);
	tmp_2 = free_tab((void **)&tmp_2);
	*str = free_tab((void **)str);
	*str = tmp;
	return (1);
}

int	check_var_env(char **str)
{
	int		i;
	int		quotes;
	char	*var_env;

	quotes = 0;
	i = 0;
	var_env = NULL;
	while ((*str)[i])
	{
		check_quote(&quotes, (*str)[i]);
		if ((quotes == 0 || quotes == 2) && (*str)[i] == '$')
		{
			var_env = return_var_env(*str, i);
			change_cmd(str, var_env, i);
			var_env = free_tab((void **)&var_env);
			if (!(*str)[0])
			{
				(*str) = free_tab((void **)str);
				return (-1);
			}
		}
		i++;
	}
	return (1);
}

int	cleaning_quotes(char **str)
{
	int	i;
	int	quotes;

	i = -1;
	quotes = 0;
	if (!*str)
		return (1);
	while ((*str)[++i])
	{
		check_quote(&quotes, (*str)[i]);
		if (quotes == 2 && (*str)[i] == '\'')
			continue ;
		else if (quotes == 1 && (*str)[i] == '\"')
			continue ;
		else if (((*str)[i] == '\"' || (*str)[i] == '\''))
		{
			sub_char(str, i);
			i--;
		}
	}
	return (1);
}
