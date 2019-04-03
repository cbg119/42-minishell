# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/26 17:43:18 by cbagdon           #+#    #+#              #
#    Updated: 2019/04/02 17:06:42 by cbagdon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c \
		prompt.c \
		env.c \
		exec.c \
		parse.c \
		cmd.c

BUILTIN = cd.c \
		env_b.c \
		setenv.c \
		unsetenv.c \
		echo.c

INCLUDES = includes/

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(patsubst %.c,%.o,$(SRC))
OBJECTS += $(patsubst %.c,%.o,$(BUILTIN))

all: $(NAME)

$(NAME):
	make -C libft
	@gcc $(FLAGS) -I $(INCLUDES) -c $(addprefix src/,$(SRC)) $(addprefix builtin/,$(BUILTIN))
	@gcc $(Flags) -o $(NAME) $(OBJECTS) -L ./libft/ -lft

clean:
	make -C libft clean
	@rm -rf $(OBJECTS)

fclean: clean
	make -C libft fclean
	@rm -rf $(NAME)

re: fclean all
