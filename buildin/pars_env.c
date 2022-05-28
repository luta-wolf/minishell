/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:31:44 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/27 14:27:46 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pars_env2(char *str)
{
	printf(" %s\n", str);
}

void	pars_env(char **env)
{
	int		i;
	// char	*tmp;

	i = -1;
	while(env[++i])
	{
	// 	tmp = ft_split(env[i], "=");

	// 	free (tmp);
	}
}
