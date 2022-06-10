/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:29:06 by einterdi          #+#    #+#             */
/*   Updated: 2022/06/07 20:32:35 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_message(char *str)
{
	write(2, "shell: export: '", 20);
	write(2, str, ft_strlen(str));
	write(2, "': not a valid identifier\n", 26);
	return (1);
}

int	ft_export(char **argv)
{
	if (!argv[1])
	{
		if (print_export() == -1)
			return (-1);
	}
	else
	{
		if (added_arg(&(argv[1])) == -1)
			return (-1);
	}
	return (1);
}
