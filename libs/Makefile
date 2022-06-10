# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 15:47:27 by mbonnet           #+#    #+#              #
#    Updated: 2022/06/02 21:04:02 by jleslee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_convertisseur/ft_itoa.c\
		ft_convertisseur/ft_split.c\
		ft_str/ft_isalpha.c\
		ft_str/ft_isdigit.c\
		ft_str/ft_memcpy.c\
		ft_str/ft_strdup.c\
		ft_str/ft_strjoin.c\
		ft_str/ft_strlcpy.c\
		ft_str/ft_strlen.c\
		ft_str/ft_strncmp.c\
		ft_str/ft_strdoublejoin.c\
		additional_functions/ft_whitespace.c\

OBJS			=	${SRCS:.c=.o}

HEAD			=	includes

CC				=	clang

CFLAGS			=	-Wall -Werror -Wextra -g

NAME			=	libft.a

.c.o			:
					${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}			:	${OBJS}
					ar -rcs ${NAME} ${OBJS}

all				:	${NAME}

clean			:
					rm -rf ${OBJS}

fclean			:	clean
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
