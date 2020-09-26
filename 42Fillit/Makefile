# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbui <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/06 09:43:02 by mbui              #+#    #+#              #
#    Updated: 2019/10/18 09:37:51 by mbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
SRC = check_input.c store.c solve.c main.c 
LIB = libft/libft.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): getlibft
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

getlibft:
	make -C libft

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: clean fclean all re
