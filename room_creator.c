/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		add_to_roomlist(t_room **roomlist, t_room *room, t_lem *lem)
{
	t_room	*tmp;

	if (*roomlist)
	{
		tmp = *roomlist;
		while (tmp->next != NULL)
		{
			if (ft_strcmp(tmp->name, room->name) == 0 ||
			(tmp->x == room->x && tmp->y == room->y))
				return (error_m(10, lem));
			tmp = tmp->next;
		}
		if (ft_strcmp(tmp->name, room->name) == 0 ||
		(tmp->x == room->x && tmp->y == room->y))
			return (error_m(10, lem));
		tmp->next = room;
	}
	else
		*roomlist = room;
	return (0);
}

t_room	*room_new(char **info)
{
	t_room	*new;

	new = (t_room*)malloc(sizeof(t_room));
	if (new)
	{
		new->value = -1;
		new->name = ft_strdup(info[0]);
		new->next = NULL;
		new->linklist = NULL;
		new->ants = 0;
		new->cross = 0;
		new->used = 0;
		new->x = ft_atoi(info[1]);
		new->y = ft_atoi(info[2]);
		return (new);
	}
	return (NULL);
}

int		create_room(char *str, t_lem *lem)
{
	char	**info;
	t_room	*newroom;

	info = ft_strsplit(str, ' ');
	if (info[0] == NULL || info[1] == NULL || info[2] == NULL)
		return (error_m(11, lem));
	if (ft_strrchr(info[0], '-'))
		return (error_m(11, lem));
	newroom = room_new(info);
	add_to_roomlist(&lem->roomlist, newroom, lem);
	if (lem->start == 0)
	{
		lem->start = 1;
		lem->startroom = newroom;
	}
	if (lem->end == 0)
	{
		lem->end = 1;
		lem->endroom = newroom;
	}
	free_info(info);
	lem->rooms++;
	return (0);
}
