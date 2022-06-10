/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_red.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:47:37 by jleslee           #+#    #+#             */
/*   Updated: 2022/06/09 20:03:54 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len_double_tab(t_intra_red *red)
{
	int	res;

	res = 0;
	if (!red)
		res = 0;
	else
		while (red[res].red != NULL)
			res++;
	return (res);
}

t_intra_red	*realoc_red(t_intra_red **red, char *file, char *redi)
{
	int			len;
	t_intra_red	*new;

	len = len_double_tab(*red);
	new = malloc(sizeof(t_intra_red) * (len + 2));
	if (!new)
		return (NULL);
	len = 0;
	while ((*red) && (*red)[len].red)
	{
		new[len].file = (*red)[len].file;
		new[len].red = (*red)[len].red;
		len++;
	}
	new[len].file = ft_strdup(file);
	new[len].red = ft_strdup(redi);
	len++;
	new[len].file = NULL;
	new[len].red = NULL;
	free_tab((void **)red);
	return (new);
}

int	return_red_2(char **str, int *i, t_intra_red **red)
{
	char		*tmp;
	char		*tmp_2;
	int			type_red;

	type_red = 0;
	type_red = check_redirect_type(&(*str)[*i]);
	if (type_red < 5)
		return (-1);
	tmp = take_redirect(type_red, i, str);
	tmp_2 = return_ellement(str, i);
	*red = realoc_red(red, tmp_2, tmp);
	tmp = free_tab((void **) &tmp);
	tmp_2 = free_tab((void **) &tmp_2);
	return (1);
}

t_intra_red	*return_red(char **str)
{
	int			i;
	t_intra_red	*red;
	int			quote;

	i = -1;
	quote = 0;
	red = NULL;
	while ((*str)[++i])
	{
		check_quote(&quote, (*str)[i]);
		if (quote == 0)
		{
			if (return_red_2(str, &i, &red) == -1)
				continue ;
			if (!(*str)[i])
				break ;
		}
	}
	return (red);
}
