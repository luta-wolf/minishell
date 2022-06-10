/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 09:22:31 by jleslee           #+#    #+#             */
/*   Updated: 2022/06/08 21:05:45 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quote(int *quote, char c)
{
	int	i;

	i = *quote;
	if (*quote == 0 && c == '\'')
		*quote = 1;
	else if (*quote == 0 && c == '\"')
		*quote = 2;
	else if (*quote == 1 && c == '\'')
		*quote = 0;
	else if (*quote == 2 && c == '\"')
		*quote = 0;
	if (i != *quote)
		return (-1);
	return (1);
}

int	check_redirect(int quote, char c)
{
	if (c == '>' && quote == 0)
		return (-1);
	else if (c == '<' && quote == 0)
		return (-2);
	return (1);
}

int	sub_char(char **str, int i)
{
	char	*tmp;
	char	*tmp_2;
	char	c;

	c = (*str)[i];
	(*str)[i] = '\0';
	tmp = ft_strdup((*str));
	(*str)[i] = c;
	tmp_2 = ft_strjoin(tmp, &((*str)[i + 1]));
	*str = free_tab((void **)str);
	*str = tmp_2;
	return (1);
}
