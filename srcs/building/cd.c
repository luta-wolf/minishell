/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:55:10 by einterdi          #+#    #+#             */
/*   Updated: 2022/06/08 20:41:54 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_pwd(char *pwd, char *oldpwd)
{
	int		i;
	char	*tmp;

	i = -1;
	while (g_term.env[++i].key)
	{
		if (ft_strncmp(g_term.env[i].key, "PWD", 3) == 0
			|| ft_strncmp(g_term.env[i].key, "OLDPWD", 6) == 0)
		{
			if (ft_strncmp(g_term.env[i].key, "PWD", 3) == 0)
				tmp = pwd;
			else
				tmp = oldpwd;
			free(g_term.env[i].var);
			g_term.env[i].var = ft_strdup(tmp);
			if (!g_term.env[i].var)
				return (-1);
			free(tmp);
		}
	}
	return (0);
}

int	ft_op(char **argv)
{
	int	i;

	i = -1;
	if (ft_strncmp(argv[1], "-", 1) == 0)
	{
		while (g_term.env[++i].key)
		{
			if (ft_strncmp(g_term.env[i].key, "OLDPWD", 6) == 0
				&& g_term.env[i].var)
			{
				chdir(g_term.env[i].var);
				printf("%s\n", g_term.env[i].var);
				return (0);
			}
		}
	}
	if (chdir(argv[1]) == -1)
	{
		write(2, "shell: cd: ", ft_strlen("shell: cd: "));
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, ": ", 2);
		perror("");
	}
	return (0);
}

int	ft_cd(char **argv)
{
	char	*pwd;
	char	*oldpwd;
	int		i;

	i = -1;
	oldpwd = getcwd(NULL, 0);
	if (!argv[1] || (ft_strncmp(argv[1], "--", 2) == 0)
		|| (ft_strncmp(argv[1], "~", 1) == 0))
	{
		while (g_term.env[++i].key)
		{
			if (ft_strncmp(g_term.env[i].key, "HOME", 4) == 0)
			{
				pwd = getcwd(NULL, 0);
				chdir(g_term.env[i].var);
				return (change_pwd(pwd, oldpwd));
			}
		}
	}
	ft_op(argv);
	pwd = getcwd(NULL, 0);
	if (change_pwd(pwd, oldpwd) == -1)
		return (-1);
	return (0);
}
