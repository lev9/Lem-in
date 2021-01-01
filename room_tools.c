/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		crossroad_check(t_room *room)
{
	t_linklist	*link;
	int			count;

	count = 0;
	link = room->linklist;
	while (link)
	{
		link = link->next;
		count++;
		if (count > 2)
			return (1);
	}
	return (0);
}

int		value_check(int rooms_left, int value, t_room *roomlist)
{
	t_room		*tmp;
	t_linklist	*link;

	tmp = roomlist;
	while (tmp)
	{
		if (tmp->value == -1 && tmp->used == 0)
		{
			link = tmp->linklist;
			while (link)
			{
				if (link->room->value == value)
				{
					tmp->value = value + 1;
					tmp->cross = link->room->cross + crossroad_check(tmp);
					rooms_left = 1;
					break ;
				}
				link = link->next;
			}
		}
		tmp = tmp->next;
	}
	return (rooms_left);
}

int		give_values_to_rooms(t_room *roomlist, t_lem *lem)
{
	int		rooms_left;
	int		value;

	lem->startroom->value = 10000;
	lem->endroom->value = 0;
	rooms_left = 1;
	value = 0;
	while (rooms_left)
	{
		rooms_left = 0;
		rooms_left = value_check(rooms_left, value, roomlist);
		value++;
	}
	return (0);
}

int		reset_values(t_lem *lem)
{
	t_room	*room;

	room = lem->roomlist;
	while (room)
	{
		room->value = -1;
		room = room->next;
	}
	return (0);
}

int		mark_all_rooms_unused(t_lem *lem)
{
	t_room		*room;
	t_linklist	*link;

	room = lem->roomlist;
	while (room)
	{
		room->used = 0;
		room->value = -1;
		room->cross = 0;
		link = room->linklist;
		while (link)
		{
			link->checked = 0;
			link = link->next;
		}
		room = room->next;
	}
	return (0);
}
