/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:00:02 by einterdi          #+#    #+#             */
/*   Updated: 2022/06/08 20:41:54 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp_2(char *str1, char *str2, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size && ((str1[i]) || (str2[i])))
	{
		if (str1[i] == '=' && (str2[i] == '=' || !str2[i]))
			return (0);
		if (str2[i] == '=' && (str1[i] == '=' || !str1[i]))
			return (0);
		else if ((unsigned char)str1[i] < (unsigned char)str2[i])
			return (-1);
		else if ((unsigned char)str1[i] > (unsigned char)str2[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_duplication_key(char *key, int index)
{
	int		i;

	i = 0;
	if (index == 1)
	{
		while (g_term.env[i].key)
		{
			if (ft_strncmp_2(g_term.env[i].key, key, 1000) == 0)
				return (i);
			i++;
		}
		return (-1);
	}
	if (!ft_isalpha(key[i]) && key[i] != '_')
		return (error_message(key));
	i++;
	while (key[i])
	{
		if (!ft_isalpha(key[i]) && key[i] != '_'
			&& !ft_isdigit(key[i]) && key[i] != '=')
			return (error_message(key));
		i++;
	}
	return (0);
}

int	add_new_env(char **key, char **var)
{
	int		len;
	t_env	*new;

	len = 0;
	while (g_term.env[len].key)
		len++;
	new = malloc(sizeof(t_env) * (len + 2));
	if (!new)
		return (-1);
	len = 0;
	while (g_term.env[len].key)
	{
		new[len].key = g_term.env[len].key;
		new[len].var = g_term.env[len].var;
		len++;
	}
	new[len].key = *key;
	new[len].var = *var;
	len++;
	new[len].key = NULL;
	new[len].var = NULL;
	free(g_term.env);
	g_term.env = new;
	return (1);
}

int	added_arg_ei(char **key, char **var)
{
	int	check;

	check = check_duplication_key(*key, 1);
	if (check >= 0)
	{
		if ((*key)[ft_strlen(*key) - 1] != '=')
			return (1);
		free(g_term.env[check].var);
		g_term.env[check].key = *key;
		g_term.env[check].var = *var;
	}
	if (check_duplication_key(*key, 1) == -1)
	{
		if (add_new_env(key, var) == -1)
		{
			free(*var);
			free(*key);
			return (-1);
		}
	}
	return (1);
}

int	added_arg(char **arg)
{
	int		y;
	char	*key;
	char	*var;
	int		i;

	y = -1;
	i = -1;
	while (arg[++y])
	{
		key = str(arg[y], 0);
		if (!key || check_duplication_key(key, 0) == -1)
			return (-1);
		var = str(arg[y], 1);
		if (added_arg_ei(&key, &var) == -1)
			return (-1);
	}
	return (1);
}
