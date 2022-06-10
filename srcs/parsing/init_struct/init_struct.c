/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:40:08 by jleslee           #+#    #+#             */
/*   Updated: 2022/06/09 19:54:31 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*init_node(char *tab_cmd)
{
	t_cmd	*tmp;

	tmp = NULL;
	tmp = malloc(sizeof(t_cmd));
	if (!tmp)
		return (NULL);
	bzero(tmp, sizeof(t_cmd));
	tmp->red = return_red(&tab_cmd);
	tmp->cmd = return_cmd(&tab_cmd);
	tmp->path = return_path(&tmp->cmd);
	if (!tmp->path)
		tmp->path = return_path_env(tmp->cmd);
	tmp->pip = return_pipe(&tab_cmd);
	tmp->arg = return_arg(&tab_cmd, tmp);
	return (tmp);
}

int	add_new_element(t_cmd *tmp)
{
	int		i;
	t_cmd	*tmp_1;

	i = 0;
	if (!tmp)
		return (-1);
	if (!g_term.cmd)
	{
		g_term.cmd = tmp;
		g_term.cmd->next = tmp;
		g_term.cmd->prev = tmp;
	}
	else
	{
		tmp_1 = g_term.cmd;
		while (++i < g_term.nb_node)
			g_term.cmd = g_term.cmd->next;
		g_term.cmd->next = tmp;
		tmp_1->prev = tmp;
		tmp->prev = g_term.cmd;
		tmp->next = tmp_1;
		g_term.cmd = tmp_1;
	}
	g_term.nb_node++;
	return (1);
}

int	create_cmd(char **tab_cmd)
{
	int		i;

	i = 0;
	g_term.nb_node = 0;
	while (tab_cmd[i])
	{
		if (add_new_element(init_node(tab_cmd[i])) == -1)
			return (-1);
		i++;
	}
	return (1);
}
