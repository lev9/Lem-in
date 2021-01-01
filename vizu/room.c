/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		draw_room(t_lst *room, t_visu *v)
{
	int		scalex;
	int		scaley;
	t_xy	xy;
	t_wh	wh;

	scalex = scaledx(room->x, v);
	scaley = scaledy(room->y, v);
	xy.x = scalex + 4;
	xy.y = scaley + 10;
	wh.w = 10 * ft_strlen(room->name);
	wh.h = 10;
	if (room == v->startroom || room == v->endroom)
		paint(xy, wh, v, 0x215c73);
	else
		paint(xy, wh, v, 0x000000);
	return (0);
}

void	lst_add(t_lst **head, t_lst *new)
{
	t_lst	*temp;

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

t_lst	*lst_new(char **info, t_visu *v)
{
	t_lst	*new;

	new = (t_lst*)malloc(sizeof(t_lst));
	{
		if (v->stretch == 1)
		{
			new->x = ft_atoi(info[1]) / 10 * 10;
			new->y = ft_atoi(info[2]) * 10 % v->ymax;
		}
		else
		{
			new->x = ft_atoi(info[1]);
			new->y = ft_atoi(info[2]);
		}
		if (v->zerox == 1)
			new->x = v->rooms;
		if (v->zeroy == 1)
			new->y = v->rooms;
		new->name = ft_strdup(info[0]);
		new->next = NULL;
		new->linklist = NULL;
		new->ants = 0;
		return (new);
	}
}

int		add_v_room(char *str, t_visu *v)
{
	char	**info;
	t_lst	*newroom;
	int		x;
	int		y;

	info = ft_strsplit(str, ' ');
	newroom = lst_new(info, v);
	lst_add(&v->v_rooms, newroom);
	if (v->start == 0)
	{
		v->start = 1;
		v->startroom = newroom;
	}
	if (v->end == 0)
	{
		v->end = 1;
		v->endroom = newroom;
	}
	x = ft_atoi(info[1]);
	y = ft_atoi(info[2]);
	free_info(info);
	if (v->stretch == 0)
		draw_room(newroom, v);
	return (0);
}
