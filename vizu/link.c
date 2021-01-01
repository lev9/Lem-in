/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			draw_a_link(t_lst *room, t_lst *room2, int ant, t_visu *v)
{
	t_xy	oldxy;
	t_xy	newxy;

	oldxy.x = scaledx(room->x, v);
	oldxy.y = scaledy(room->y, v);
	newxy.x = scaledx(room2->x, v);
	newxy.y = scaledy(room2->y, v);
	draw_line(oldxy, newxy, ant, v);
	return (0);
}

int			link_add(t_linklist **linklist, t_linklist *link)
{
	t_linklist	*tmp;

	if (*linklist)
	{
		tmp = *linklist;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = link;
	}
	else
		*linklist = link;
	return (0);
}

t_linklist	*new_link(t_lst *tmp)
{
	t_linklist	*new;

	new = (t_linklist*)malloc(sizeof(t_linklist));
	if (new)
	{
		new->room = tmp;
		new->next = NULL;
		return (new);
	}
	return (0);
}

int			add_v_link(char *str, t_visu *v)
{
	char		**info;
	t_lst		*tmp;
	t_lst		*tmp2;
	t_linklist	*newlink;
	t_linklist	*newlink2;

	info = ft_strsplit(str, '-');
	tmp = v->v_rooms;
	while (tmp && ft_strcmp(tmp->name, info[0]) != 0)
		tmp = tmp->next;
	tmp2 = v->v_rooms;
	while (tmp && ft_strcmp(tmp2->name, info[1]) != 0)
		tmp2 = tmp2->next;
	newlink = new_link(tmp2);
	link_add(&tmp->linklist, newlink);
	newlink2 = new_link(tmp);
	link_add(&tmp2->linklist, newlink2);
	v->links++;
	free_info(info);
	draw_a_link(tmp, tmp2, 1, v);
	return (0);
}
