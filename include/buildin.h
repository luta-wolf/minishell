/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:25:33 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/29 15:15:02 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUILDIN_H
# define BUILDIN_H

# include "minishell.h"

# define KEY 0
# define VALUE 1

typedef struct s_node
{
	char			*key;
	char			*value;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

// typedef struct s_mini
// {
// 	int		id;
// 	t_node	*pipe;
// }				t_mini;

// void		rl_replace_line(const char *buffer, int val);

// pars_env
void	pars_env2(char *str);
void	pars_env(char **env);

#endif
