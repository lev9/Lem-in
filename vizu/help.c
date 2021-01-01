/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		scaledx(int x, t_visu *v)
{
	int		scalex;

	if (v->xmax > 0)
		scalex = (x - v->xmin) * ((double)(v->w - 200) /
		(double)(v->xmax - v->xmin)) + 50;
	else
		scalex = x * ((v->w - 200) / v->ymax) + 50;
	return (scalex);
}

int		scaledy(int y, t_visu *v)
{
	int	scaley;

	if (v->ymax > 0)
		scaley = (y - v->ymin) * ((double)(v->h - 200) /
		(double)(v->ymax - v->ymin)) + 50;
	else
		scaley = y * ((v->h - 200) / v->xmax) + 50;
	return (scaley);
}

int		set_defaults2(t_visu *v)
{
	v->startroom = NULL;
	v->endroom = NULL;
	v->coming = 0;
	v->toimage = 1;
	v->antlist = NULL;
	v->movelist = NULL;
	v->curmove = NULL;
	v->started = 0;
	v->count = 0;
	v->moves = 0;
	v->zerox = 0;
	v->zeroy = 0;
	return (0);
}

int		set_defaults(int size, t_visu *v)
{
	v->mlx = mlx_init();
	v->h = size;
	v->w = size;
	v->win = mlx_new_window(v->mlx, v->w, v->h, "");
	v->v_rooms = NULL;
	v->rooms = 0;
	v->ants = 0;
	v->ymax = 0;
	v->ymin = 0;
	v->xmax = 0;
	v->xmin = 0;
	v->rooms = 0;
	v->links = 0;
	v->start = -1;
	v->end = -1;
	set_defaults2(v);
	return (0);
}

int		free_info(char **info)
{
	if (info[0])
	{
		free(info[0]);
		info[0] = NULL;
	}
	if (info[1])
	{
		free(info[1]);
		info[1] = NULL;
	}
	if (info[2])
	{
		free(info[2]);
		info[2] = NULL;
	}
	free(info);
	return (0);
}
