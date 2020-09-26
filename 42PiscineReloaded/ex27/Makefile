# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbui <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 09:55:49 by mbui              #+#    #+#              #
#    Updated: 2019/04/03 11:19:40 by mbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SRC = display_file.c
OUT = display_file.o
FLGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLGS) $(SRC)
	mv a.out $(NAME)

clean:
	rm -f $(OUT)

fclean: clean
	rm -f $(NAME)

re: fclean all
