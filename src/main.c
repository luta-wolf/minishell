/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:09:02 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/29 19:50:45 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	char *line;
	(void)argc;
	// (void)argv;
	// (void)env;

	printf("Hello");
	pars_env2(argv[0]);
	pars_env(env);
	line = readline(YEL"shell-3.2$ "RESET);
	printf("line = %s\n", line);
	return (0);
}
