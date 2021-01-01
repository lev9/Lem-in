/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

/*
**	1.while reading the map to maplinelist, check that it is valid
**	and collect a list of rooms. Each room has it's own list of
**	links. Each link has one room (from the roomlist).
**
** 	2.create given amount of t_ant ants.
**
**	3.on larger maps, use 5 search options to search ways, choose the
**	best result. With smaller, just one. Give values to rooms so that
**	endrooms links are 1, their links 2 and so on. Also give a cross value
**	based on how many times the way from room to end will cross another
**	way. Use these values in search for good ways, and save ways
**	to waylists.
**
**	4.if found a way, print out valid map.
**
**	5.sign one of the chosen ways to each ant.
**
** 	6.until all ants are in endroom, move ants forward on their
**	signed ways & print moves.
*/

void	get_best_option(t_lem *lem)
{
	if (lem->len5 <= lem->len1 && lem->len5 <= lem->len2 &&
	lem->len5 <= lem->len3 && lem->len5 <= lem->len4)
		lem->final_ways = lem->chosen_ways5;
	else if (lem->len4 <= lem->len1 && lem->len4 <= lem->len2 &&
	lem->len4 <= lem->len3 && lem->len4 <= lem->len5)
	{
		lem->final_ways = lem->chosen_ways4;
		lem->ways = lem->opt_4_ways;
	}
	else if (lem->len3 <= lem->len1 && lem->len3 <= lem->len2 &&
	lem->len3 <= lem->len4 && lem->len3 <= lem->len5)
	{
		lem->final_ways = lem->chosen_ways3;
		lem->ways = lem->opt_3_ways;
	}
	else if (lem->len2 <= lem->len1)
	{
		lem->final_ways = lem->chosen_ways2;
		lem->ways = lem->opt_2_ways;
	}
	else
	{
		lem->final_ways = lem->chosen_ways;
		lem->ways = lem->opt_1_ways;
	}
}

void	find_path(t_lem *lem)
{
	give_values_to_rooms(lem->roomlist, lem);
	find_best_ways_1(lem);
	lem->len1 = test_final_steps(lem, lem->chosen_ways);
	lem->opt_1_ways = lem->ways;
	mark_all_rooms_unused(lem);
	give_values_to_rooms(lem->roomlist, lem);
	find_best_ways_2(lem);
	lem->len2 = test_final_steps(lem, lem->chosen_ways2);
	lem->opt_2_ways = lem->ways;
	mark_all_rooms_unused(lem);
	give_values_to_rooms(lem->roomlist, lem);
	find_best_ways_3(lem);
	lem->len3 = test_final_steps(lem, lem->chosen_ways3);
	lem->opt_3_ways = lem->ways;
	mark_all_rooms_unused(lem);
	give_values_to_rooms(lem->roomlist, lem);
	find_best_ways_4(lem);
	lem->len4 = test_final_steps(lem, lem->chosen_ways4);
	lem->opt_4_ways = lem->ways;
	mark_all_rooms_unused(lem);
	give_values_to_rooms(lem->roomlist, lem);
	find_best_ways_5(lem);
	lem->len5 = test_final_steps(lem, lem->chosen_ways5);
	get_best_option(lem);
}

int		use_one_option(t_lem *lem)
{
	give_values_to_rooms(lem->roomlist, lem);
	find_best_ways_1(lem);
	test_final_steps(lem, lem->chosen_ways);
	lem->final_ways = lem->chosen_ways;
	return (0);
}

int		one_step_check(t_lem *lem)
{
	t_linklist	*link;

	link = lem->startroom->linklist;
	while (link)
	{
		if (link->room == lem->endroom)
		{
			lem->waylist = NULL;
			add_room_to_waylist(lem, lem->startroom);
			add_room_to_waylist(lem, lem->endroom);
			lem->final_ways = (t_linklist**)malloc(sizeof(t_linklist));
			lem->final_ways[0] = lem->waylist;
			lem->ways = 1;
			lem->fast = 1;
			return (1);
		}
		link = link->next;
	}
	return (0);
}

int		main(void)
{
	t_lem newlem;
	t_lem *lem;

	lem = &newlem;
	set_default_values(lem);
	read_map(lem);
	create_ants(lem->ants, lem);
	if (one_step_check(lem) == 0)
	{
		if (lem->links < 1000)
			use_one_option(lem);
		else
			find_path(lem);
		if (lem->ways == 0)
			return (error_m(12, lem));
	}
	print_map(lem->firstline);
	ft_putchar_fd('\n', 1);
	sign_ways_to_ants(lem);
	send_ants(lem);
	if (ANTCOUNT == 1)
		print_ants(3, lem->finalcount, lem);
	final_error(lem);
	return (0);
}
