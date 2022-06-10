/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:35:30 by einterdi          #+#    #+#             */
/*   Updated: 2022/06/07 20:38:44 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	overwrite_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		if (remove(file) != 0)
			return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		fd = open(file, O_CREAT);
	else
		close(fd);
	return (1);
}

int	return_fd(char *file, int i)
{
	int		fd;
	char	c;

	fd = -1;
	if (ft_strncmp(g_term.cmd->red[i].red, ">", 3) == 0)
		overwrite_file(file);
	fd = open(file, O_RDWR);
	if (fd == -1 && ft_strncmp(g_term.cmd->red[i].red, "<", 3) != 0)
	{
		close(fd);
		fd = open(file, O_CREAT);
		if (fd == -1)
			return (-1);
	}
	close(fd);
	fd = open(file, O_RDWR);
	if (fd == -1)
		return (-1);
	if (ft_strncmp(g_term.cmd->red[i].red, ">>", 3) == 0)
		while (read(fd, &c, 1) > 0)
			c = 'a';
	return (fd);
}

int	connect_redirect(void)
{
	int		i;
	int		fd;

	i = -1;
	fd = 0;
	while (g_term.cmd->red && g_term.cmd->red[++i].red)
	{
		if (ft_strncmp(g_term.cmd->red[i].red, "<<", 3) == 0)
			continue ;
		fd = return_fd(g_term.cmd->red[i].file, i);
		if (ft_strncmp(g_term.cmd->red[i].red, ">", 3) == 0
			|| ft_strncmp(g_term.cmd->red[i].red, ">>", 3) == 0)
			dup2(fd, 1);
		else if (ft_strncmp(g_term.cmd->red[i].red, "<", 3) == 0)
		{
			if (fd == -1)
				printf(RED"No such file or directory\n"RESET);
			if (fd == -1)
				exit (1);
			dup2(fd, 0);
		}
		if (fd != -1)
			close(fd);
	}
	return (1);
}
