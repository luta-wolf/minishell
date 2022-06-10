/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:10:42 by jleslee           #+#    #+#             */
/*   Updated: 2022/06/09 20:03:54 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**realloc_double_tab(char **tabe, char **tmp)
{
	char	**new;
	int		i;

	i = 0;
	while (tabe && tabe[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (tabe && tabe[i])
	{
		new[i] = ft_strdup(tabe[i]);
		i++;
	}
	new[i++] = ft_strdup(*tmp);
	new[i] = NULL;
	tabe = free_double_tab((void **)tabe, -1);
	return (new);
}

char	**return_arg(char **tab_cmd, t_cmd *cmd)
{
	int		i;
	char	**res;
	char	*tmp;

	i = -1;
	res = NULL;
	tmp = NULL;
	if (cmd->path)
		tmp = ft_strjoin(cmd->path, cmd->cmd);
	else if (cmd->cmd)
		tmp = ft_strdup(cmd->cmd);
	res = realloc_double_tab(res, &tmp);
	tmp = free_tab((void **)&tmp);
	while ((*tab_cmd)[++i])
	{
		while (ft_whitespace((*tab_cmd)[i]) == 1)
			i++;
		tmp = return_ellement(tab_cmd, &i);
		res = realloc_double_tab(res, &tmp);
		tmp = free_tab((void **)&tmp);
		if (!(*tab_cmd)[i])
			break ;
	}
	return (res);
}

char	*return_pipe(char **cmd)
{
	char	*res;
	int		i;
	int		red;
	int		quote;

	i = -1;
	res = NULL;
	quote = 0;
	while ((*cmd)[++i])
	{
		check_quote(&quote, (*cmd)[i]);
		if (quote != 0)
			continue ;
		red = check_redirect_type(&((*cmd)[i]));
		if (red > 0 && red < 5)
			res = take_redirect(red, &i, cmd);
		if (!(*cmd)[i])
			break ;
	}
	if (!res)
		res = ft_strdup(";");
	return (res);
}
