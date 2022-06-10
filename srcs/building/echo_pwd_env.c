/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_pwd_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:32:47 by einterdi          #+#    #+#             */
/*   Updated: 2022/06/08 20:41:54 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	option(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) >= 2)
	{
		if (str[0] == '-' && str[1] == 'n')
		{
			while (str[++i])
			{
				if (str[i] != 'n')
					return (0);
				return (1);
			}
		}
	}
	return (0);
}

int	ft_echo(char **argv)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	while (argv[i] && option(argv[i]))
	{
		flag = 1;
		i++;
	}
	if (!(argv[i]) && flag == 0)
		printf("\n");
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		else if (!(argv[i + 1]) && flag == 0)
			printf("\n");
		i++;
	}
	if (g_term.cmd->pid == 0)
		exit (0);
	else
		return (0);
}

int	ft_pwd(t_cmd *cmd)
{
	char	*pwd;

	if (!cmd->arg[1])
	{
		pwd = getcwd(NULL, 0);
		printf("%s\n", pwd);
		free(pwd);
	}
	else
		printf(RED"pwd: -a : option non valable\n"RESET);
	if (g_term.cmd->pid == 0)
		exit (0);
	else
		return (0);
}

int	env(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (!cmd->arg[1])
	{
		while (g_term.env[i].key)
		{
			if (g_term.env[i].key[ft_strlen(
						g_term.env[i].key) - 1] == '=')
			{
				printf("%s", g_term.env[i].key);
				if (g_term.env[i].var)
					printf("%s", g_term.env[i].var);
				printf("\n");
			}
			i++;
		}
	}
	else
		printf(RED"env: option non valable\n"RESET);
	if (g_term.cmd->pid == 0)
		exit (0);
	else
		return (0);
}
