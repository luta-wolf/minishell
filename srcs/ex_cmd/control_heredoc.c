/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:48:24 by einterdi          #+#    #+#             */
/*   Updated: 2022/06/07 20:37:54 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_sort_2(char **str, char **res, int option, int *tub)
{
	close(tub[OUT]);
	dup2(tub[IN], 1);
	close(tub[IN]);
	if (option == 0)
		check_var_env(res);
	write(2, (*res), ft_strlen((*res)));
	write(2, ": command not found\n", ft_strlen(": command not found\n"));
	*str = free_tab((void **)str);
	*res = free_tab((void **)res);
	exit(0);
	return (1);
}

int	choose_option(char *fin, char *deb)
{
	int	i;

	i = -1;
	while (fin[++i])
		if (fin[i] == '\"' || fin[i] == '\'')
			return (1);
	i = -1;
	while (deb && deb[++i])
		if (deb[i] == '\"' || deb[i] == '\'')
			return (1);
	return (0);
}

int	my_lancement_heredoc(char *deb, char *fin)
{
	pid_t	pid;
	int		tub[2];

	pipe(tub);
	pid = fork();
	if (pid != 0)
	{
		close(tub[IN]);
		dup2(tub[OUT], 0);
		close(tub[OUT]);
	}
	if (pid == 0)
		ft_heredoc(deb, fin, choose_option(fin, deb), tub);
	if (pid != 0)
		waitpid(pid, NULL, 0);
	return (1);
}

int	connect_heredoc(void)
{
	int		i;
	char	*fin;
	char	*deb;

	i = 0;
	fin = NULL;
	deb = NULL;
	while (g_term.cmd->red && g_term.cmd->red[i].red)
	{
		if (ft_strncmp(g_term.cmd->red[i].red, "<<", 3) == 0
			&& (!g_term.cmd->red[i + 1].red
				|| ft_strncmp(g_term.cmd->red[i + 1].red, "<<", 3) != 0))
		{
			fin = g_term.cmd->red[i].file;
			break ;
		}
		if (ft_strncmp(g_term.cmd->red[i].red, "<<", 3) == 0
			&& g_term.cmd->red[i].red
			&& ft_strncmp(g_term.cmd->red[i + 1].red, "<<", 3) == 0)
			deb = g_term.cmd->red[i].file;
		i++;
	}
	if (fin)
		my_lancement_heredoc(deb, fin);
	return (1);
}
