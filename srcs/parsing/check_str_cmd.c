/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:17:25 by jleslee           #+#    #+#             */
/*   Updated: 2022/06/07 20:18:44 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_nb_quotes(char *str)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (str[i])
	{
		if (quote == 0 && str[i] == '\'')
			quote = 1;
		else if (quote == 0 && str[i] == '\"')
			quote = 2;
		else if (quote == 1 && str[i] == '\'')
			quote = 0;
		else if (quote == 2 && str[i] == '\"')
			quote = 0;
		i++;
	}
	return (quote);
}

int	check_bad_redirect(char *str)
{
	int	i;
	int	quote;
	int	tem;

	i = 0;
	quote = 0;
	tem = 0;
	while (str[i])
	{
		check_quote(&quote, str[i]);
		if (check_redirect(quote, str[i]) < 0)
			tem++;
		else
			tem = 0;
		if (tem == 3)
			return (-1);
		i++;
	}
	return (1);
}
