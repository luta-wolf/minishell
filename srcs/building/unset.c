/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:35:20 by einterdi          #+#    #+#             */
/*   Updated: 2022/06/08 20:41:54 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	supp_var_2(char *argv, t_env **new, int j, int len)
{
	int		len_2;
	char	*tmp;

	len_2 = ft_strlen(g_term.env[len].key) - 1;
	if (g_term.env[len].key[len_2] == '=')
	{
		g_term.env[len].key[len_2] = '\0';
		tmp = ft_strdup(g_term.env[len].key);
		g_term.env[len].key[len_2] = '=';
	}
	else
		tmp = ft_strdup(g_term.env[len].key);
	if (ft_strncmp(tmp, argv, ft_strlen(tmp)) == 0)
	{
		free(tmp);
		free(g_term.env[len].key);
		if (g_term.env[len].var)
			free(g_term.env[len].var);
		return (1);
	}
	free(tmp);
	(*new)[j].key = g_term.env[len].key;
	(*new)[j].var = g_term.env[len].var;
	return (0);
}

void	supp_var(char *argv)
{
	int		len;
	t_env	*new;
	int		j;

	len = 0;
	while (g_term.env[len].key)
		len++;
	new = malloc(sizeof(t_env) * (len + 1));
	if (!new)
		return ;
	j = 0;
	len = -1;
	while (g_term.env[++len].key != NULL)
	{
		if (supp_var_2(argv, &new, j, len) == 1)
			continue ;
		j++;
	}
	new[j].key = NULL;
	new[j].var = NULL;
	free(g_term.env);
	g_term.env = new;
	return ;
}

int	mess_err(char *str)
{
	write(2, "shell: unset: '", 19);
	write(2, str, ft_strlen(str));
	write(2, "': not a valid identifier\n", 26);
	return (1);
}

int	check(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]) && str[i] != '_')
		mess_err(str);
	i++;
	while (str[i])
	{
		if (!ft_isalpha(str[i]) && str[i] != '_' && !ft_isdigit(str[i]))
			mess_err(str);
		i++;
	}
	return (0);
}

int	ft_unset(char **argv)
{
	int	i;

	i = 0;
	if (!argv[1])
		return (0);
	while (argv[i])
	{
		if (check(argv[i]) == -1)
			return (-1);
		supp_var(argv[i]);
		i++;
	}
	return (0);
}
