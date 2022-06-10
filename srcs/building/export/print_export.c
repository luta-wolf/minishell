/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 10:16:53 by einterdi          #+#    #+#             */
/*   Updated: 2022/06/08 20:41:54 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*copy_env(void)
{
	t_env	*env;
	int		i;

	i = 0;
	while (g_term.env[i].key)
		i++;
	env = malloc(sizeof(t_env) * (i + 1));
	if (!env)
		return (NULL);
	i = 0;
	while (g_term.env[i].key)
	{
		env[i].key = g_term.env[i].key;
		env[i].var = g_term.env[i].var;
		i++;
	}
	env[i].key = NULL;
	return (env);
}

int	sort(t_env **tmp)
{
	int		i;
	int		j;
	t_env	tmp_2;

	i = -1;
	while ((*tmp)[++i].key)
	{
		j = i;
		while ((*tmp)[++j].key)
		{
			if (ft_strncmp((*tmp)[i].key, (*tmp)[j].key,
				ft_strlen((*tmp)[j].key)) > 0)
			{
				tmp_2 = (*tmp)[i];
				(*tmp)[i] = (*tmp)[j];
				(*tmp)[j] = tmp_2;
			}
		}
	}
	return (0);
}

int	print_export(void)
{
	int		i;
	t_env	*tmp;

	i = -1;
	tmp = copy_env();
	if (!tmp)
		return (-1);
	sort(&tmp);
	i = -1;
	while (tmp[++i].key)
	{
		printf("declare -i %s", tmp[i].key);
		if (tmp[i].var)
			printf("\"%s\"", tmp[i].var);
		else if (tmp[i].key[ft_strlen(tmp[i].key) - 1] == '=')
			printf("\"\"");
		printf("\n");
	}
	free(tmp);
	return (0);
}
