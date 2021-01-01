/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waylist_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		add_to_end_of_waylist(t_linklist **waylist, t_linklist *link)
{
	t_linklist	*tmp;

	if (*waylist)
	{
		tmp = *waylist;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = link;
		link->next = NULL;
	}
	else
	{
		*waylist = link;
		link->next = NULL;
	}
	return (0);
}

int		add_room_to_waylist(t_lem *lem, t_room *room)
{
	t_linklist	*newlink;

	newlink = new_link(room);
	add_to_end_of_waylist(&lem->waylist, newlink);
	if (room != lem->endroom)
		room->used = 1;
	return (0);
}

int		arrange_ways(t_lem *lem, t_linklist **waylist)
{
	t_linklist	*swap;
	int			check;
	int			i;

	check = 1;
	while (check)
	{
		check = 0;
		i = 0;
		while (i < lem->ways - 1)
		{
			if (waylist[i]->size > waylist[i + 1]->size)
			{
				swap = waylist[i];
				waylist[i] = waylist[i + 1];
				waylist[i + 1] = swap;
				check = 1;
			}
			i++;
		}
	}
	return (0);
}

int		freerooms(t_linklist *linklist)
{
	t_linklist	*link;
	t_linklist	*tmp;

	link = linklist->next->next;
	while (link)
	{
		link->room->used = 0;
		tmp = link->next;
		free(link);
		link = tmp;
	}
	link = linklist;
	tmp = link->next;
	free(tmp);
	free(link);
	return (0);
}
