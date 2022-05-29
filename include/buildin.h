/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:25:33 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/29 19:45:19 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUILDIN_H
# define BUILDIN_H

# include "minishell.h"

# define RED    "\x1b[31m"
# define BLU    "\x1B[34m"
# define GRN    "\x1B[32m"
# define YEL    "\x1B[33m"
# define MAG    "\x1B[35m"
# define CYN    "\x1B[36m"
# define WHT    "\x1B[37m"
# define RESET  "\x1B[0m"

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
