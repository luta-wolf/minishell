NAME	=	minishell

SRCS	=	src/main.c	src/buildin/pars_env.c

OBJ		=	$(SRCS:%.c=%.o)

OBJ_B	=	$(SRCS_B:%.c=%.o)

LIB		=	libft/libft.a

INCLUDE	=	include/

HEADER	=	minishell.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

# FLAG_SH	=	-L /Users/$(USER)/.brew/opt/readline/lib/ -lreadline
# READLINE=   -L$(HOME)/.brew/opt/readline/lib -I .brew/opt/readline/include
READLINE=	-l readline

RM		= rm -rf

#---------------------------------------------------------------------------------
RED		=	\033[1;31m
BLUE	=	\033[1;34m
YELLOW	=	\033[1;33m
WHITE	=	\033[1;32m
PUPURE	=	\033[1;35m
GRY		=	\033[1;30m
TURQUOISE =	\033[36;1m
END		=	\033[0m
#---------------------------------------------------------------------------------
.PHONY:		all	clean	fclean	re	bonus	libft

all:		libft $(NAME)

libft:
			@$(MAKE) -C libft/

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(READLINE) $(OBJ) $(LIB) -o $(NAME)
			@echo "$(TURQUOISE)\n\t Complited $(NAME) \n$(END)"

%.o:		%.c $(INCLUDE)$(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@ -I $(INCLUDE)

bonus:		libft $(OBJ_B)
			$(CC) $(FLAGS) $(OBJ_B) $(LIB) -o $(NAME_B)
			@echo "$(TURQUOISE)\n\tComplited $(NAME_B) \n$(END)"

clean:
			@$(RM) $(OBJ) $(OBJ_B)
			@$(MAKE) -C libft/ clean
			@echo "$(BLUE)\n\tCleaning succeed\n$(END)"

fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(RM) $(NAME) $(NAME_B)
			@echo "$(BLUE)\tAll files were deleted\n$(END)"

re:			fclean all
			@echo "$(BLUE)\tRemake done\n$(END)"


