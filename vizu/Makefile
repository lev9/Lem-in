# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 08:30:56 by laskolin          #+#    #+#              #
#    Updated: 2020/07/16 16:47:59 by laskolin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visu

LIBMLX = ./lib/libmlx

LIBFT = ./lib/libft

SRC = visu.c help.c read.c room.c link.c key1.c key2.c ant.c move.c window.c \
	text.c paint.c

OBJ = $(subst .c,.o,$(SRC))

MLXFLAGS = -I$(LIBMLX) -L$(LIBMLX) -lmlx -framework OpenGL -framework Appkit

LIBFTFLAGS = -L$(LIBFT) -lft

REST =  -I /usr/local/include -L /usr/local/lib/ -lmlx -framework \
	OpenGL -framework Appkit libft/libft.a


FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)/
	@make -C $(LIBMLX)/
	@gcc $(FLAGS) -I libft/ -c $(SRC)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFTFLAGS) $(MLXFLAGS)
	@/bin/rm -f $(OBJ)

clean:
	@/bin/rm -f $(OBJ)
	@make clean -C $(LIBFT)/

fclean: clean
	@make fclean -C $(LIBFT)/
	@/bin/rm -f $(NAME)

re: fclean all
