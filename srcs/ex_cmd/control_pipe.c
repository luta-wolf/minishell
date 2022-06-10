/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:24:41 by einterdi          #+#    #+#             */
/*   Updated: 2022/06/09 19:54:31 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close_pipe(t_cmd *cmd)
{
	close(cmd->tub[IN]);
	close(cmd->tub[OUT]);
}

void	connect_pipe(void)
{
	if (ft_strncmp(g_term.cmd->pip, "|", 3) == 0)
	{
		close(g_term.cmd->tub[OUT]);
		dup2(g_term.cmd->tub[IN], 1);
		close(g_term.cmd->tub[IN]);
	}
	else
	{
		ft_close_pipe(g_term.cmd);
	}
	if (ft_strncmp(g_term.cmd->prev->pip, "|", 3) == 0)
	{
		close(g_term.cmd->prev->tub[IN]);
		dup2(g_term.cmd->prev->tub[OUT], 0);
		close(g_term.cmd->prev->tub[OUT]);
	}
}

void	close_pipe(void)
{
	t_cmd	*tmp;
	int		i;

	i = 0;
	tmp = g_term.cmd;
	while (i++ < g_term.nb_node)
	{
		ft_close_pipe(g_term.cmd);
		g_term.cmd = g_term.cmd->next;
	}
	g_term.cmd = tmp;
}

void	creat_pipe(void)
{
	t_cmd	*tmp;
	int		i;

	i = 0;
	tmp = g_term.cmd;
	while (i++ < g_term.nb_node)
	{
		pipe(g_term.cmd->tub);
		g_term.cmd = g_term.cmd->next;
	}
	g_term.cmd = tmp;
}
