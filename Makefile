# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 13:41:26 by dpalacio          #+#    #+#              #
#    Updated: 2022/03/04 11:32:39 by dpalacio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./libft/

LIB = -L ./libft -lft

SRC = main.c error.c read_file.c str_to_int.c build_struct.c map.c

OBJ = main.o error.o read_file.o str_to_int.o build_struct.o map.o

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
