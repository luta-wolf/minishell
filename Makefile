# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 15:14:49 by mbonnet           #+#    #+#              #
#    Updated: 2022/06/07 20:13:28 by jleslee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	minishell 

SRCS			=	main.c\
					hendler/hendler.c\
					building/unset.c\
					building/cd.c\
					building/exit.c\
					building/echo_pwd_env.c\
					building/export/export.c\
					building/export/export_processing.c\
					building/export/add_env_export.c\
					building/export/print_export.c\
					building/check_building.c\
					free/free.c\
					init_struct_env.c\
					parsing/init_parsing.c\
					parsing/check_str_cmd.c\
					parsing/utile.c\
					parsing/init_tab_cmd/init_tab_cmd.c\
					parsing/init_struct/init_struct.c\
					parsing/init_struct/utile.c\
					parsing/init_struct/control_red.c\
					parsing/init_struct/control_cmd.c\
					parsing/init_struct/control_arg.c\
					ex_cmd/launch_ex.c\
					ex_cmd/control_var_env.c\
					ex_cmd/control_var_env_utile.c\
					ex_cmd/control_pipe.c\
					ex_cmd/control_redirect.c\
					ex_cmd/control_heredoc.c\
					ex_cmd/control_heredoc_2.c\
					ex_cmd/control_ex.c\


OBJS			=	${addprefix srcs/,${SRCS:.c=.o}}

HEAD			=	-I includes -I libs/includes

CC				=	clang

CFLAGS			=	-Wall -Werror -Wextra 

LIBS_DIR		=	libs

LDFLAGS			=	-L ${LIBS_DIR} -lft 

.c.o			:
					${CC} ${CFLAGS} ${HEAD}  -c $< -o ${<:.c=.o} 

$(NAME)			:	${OBJS} ${LIBS_DIR}
					make -C ${LIBS_DIR}
					${CC} ${CFLAGS} -lreadline ${OBJS} ${LDFLAGS} -o ${NAME} -lncurses


all				:	${NAME}

clean			:
					make clean -C ${LIBS_DIR}
					rm -rf ${OBJS}

fclean			:	clean
					make fclean -C ${LIBS_DIR}
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
