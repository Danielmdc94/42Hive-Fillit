# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 13:41:26 by dpalacio          #+#    #+#              #
#    Updated: 2022/02/17 16:40:16 by dpalacio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./libft/

LIB = -L ./libft -lft

SRC = main.c error.c read_file.c convert_file.c

OBJ = main.o error.o read_file.o convert_file.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(INCLUDES) $(SRC) $(LIB) -o $(NAME)
lib:
	make -C libft/ re

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
