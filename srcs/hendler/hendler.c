/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hendler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 20:10:46 by jleslee           #+#    #+#             */
/*   Updated: 2022/06/07 20:11:01 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler_ctr_c(int code)
{
	int	i;

	i = 0;
	(void)code;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handler_ctr_c_2(int code)
{
	int	i;

	(void)code;
	i = 0;
	printf("\n");
}

void	handler_ctr_backslash(int code)
{
	(void)code;
	printf(RED"Fault (Core dumped)\n"RESET);
}
