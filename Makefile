# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 13:41:26 by dpalacio          #+#    #+#              #
#    Updated: 2022/01/21 15:30:30 by dpalacio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

INCLUDES = libft/includes

SRC = main.c

OBJ = main.o

all: $(NAME)

$(NAME):
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -o $(NAME) main.o -I libft/includes -L libft/ -lft

lib:
	make -C libft/ fclean && make -C libft/

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
