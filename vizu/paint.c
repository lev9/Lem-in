/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	paint(t_xy xy, t_wh wh, t_visu *v, int color)
{
	int		i;
	int		j;

	j = xy.y - 5;
	if (wh.h == 1)
		j = xy.y - 2;
	if (color == 0x000000 && v->stretch == 1)
		j = xy.y;
	while (j < xy.y + wh.h)
	{
		i = xy.x - 5;
		if (wh.h == 1)
			i = xy.x - 2;
		if (color != 0x000001 && v->stretch == 1)
			i = xy.x;
		while (i < xy.x + wh.w)
		{
			if (v->toimage == 0)
				mlx_pixel_put(v->mlx, v->win, i, j, color);
			else
				v->buf[j * v->w + i] = color;
			i++;
		}
		j++;
	}
}

void	draw(int steps, int col, int ant, t_visu *v)
{
	int		b;
	t_xy	xy;
	t_wh	wh;

	v->draw->jumpy = 0;
	v->draw->jumpx = 0;
	b = 0;
	while (b < steps)
	{
		v->draw->jumpy += v->draw->y_step;
		v->draw->jumpx += v->draw->x_step;
		xy.x = v->draw->oldx + round(v->draw->jumpx);
		xy.y = v->draw->oldy + round(v->draw->jumpy);
		wh.w = 1;
		wh.h = 1;
		if (ant != 0)
			paint(xy, wh, v, col);
		else
			paint(xy, wh, v, col);
		b++;
	}
}

int		draw_line(t_xy oldxy, t_xy newxy, int ant, t_visu *v)
{
	t_draw	newdraw;
	int		col;
	int		steps;

	v->draw = &newdraw;
	col = 0x000000;
	v->draw->x_len = newxy.x - oldxy.x;
	v->draw->y_len = newxy.y - oldxy.y;
	if (abs(v->draw->x_len) > abs(v->draw->y_len))
		steps = abs(v->draw->x_len);
	else
		steps = abs(v->draw->y_len);
	v->draw->x_step = v->draw->x_len / (float)steps;
	v->draw->y_step = v->draw->y_len / (float)steps;
	if (ant == 0)
		col = 0x75ff8c;
	v->draw->oldx = oldxy.x;
	v->draw->oldy = oldxy.y;
	draw(steps, col, ant, v);
	return (0);
}
