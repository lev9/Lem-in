/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include "libft/libft.h"

# define G "\x1B[32m"
# define R "\x1b[31m"
# define N "\033[0;0m"
# define P "\033[0;35m"
# define ANTCOUNT 0

typedef struct s_linklist	t_linklist;
typedef struct s_room		t_room;
typedef struct s_ant		t_ant;
typedef struct s_mapline	t_mapline;
typedef struct s_lem		t_lem;

struct		s_linklist
{
	t_room		*room;
	t_linklist	*next;
	int			size;
	int			checked;
	int			signed_ants;
};

struct		s_room
{
	t_linklist	*linklist;
	t_room		*next;
	char		*name;
	int			value;
	int			ants;
	int			cross;
	int			used;
	int			x;
	int			y;
};

struct		s_ant
{
	t_linklist	*link;
	t_ant		*next;
	int			name;
};

struct		s_mapline
{
	char		*str;
	t_mapline	*next;
	t_mapline	*prev;
	t_mapline	*last;
};

struct		s_lem
{
	int			ants;
	int			start;
	int			end;
	int			room_part;
	int			link_part;
	int			rooms;
	int			links;
	int			ways;
	int			fast;
	int			opt_1_ways;
	int			opt_2_ways;
	int			opt_3_ways;
	int			opt_4_ways;
	int			len1;
	int			len2;
	int			len3;
	int			len4;
	int			len5;
	int			finalcount;
	int			required;
	char		*req;
	t_mapline	*maplinelist;
	t_room		*roomlist;
	t_room		*startroom;
	t_room		*endroom;
	t_ant		*antlist;
	t_mapline	*firstline;
	t_linklist	*waylist;
	t_linklist	**chosen_ways;
	t_linklist	**chosen_ways2;
	t_linklist	**chosen_ways3;
	t_linklist	**chosen_ways4;
	t_linklist	**chosen_ways5;
	t_linklist	**final_ways;
};

/*
**	main.c
*/

void		get_best_option(t_lem *lem);
void		find_path(t_lem *lem);
int			use_one_option(t_lem *lem);
int			one_step_check(t_lem *lem);
int			main(void);

/*
**	default_and_error.c
*/

int			set_default_values(t_lem *lem);
int			error_m2(int why, t_lem *lem);
int			error_m(int why, t_lem *lem);
int			final_error(t_lem *lem);

/*
**	map.c
*/

int			print_map(t_mapline *firstline);
int			handle_line(char *str, t_lem *lem);
int			read_map(t_lem *lem);

/*
**	line_handler.c
*/

int			is_link_line(char *str);
int			is_room_line(char *str);
int			check_comments(char *str, t_lem *lem);
int			check_ant_line(char *str, t_lem *lem);
int			check_if_time_for_link_line(char *str, t_lem *lem);

/*
**	room_creator.c
*/

int			add_to_roomlist(t_room **roomlist, t_room *room, t_lem *lem);
t_room		*room_new(char **info);
int			create_room(char *str, t_lem *lem);

/*
**	link_collector.c
*/

int			add_to_rooms_links(t_linklist **linklist, t_linklist *link);
t_linklist	*new_link(t_room *tmp);
int			free_info(char **info);
int			create_link(char *str, t_lem *lem);

/*
**	option_1.c
*/

int			finish_way(int size, t_lem *lem);
int			create_way_1(t_linklist *link, t_linklist *c, t_lem *lem, int size);
t_linklist	*choose_first_room_1(t_lem *lem, int cur_shortest);
int			find_best_ways_1(t_lem *lem);

/*
**	option_2.c
*/

int			create_way_2(t_linklist *link, t_linklist *c, t_lem *lem, int size);
t_linklist	*choose_first_room_2(t_lem *lem, int cur_shortest);
int			handle_way_2(t_linklist *shortest, t_lem *lem);
int			find_best_ways_2(t_lem *lem);

/*
**      option_3.c
*/

int			create_way_3(t_linklist *link, t_linklist *c, t_lem *lem, int size);
t_linklist	*choose_first_room_3(t_lem *lem, int cur_shortest);
int			find_best_ways_3(t_lem *lem);

/*
**	option_4.c
*/

int			create_way_4(t_linklist *link, t_linklist *c, t_lem *lem, int size);
t_linklist	*choose_first_room_4(t_lem *lem, int cur_shortest);
int			find_best_ways_4(t_lem *lem);

/*
**      option_5.c
*/

int			create_way_5(t_linklist *link, t_linklist *c, t_lem *lem, int size);
t_linklist	*choose_first_room_5(t_lem *lem, int cur_shortest);
t_linklist	*choose_first_room_5a(t_lem *lem, int cur_shortest);
int			find_best_ways_5(t_lem *lem);

/*
**	waylist_tools.c
*/

int			add_to_end_of_waylist(t_linklist **waylist, t_linklist *link);
int			add_room_to_waylist(t_lem *lem, t_room *room);
int			arrange_ways(t_lem *lem, t_linklist **waylist);
int			freerooms(t_linklist *linklist);

/*
**	room_tools.c
*/

int			crossroad_check(t_room *room);
int			value_check(int rooms_left, int value, t_room *roomlist);
int			give_values_to_rooms(t_room *roomlist, t_lem *lem);
int			reset_values(t_lem *lem);
int			mark_all_rooms_unused(t_lem *lem);

/*
**	compare.c
*/

int			test_move_ant(t_ant *ant, t_lem *lem);
int			test_send_ants(t_lem *lem);
int			test_sign_ways_to_ants(t_lem *lem, t_linklist **option);
int			test_final_steps(t_lem *lem, t_linklist **option);

/*
**	ant_handler.c
*/

int			move_ant(t_ant *ant, t_lem *lem);
void		send_ants(t_lem *lem);
int			sign_ways_to_ants(t_lem *lem);
int			create_ants(int ants, t_lem *lem);

/*
**	printer.c
*/

void		print_option_results(int count, t_lem *lem);
void		print_results(int count, t_lem *lem);
void		print_ants(int i, int count, t_lem *lem);

#endif
