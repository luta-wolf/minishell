/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:09:02 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/29 15:19:21 by jleslee          ###   ########.fr       */
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
