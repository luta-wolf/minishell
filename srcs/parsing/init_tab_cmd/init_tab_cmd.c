/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:42:30 by jleslee           #+#    #+#             */
/*   Updated: 2022/06/07 20:18:24 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_tab_cmd_3(char **tmp)
{
	int		w;

	w = 0;
	while ((*tmp)[w])
	{
		if (ft_whitespace((*tmp)[w]) == 0)
			break ;
		w++;
	}
	if (!(*tmp)[w] || (*tmp)[w] == '|' || (*tmp)[w] == ';'
		|| ((*tmp)[w] == '&' && (*tmp)[w + 1] == '&')
		|| ((*tmp)[w] == '|' && (*tmp)[w + 1] == '|'))
		return (-1);
	return (1);
}

char	*init_tab_cmd_2(char **str, int *quote)
{
	char	*res;

	res = NULL;
	while (1)
	{
		check_quote(quote, *(*str));
		res = ft_strmicrojoin(&res, *(*str));
		if ((*quote == 0 && ((*(*str) == ';')
					|| (*(*str) == '&' && *((*str) - 1) == '&')
					|| (*(*str) == '|' && *((*str) - 1) == '|')
					|| (*(*str) == '|' && *((*str) + 1) != '|')))
			|| *(*str) == '\0')
			return (res);
		(*str)++;
	}
	return (res);
}

char	**init_tab_cmd(char *str)
{
	char	**tab_cmd;
	int		i;
	char	*tmp;
	char	**tmp_2;
	int		quote;

	quote = 0;
	i = -1;
	tab_cmd = NULL;
	while (*str)
	{
		tmp = init_tab_cmd_2(&str, &quote);
		tmp_2 = ft_strdoubledup(tab_cmd);
		tab_cmd = free_double_tab((void **)tab_cmd, -1);
		tab_cmd = ft_strdoublejoin(tmp_2, tmp);
		tmp_2 = free_double_tab((void **)tmp_2, -1);
		tmp = free_tab((void **)&tmp);
		if (!(*str))
			break ;
		str++;
	}
	while (tab_cmd[++i])
		if (init_tab_cmd_3(&(tab_cmd[i])) == -1 && tab_cmd[i + 1] != NULL)
			return (free_double_tab((void **)tab_cmd, -1));
	return (tab_cmd);
}
