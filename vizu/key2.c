/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		start(t_visu *v)
{
	int		scalex;
	int		scaley;
	t_xy	xy;
	t_wh	wh;

	scalex = scaledx(v->startroom->x, v);
	scaley = scaledy(v->startroom->y, v);
	mlx_put_image_to_window(v->mlx, v->win, v->screen, 0, 0);
	text(v);
	v->toimage = 0;
	xy.x = scalex + 4 + v->ants;
	xy.y = scaley - 10;
	wh.w = 10 * ft_strlen("  START!");
	wh.h = 15;
	paint(xy, wh, v, 0x241a14);
	print_ants(v, 0xFF00FF, 1);
	mlx_string_put(v->mlx, v->win, scalex + 5 + v->ants, scaley - 18,
	0xFFFFFF, "START!");
	v->started = 1;
	return (0);
}

int		return_ants(t_visu *v)
{
	t_ant	*ant;

	ant = v->antlist;
	while (ant)
	{
		ant->room = v->startroom;
		ant = ant->next;
	}
	return (0);
}

int		finish(t_visu *v)
{
	int		scalex;
	int		scaley;
	t_xy	xy;
	t_wh	wh;

	scalex = scaledx(v->endroom->x, v);
	scaley = scaledy(v->endroom->y, v);
	mlx_put_image_to_window(v->mlx, v->win, v->screen, 0, 0);
	text(v);
	v->toimage = 0;
	xy.x = scalex + 4 + v->ants;
	xy.y = scaley - 10;
	wh.w = 10 * ft_strlen("  FINISH!");
	wh.h = 15;
	paint(xy, wh, v, 0x241a14);
	print_ants(v, 0xFF00FF, 1);
	mlx_string_put(v->mlx, v->win, scalex + 5 + v->ants, scaley - 18, 0xFFFFFF,
	"FINISH!");
	return_ants(v);
	v->startroom->ants = v->ants;
	v->endroom->ants = 0;
	v->started = 0;
	return (0);
}

int		move_ant(int antname, char *roomname, t_visu *v)
{
	t_ant	*ant;
	t_lst	*room;

	room = v->v_rooms;
	while (ft_strcmp(room->name, roomname) != 0)
		room = room->next;
	ant = v->antlist;
	while (ant->name != antname)
		ant = ant->next;
	v->toimage = 0;
	draw_a_link(ant->room, room, 0, v);
	v->toimage = 1;
	ant->room->ants--;
	ant->room = room;
	room->ants++;
	return (0);
}
