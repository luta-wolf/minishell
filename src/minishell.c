/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:09:02 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/27 13:45:10 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	// (void)argv;
	// (void)env;

	printf("Hello");
	pars_env2(argv[0]);
	pars_env(env);
	return (0);
}
