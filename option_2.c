/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int			create_way_2(t_linklist *link, t_linklist *c, t_lem *lem, int size)
{
	t_linklist	*t;
	t_linklist	*b;

	add_room_to_waylist(lem, link->room);
	if (link->room == lem->endroom)
		return (finish_way(size, lem));
	t = link->room->linklist;
	while (t && t->room != lem->endroom && (t->room->used == 1 ||
	t->room->value > c->room->value || t->room->value == -1))
		t = t->next;
	b = t;
	while (t)
	{
		if (t->room == lem->endroom || (t->room->used == 0 &&
		t->room->value <= c->room->value && t->room->value <
		b->room->value - 1 && t->room->value != -1) ||
		(t->room->used == 0 && t->room->value <= b->room->value
		&& t->room->value != -1 && t->room->cross < b->room->cross))
			b = t;
		t = t->next;
		if (b->room == lem->endroom)
			break ;
	}
	create_way_2(b, c, lem, size + 1);
	return (0);
}

t_linklist	*choose_first_room_2(t_lem *lem, int cur_shortest)
{
	t_linklist	*link;
	t_linklist	*shortest;

	link = lem->startroom->linklist;
	while (link && (!(link->room == lem->endroom && link->checked == 0)) &&
	(link->room->cross < cur_shortest || link->room->used == 1 ||
	link->room->value == -1))
		link = link->next;
	if (link == NULL)
		return (link);
	shortest = link;
	link = link->next;
	while (link)
	{
		if (link->room == lem->endroom || (link->room->used == 0 &&
		link->room->value != -1 && link->room->cross <= shortest->room->cross))
			shortest = link;
		link = link->next;
	}
	shortest->room->used = 1;
	shortest->checked = 1;
	return (shortest);
}

int			handle_way_2(t_linklist *shortest, t_lem *lem)
{
	if (lem->waylist->size < 70)
	{
		lem->chosen_ways2[lem->ways] = lem->waylist;
		lem->ways++;
	}
	else
	{
		freerooms(lem->waylist);
		shortest->checked = 0;
	}
	return (0);
}

int			find_best_ways_2(t_lem *lem)
{
	t_linklist	*shortest;
	int			mem_shortest;

	lem->chosen_ways2 = (t_linklist**)malloc(500 * sizeof(t_linklist));
	lem->ways = 0;
	shortest = choose_first_room_2(lem, 0);
	while (shortest != NULL)
	{
		lem->endroom->used = 0;
		mem_shortest = shortest->room->cross;
		lem->waylist = NULL;
		add_room_to_waylist(lem, lem->startroom);
		create_way_2(shortest, shortest, lem, 1);
		handle_way_2(shortest, lem);
		reset_values(lem);
		give_values_to_rooms(lem->roomlist, lem);
		shortest = choose_first_room_2(lem, mem_shortest);
	}
	arrange_ways(lem, lem->chosen_ways2);
	return (0);
}
