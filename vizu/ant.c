/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		print_ants2(t_visu *v)
{
	t_xy	xy;
	t_wh	wh;
	t_lst	*room;

	room = v->v_rooms;
	while (v->stretch == 0 && room)
	{
		xy.x = scaledx(room->x, v);
		xy.y = scaledy(room->y, v);
		wh.w = room->ants;
		wh.h = room->ants;
		if (room->ants > 0)
			paint(xy, wh, v, 0xFF00FF);
		room = room->next;
	}
	return (0);
}

int		print_ants(t_visu *v, int color, int n)
{
	t_xy	xy;
	t_wh	wh;

	n = 1;
	v->toimage = 0;
	if (color == (int)0xe6ff00e6)
	{
		xy.x = scaledx(v->startroom->x, v);
		xy.y = scaledy(v->startroom->y, v);
		wh.w = v->startroom->ants;
		wh.h = v->startroom->ants;
		paint(xy, wh, v, 0x4dff00e6);
		xy.x = scaledx(v->endroom->x, v);
		xy.y = scaledy(v->endroom->y, v);
		wh.w = v->endroom->ants;
		wh.h = v->endroom->ants;
		paint(xy, wh, v, 0x4d001eff);
	}
	else
		print_ants2(v);
	v->toimage = 1;
	return (0);
}

void	ant_add(t_ant **head, t_ant *new)
{
	t_ant	*temp;

	if (*head)
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	else
		*head = new;
}

t_ant	*ant_new(int i, t_visu *v)
{
	t_ant	*new;

	new = (t_ant*)malloc(sizeof(t_ant));
	if (new)
	{
		new->name = i;
		new->room = v->startroom;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

int		create_ants(int size, t_visu *v)
{
	int		i;
	t_ant	*newant;

	i = 1;
	while (i <= size)
	{
		newant = ant_new(i, v);
		ant_add(&v->antlist, newant);
		i++;
	}
	v->startroom->ants = size;
	return (0);
}
