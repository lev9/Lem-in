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

SRC = main.c default_and_error.c map.c line_handler.c room_creator.c \
	link_collector.c option_1.c option_2.c option_3.c option_4.c \
	option_5.c waylist_tools.c room_tools.c compare.c ant_handler.c \
	printer.c

OBJ = main.o default_and_error.o map.o line_handler.o room_creator.o \
	link_collector.o option_1.o option_2.o option_3.o option_4.o \
	option_5.o waylist_tools.o room_tools.o compare.o ant_handler.o \
	printer.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

lem-in: $(OBJ)
	@make -C libft
	@clang  $(FLAGS) -g -o $(NAME) $(OBJ) -L libft/ -lft
	@printf "Done compiling lem-in.\nRun:\n\x1b[31m./lem-in < [antfarm]\n"

$(OBJ): %.o: %.c lem.h
	@clang $(FLAGS) -c $<
	@printf "\r                                  \r$<"

clean:
	@/bin/rm -f $(OBJ)
	@make clean -C libft/

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f lem-in

re: fclean all
