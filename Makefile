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

NAME = lem-in

SRC = main.c default_and_error.c map.c map_reader.c room_creator.c \
	link_collector.c option_1.c option_2.c option_3.c option_4.c \
	option_5.c waylist_tools.c room_tools.c compare.c ant_handler.c \
	printer.c

OBJ = $(subst .c,.o,$(SRC))

REST = -L./libft -lft

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(FLAGS) -I libft/ -c $(SRC)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(REST)
	@/bin/rm -f $(OBJ)
	
clean:
	@/bin/rm -f $(OBJ)
	@make clean -C libft/

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)

re: fclean all
