/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	get_images(t_visu *v)
{
	int		bits;
	int		pixels;
	int		endian;

	v->screen = mlx_new_image(v->mlx, v->w, v->h);
	v->buf = (int*)mlx_get_data_addr(v->screen, &bits, &pixels, &endian);
}

int		paint_window(t_visu *v)
{
	int		x;
	int		y;

	y = 0;
	while (y < v->h)
	{
		x = 0;
		while (x < v->w)
		{
			v->buf[y * v->w + x] = 0xfffeadf;
			x++;
		}
		y++;
	}
	return (0);
}

int		panel2(t_visu *v)
{
	t_xy		xy;
	t_wh		wh;

	wh.h = 10;
	xy.x = 204;
	xy.y = v->h - 70;
	wh.w = 80 + 10 * ft_strlen(v->startroom->name);
	paint(xy, wh, v, 0x000001);
	xy.y = v->h - 50;
	wh.w = 80 + 10 * ft_strlen(v->endroom->name);
	paint(xy, wh, v, 0x000001);
	xy.y = v->h - 30;
	wh.w = 120;
	paint(xy, wh, v, 0x000001);
	xy.x = v->w / 2 - 100;
	xy.y = 16;
	wh.w = 140;
	paint(xy, wh, v, 0x000001);
	return (0);
}

int		panel(t_visu *v)
{
	t_xy	xy;
	t_wh	wh;
	char	*str;

	wh.h = 10;
	xy.x = 24;
	xy.y = v->h - 70;
	str = ft_itoa(v->ants);
	wh.w = 70 + 10 * ft_strlen(str);
	free(str);
	paint(xy, wh, v, 0x000001);
	xy.y = v->h - 50;
	str = ft_itoa(v->rooms);
	wh.w = 70 + 10 * ft_strlen(str);
	free(str);
	paint(xy, wh, v, 0x000001);
	xy.y = v->h - 100;
	wh.w = 410;
	if (v->stretch == 1)
		paint(xy, wh, v, 0x000001);
	panel2(v);
	return (0);
}
