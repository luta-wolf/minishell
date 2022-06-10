/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 12:01:20 by jleslee           #+#    #+#             */
/*   Updated: 2022/06/09 19:54:31 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*free_tab(void **a_free)
{
	if (*a_free)
		free(*a_free);
	*a_free = NULL;
	return (NULL);
}

void	*free_double_tab(void **tab_str, int nb_str)
{
	int	op;

	if (!tab_str)
		return (NULL);
	if (nb_str != -1)
		op = -1;
	else
	{
		nb_str = 0;
		op = 1;
	}
	while (nb_str >= 0 && tab_str[nb_str])
	{
		if (tab_str[nb_str])
			tab_str[nb_str] = free_tab((void **)&(tab_str[nb_str]));
		else
			break ;
		nb_str += (1 * op);
	}
	tab_str = free_tab((void **)&tab_str);
	return (NULL);
}

void	*listing(t_cmd *cmd)
{
	int			i;
	int			j;
	t_cmd		*tmp;

	j = 0;
	i = 1;
	g_term.str_cmd = free_tab((void **)&(g_term.str_cmd));
	if (!cmd)
		return (NULL);
	i = g_term.nb_node;
	while (i > 0)
	{
		tmp = cmd->next;
		cmd = free_node(cmd);
		if (tmp == NULL)
			break ;
		i--;
		cmd = tmp;
	}
	g_term.nb_node = 0;
	g_term.cmd = NULL;
	return (NULL);
}

void	*free_intra_red(t_intra_red **red)
{
	int	i;

	i = -1;
	while ((*red) && (*red)[++i].red)
	{
		(*red)[i].file = free_tab((void **)&((*red)[i].file));
		(*red)[i].red = free_tab((void **)&((*red)[i].red));
	}
	*red = free_tab((void **)&((*red)));
	return (NULL);
}

void	*free_node(t_cmd *tmp)
{
	int	i;

	i = -1;
	if (tmp == NULL)
		return (NULL);
	tmp->cmd = free_tab((void **)&(tmp->cmd));
	tmp->path = free_tab((void **)&(tmp->path));
	tmp->red = free_intra_red(&(tmp->red));
	while (tmp->arg && tmp->arg[++i])
		tmp->arg[i] = free_tab((void **)&(tmp->arg[i]));
	tmp->arg = free_tab((void **)&(tmp->arg));
	tmp->pip = free_tab((void **)&(tmp->pip));
	tmp = free_tab((void **)&tmp);
	return (NULL);
}
