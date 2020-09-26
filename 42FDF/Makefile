# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 12:55:24 by mbui              #+#    #+#              #
#    Updated: 2020/01/20 09:15:13 by mbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Werror -Wextra
DIR = srcs/
SRC = main.c all_init.c store.c draw.c draw_start.c projection.c colors.c \
	  deal_events.c deal_mouse.c deal_key.c deal_event_utils.c \
	  deal_event_utils2.c
OBJ = $(SRC:.c=.o)
LIB = libft/libft.a minilibx_macos/libmlx.a

all: $(NAME)

$(NAME): makeo
	gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME) -lm -framework OpenGL -framework AppKit

makeo: lib
	gcc $(FLAGS) -c $(addprefix $(DIR), $(SRC))

lib:
	make -C libft
	make -C minilibx_macos

clean:
	rm -f $(OBJ)
	make clean -C libft
	make clean -C minilibx_macos

fclean: clean
	rm -f $(NAME) $(LIB)

re: fclean all

.PHONY: makeo lib clean fclean all re
