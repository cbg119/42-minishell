# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/26 17:43:18 by cbagdon           #+#    #+#              #
#    Updated: 2019/03/27 22:46:03 by cbagdon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c \
		prompt.c \
		env.c

INCLUDES = includes/

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME):
	make -C libft
	@gcc -g $(FLAGS) -c $(addprefix src/,$(SRC)) -I $(INCLUDES)
	@gcc -g $(Flags) -o $(NAME) $(OBJECTS) -L ./libft/ -lft

clean:
	make -C libft clean
	@rm -rf $(OBJECTS)

fclean: clean
	make -C libft fclean
	@rm -rf $(NAME)

re: fclean all
