/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int			finish_way(int size, t_lem *lem)
{
	lem->waylist->size = size;
	return (0);
}

int			create_way_1(t_linklist *link, t_linklist *c, t_lem *lem, int size)
{
	t_linklist	*t;
	t_linklist	*b;

	add_room_to_waylist(lem, link->room);
	if (link->room == lem->endroom)
		return (finish_way(size, lem));
	t = link->room->linklist;
	while (t->room != lem->endroom && (t->room == lem->startroom ||
	t->room->value == -1))
		t = t->next;
	b = t;
	while (t)
	{
		if (t->room == lem->endroom || (t->room->value != -1 &&
		t->room != c->room && t->room != lem->startroom &&
		t->room->value < b->room->value - 1) || (t->room != c->room &&
		t->room->value <= b->room->value && t->room->value != -1 &&
		t->room->cross < b->room->cross))
			b = t;
		t = t->next;
		if (b->room == lem->endroom)
			break ;
	}
	create_way_1(b, c, lem, size + 1);
	return (0);
}

t_linklist	*choose_first_room_1(t_lem *lem, int cur_shortest)
{
	t_linklist	*link;
	t_linklist	*shortest;

	link = lem->startroom->linklist;
	while (link && (link->room != lem->endroom || link->checked == 1) &&
	(link->room->value < cur_shortest || link->checked == 1))
		link = link->next;
	if (link == NULL)
		return (link);
	shortest = link;
	link = link->next;
	while (link)
	{
		if (link->checked == 0 && link->room->value != -1 && (link->room->value
		< shortest->room->value))
			shortest = link;
		link = link->next;
	}
	shortest->checked = 1;
	return (shortest);
}

int			find_best_ways_1(t_lem *lem)
{
	t_linklist	*shortest;
	int			mem_shortest;

	lem->chosen_ways = (t_linklist**)malloc(500 * sizeof(t_linklist));
	lem->ways = 0;
	shortest = choose_first_room_1(lem, 0);
	while (shortest != NULL)
	{
		lem->endroom->used = 0;
		mem_shortest = shortest->room->value;
		lem->waylist = NULL;
		add_room_to_waylist(lem, lem->startroom);
		create_way_1(shortest, shortest, lem, 1);
		lem->chosen_ways[lem->ways] = lem->waylist;
		lem->ways++;
		reset_values(lem);
		give_values_to_rooms(lem->roomlist, lem);
		shortest = choose_first_room_1(lem, mem_shortest);
	}
	return (0);
}
