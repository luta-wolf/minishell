/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_ex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 08:27:33 by einterdi          #+#    #+#             */
/*   Updated: 2022/06/09 19:54:31 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	control_logic_operation(int	*verif, int	*verif_2)
{
	if (g_term.cmd->pid != 0)
	{
		if (ft_strcmp(g_term.cmd->prev->pip, "&&") == 0)
		{
			waitpid(g_term.cmd->prev->pid, &(*verif), 0);
			if (WIFEXITED((*verif)))
				(*verif) = WEXITSTATUS((*verif));
		}
		if (ft_strcmp(g_term.cmd->prev->pip, "||") == 0)
		{
			waitpid(g_term.cmd->prev->pid, &(*verif_2), 0);
			if (WIFEXITED((*verif_2)))
				(*verif_2) = WEXITSTATUS((*verif_2));
		}
		usleep(1000);
	}
	if ((*verif != 0 || *verif_2 == 0)
		&& check_building(g_term.cmd) == 1
		&& g_term.cmd->pip[0] == ';'
		&& !g_term.cmd->red)
		g_term.cmd->cmd = free_tab((void **)&g_term.cmd->cmd);
	return (1);
}

void	creat_fork(void)
{
	t_cmd	*tmp;
	int		i;
	int		verif;
	int		verif_2;

	i = 0;
	verif = 0;
	verif_2 = -1;
	tmp = g_term.cmd;
	while (i++ < g_term.nb_node)
	{
		g_term.cmd->pid = -1;
		control_logic_operation(&verif, &verif_2);
		if (verif == 0 && verif_2 != 0)
		{
			g_term.cmd->pid = fork();
			if (g_term.cmd->pid == 0)
				return ;
		}
		else
			g_term.dernier_ret = verif;
		g_term.cmd = g_term.cmd->next;
	}
	g_term.cmd = tmp;
}

void	waiting_loop(void)
{
	t_cmd	*tmp;
	int		i;

	i = 0;
	tmp = g_term.cmd;
	if (g_term.cmd->pid != 0)
	{
		while (i++ < g_term.nb_node)
		{
			waitpid(g_term.cmd->pid, &g_term.dernier_ret, 0);
			if (WIFEXITED(g_term.dernier_ret))
				g_term.dernier_ret = WEXITSTATUS(g_term.dernier_ret);
			g_term.cmd = g_term.cmd->next;
		}
		message_error();
	}
	g_term.cmd = tmp;
}

int	launch_ex_2(void)
{
	creat_pipe();
	creat_fork();
	control_var_env_quotes(g_term.cmd);
	if (g_term.cmd->pid == 0)
	{
		connect_pipe();
		if (connect_redirect() == -1)
			return (-1);
		connect_heredoc();
	}
	close_pipe();
	exec_cmd();
	waiting_loop();
	return (1);
}

int	launch(void)
{
	int	parsing;

	parsing = init_parsing();
	if (parsing != 0)
	{
		if (parsing == 3 || parsing == -1)
			printf(RED"Syntax error\n"RESET);
		listing(g_term.cmd);
		return (1);
	}
	signal(SIGQUIT, handler_ctr_backslash);
	signal(SIGINT, handler_ctr_c_2);
	launch_ex_2();
	signal(SIGINT, handler_ctr_c);
	signal(SIGQUIT, SIG_IGN);
	listing(g_term.cmd);
	return (1);
}
