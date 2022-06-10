/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:50:35 by jleslee           #+#    #+#             */
/*   Updated: 2022/06/08 20:50:06 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_term	g_term;

int	free_all(int ret)
{
	int	i;

	i = 0;
	while (g_term.env && g_term.env[i].key != NULL)
	{
		g_term.env[i].key = free_tab((void **)&(g_term.env[i].key));
		g_term.env[i].var = free_tab((void **)&(g_term.env[i].var));
		i++;
	}
	rl_clear_history();
	if (g_term.env)
		g_term.env = free_tab((void **)&(g_term.env));
	return (ret);
}

int	launch_setup(int ac, char **envp)
{
	if (ac != 1)
		return (-1);
	start_write();
	signal(SIGINT, handler_ctr_c);
	signal(SIGQUIT, SIG_IGN);
	g_term.envp = envp;
	g_term.env = NULL;
	if (init_struct_env() == -1)
		return (-1);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	(void)av;
	if (launch_setup(ac, envp) == -1)
		return (-1);
	while (1)
	{
		g_term.str_cmd = NULL;
		g_term.str_cmd = readline(BLU_2"shell-3.2$ "RESET);
		if (g_term.str_cmd == 0)
		{
			free(g_term.str_cmd);
			rl_clear_history();
			return (free_all(-1));
		}
		if (g_term.str_cmd[0])
		{
			add_history(g_term.str_cmd);
			if (launch() == -1)
				return (free_all(-1));
		}
		else
			free(g_term.str_cmd);
	}
	return (free_all(0));
}
