/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:25:33 by einterdi          #+#    #+#             */
/*   Updated: 2022/05/27 14:28:30 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUILDIN_H
# define BUILDIN_H

# include "../libft/libft.h"
# include <stdio.h> // printf, strerror, perror,
# include <stdlib.h> // malloc, free, exit, getenv,
# include <unistd.h> // write, access, read, close, fork, getcwd, chdir, unlink,  execve, dup, dup2, pipe, isatty, ttyname, ttyslot,
# include <fcntl.h> // open,
# include <signal.h> // signal, sigaction, sigemptyset, sigaddset, kill,
# include <dirent.h> // opendir, readdir, closedir,
# include <sys/wait.h> //wait, waitpid, wait3, wait4,
# include <sys/stat.h> // stat, lstat, fstat,
# include <sys/ioctl.h> // ioctl,
# include <termios.h> //  tcsetattr, tcgetattr,
# include <term.h> // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <readline/readline.h> //readline, rl_on_new_line, rl_replace_line
# include <readline/history.h> //rl_clear_history, add_history, rl_redisplay

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
