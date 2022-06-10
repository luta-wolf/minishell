/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_ex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:52:12 by einterdi          #+#    #+#             */
/*   Updated: 2022/06/09 19:54:31 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ex_building(t_cmd *cmd)
{
	char	*cpe;
	int		c;

	c = 0;
	cpe = cmd->cmd;
	if (ft_strncmp(cpe, "cd", 10) == 0)
		c = ft_cd(g_term.cmd->arg);
	else if (ft_strncmp(cpe, "pwd", 10) == 0)
		c = ft_pwd(cmd);
	else if (ft_strncmp(cpe, "echo", 10) == 0)
		c = ft_echo(cmd->arg);
	else if (ft_strncmp(cpe, "export", 10) == 0)
		c = ft_export(cmd->arg);
	else if (ft_strncmp(cpe, "unset", 10) == 0)
		c = ft_unset(cmd->arg);
	else if (ft_strncmp(cpe, "env", 5) == 0)
		c = env(cmd);
	else if (ft_strncmp(cpe, "exit", 5) == 0)
		ft_exit(cmd->arg);
	else
		return (-1);
	if (c == -1)
		return (-1);
	return (0);
}

int	ft_exe(t_cmd *cmd)
{
	char	*cpe;
	int		ret;

	ret = 0;
	if (cmd->path == NULL)
		cpe = ft_strdup(cmd->cmd);
	else
		cpe = ft_strjoin(cmd->path, cmd->cmd);
	if (!cpe)
	{
		exit (-1);
		return (-1);
	}
	ret = execve(cpe, cmd->arg, g_term.envp);
	if (ret == -1)
	{
		free(cpe);
		exit (ret);
	}
	free(cpe);
	return (1);
}

void	exec_cmd_2(void)
{
	if (g_term.cmd->pid == 0
		&& check_building(g_term.cmd) == 1
		&& g_term.cmd->pip[0] == ';'
		&& !g_term.cmd->red)
		exit (0);
	else if (g_term.cmd->pid == 0)
	{
		if (!g_term.cmd->cmd)
		{
			if (g_term.cmd->pid == 0)
				exit (0);
			return ;
		}
		if (g_term.cmd->pid == 0)
		{
			if (check_building(g_term.cmd) == 1)
				g_term.dernier_ret = ex_building(g_term.cmd);
			else
				g_term.dernier_ret = ft_exe(g_term.cmd);
		}
	}
}

int	exec_cmd(void)
{
	int		x;

	x = 0;
	if (g_term.cmd->pid != 0)
	{
		while (x < g_term.nb_node)
		{
			if (check_building(g_term.cmd) == 1
				&& g_term.cmd->pip[0] == ';'
				&& !g_term.cmd->red)
			{
				g_term.dernier_ret = ex_building(g_term.cmd);
				if (g_term.dernier_ret != 0)
					dprintf(2, RED"shell: file not foundr\n"RESET);
			}
			g_term.cmd = g_term.cmd->next;
			x++;
		}
	}
	exec_cmd_2();
	return (1);
}

int	message_error(void)
{
	if (g_term.dernier_ret == 255 || g_term.dernier_ret == 139)
		printf(RED"shell: %s : command not found\n"RESET,
			g_term.cmd->cmd);
	if (g_term.dernier_ret == -1)
		printf(RED"shell: %s : too many arguments\n"RESET,
			g_term.cmd->cmd);
	return (1);
}
