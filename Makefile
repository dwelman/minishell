# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/27 08:37:23 by daviwel           #+#    #+#              #
#    Updated: 2016/06/28 08:10:23 by daviwel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c loop.c get_commands.c execute.c echo.c show_env.c env_funcs.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Werror -Wextra

ATTACH = -L libft/ -lft

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft/
	clang $(CFLAG) -c $(SRC)
	clang $(CFLAG) -o $(NAME) $(OBJ) $(ATTACH)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norme:
	norminette minishell.h $(SRC)

author:
	/bin/rm -f author
	whoami > author
