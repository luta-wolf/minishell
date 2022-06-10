/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:00:44 by jleslee           #+#    #+#             */
/*   Updated: 2022/06/09 20:03:54 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libs.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <curses.h>
# include <term.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>

# define RED    "\x1b[31m"
# define BLU    "\x1B[34m"
# define BLU_2 "\e[1;34m"
# define GRN    "\x1B[32m"
# define YEL    "\x1B[33m"
# define MAG    "\x1B[35m"
# define CYN    "\x1B[36m"
# define WHT    "\x1B[37m"
# define RESET  "\x1B[0m"

typedef struct s_intra_red
{
	char				*file;
	char				*red;
}	t_intra_red;

typedef struct s_cmd
{
	char			*cmd;
	char			*path;
	t_intra_red		*red;
	char			**arg;
	char			*pip;
	pid_t			pid;
	int				tub[2];
	struct s_cmd	*next;
	struct s_cmd	*prev;

}	t_cmd;

typedef struct str_env
{
	char	*key;
	char	*var;
}	t_env;

typedef struct s_term
{
	int		nb_node;
	char	**envp;
	char	*str_cmd;
	t_cmd	*cmd;
	t_env	*env;
	int		dernier_ret;
}	t_term;

extern t_term	g_term;

# define IN 1
# define OUT 0

char		*str(char *arg, int tele);
int			check_duplication_key(char *key, int tele);
int			add_new_env(char **key, char **var);
int			added_arg(char **arg);
void		start_write(void);
int			error_message(char *str);
int			ft_export(char **argv);
t_env		*copy_env(void);
int			sort(t_env **tmp);
int			print_export(void);
char		*ft_strmicrojoin(char **str, char c);
int			init_struct_env(void);
int			change_pwd(char *pwd, char *oldpwd);
int			ft_cd(char **argv);
int			check_building(t_cmd *cmd);
int			option(char *str);
int			ft_echo(char **argv);
int			ft_pwd(t_cmd *cmd);
int			env(t_cmd *cmd);
int			ex_exit(int nbr, int err, char *str);
int			verif_arg(char *str);
long long	ft_atoll(char *str);
void		ft_exit(char **argv);
void		supp_var(char *argv);
int			mess_err(char *str);
int			check(char *str);
int			ft_unset(char **argv);
void		*free_tab(void **a_free);
void		*free_double_tab(void **tab_str, int nb_str);
void		*listing(t_cmd *cmd);
void		*free_node(t_cmd *tmp);
int			free_all(int ret);
int			launch_ex_2(void);
void		handler_ctr_c(int code);
void		handler_ctr_c_2(int code);
void		handler_ctr_backslash(int code);
int			main(int ac, char **av, char **envp);
int			message_error(void);
int			init_parsing(void);
int			check_nb_quotes(char *str);
int			check_bad_redirect(char *str);
int			check_quote(int *gu, char c);
int			check_redirect(int gu, char c);
int			sub_char(char **str, int x);
char		**init_tab_cmd(char *str);
int			create_cmd(char **tab_cmd);
int			check_redirect_type(char *str);
char		*return_ellement(char **str, int *x);
char		*take_redirect(int choose, int *x, char **str);

t_intra_red	*return_red(char **str);

char		*return_cmd(char **str);
char		*return_path(char **str);
char		*return_path_env(char *cmd);
char		*return_pipe(char **cmd);
char		**return_arg(char **tab_cmd, t_cmd *cmd);
void		ft_close_pipe(t_cmd *cmd);
int			launch(void);
int			control_var_env_quotes(t_cmd *cmd);
int			cleaning_quotes(char **str);
int			check_var_env(char **str);
void		connect_pipe(void);
void		close_pipe(void);
void		creat_pipe(void);
int			connect_redirect(void);
int			connect_heredoc(void);
int			ft_sort_2(char **str, char **res, int option, int *tub);
int			ft_strcmp(char *str1, char *str2);
int			ft_sort(char **str, char **res, int option, int *tub);
int			ft_join(char **res, char *str);
int			clearing_quotes(char **str);
int			ft_heredoc(char *deb, char *fin, int option, int *tub);
int			exec_cmd(void);
#endif
