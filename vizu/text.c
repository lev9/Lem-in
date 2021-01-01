/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	ant_in_room2(t_lst *room, char *str, t_xy xy, t_visu *v)
{
	if (room == v->endroom)
	{
		if (v->stretch == 1)
			mlx_string_put(v->mlx, v->win, xy.x, xy.y + 10, 0xFFFFFF, str);
		else
			mlx_string_put(v->mlx, v->win, xy.x, xy.y, 0xFFFFFF, str);
	}
	else if (room->ants > 1)
		mlx_string_put(v->mlx, v->win, xy.x, xy.y, 0x0022ff, str);
	else if (v->stretch == 0)
		mlx_string_put(v->mlx, v->win, xy.x, xy.y, 0xba3232, str);
	else
		mlx_string_put(v->mlx, v->win, xy.x, xy.y, 0xFFFFFF, str);
}

void	free_3(char *s1, char *s2, char *s3)
{
	free(s1);
	free(s2);
	free(s3);
}

void	ant_in_room(t_lst *room, int scalex, int scaley, t_visu *v)
{
	char	*str;
	char	*str2;
	char	*name;
	t_xy	xy;

	xy.x = scalex;
	xy.y = scaley;
	name = ft_strjoin(room->name, " ");
	str2 = ft_itoa(room->ants);
	str = ft_strjoin(name, str2);
	if (room == v->startroom)
	{
		if (v->stretch == 1)
			mlx_string_put(v->mlx, v->win, scalex, scaley - 10, 0xFFFFFF, str);
		else
			mlx_string_put(v->mlx, v->win, scalex, scaley, 0xFFFFFF, str);
	}
	else
		ant_in_room2(room, str, xy, v);
	free_3(name, str2, str);
}

void	basictext(char *str, t_visu *v)
{
	mlx_string_put(v->mlx, v->win, 20, v->h - 80, 0xFFFFFF, "ants:");
	str = ft_itoa(v->ants);
	mlx_string_put(v->mlx, v->win, 90, v->h - 80, 0xFFFFFF, str);
	free(str);
	mlx_string_put(v->mlx, v->win, 20, v->h - 60, 0xFFFFFF, "rooms:");
	str = ft_itoa(v->rooms);
	mlx_string_put(v->mlx, v->win, 90, v->h - 60, 0xFFFFFF, str);
	free(str);
	if (v->stretch == 1)
		mlx_string_put(v->mlx, v->win, 20, v->h - 110, 0xFF00FF,
		"map has been stretched for better vision!");
	mlx_string_put(v->mlx, v->win, 200, v->h - 80, 0xFFFFFF, "start:");
	mlx_string_put(v->mlx, v->win, 280, v->h - 80, 0xFFFFFF,
	v->startroom->name);
	mlx_string_put(v->mlx, v->win, 200, v->h - 60, 0xFFFFFF, "end:");
	mlx_string_put(v->mlx, v->win, 280, v->h - 60, 0xFFFFFF, v->endroom->name);
	mlx_string_put(v->mlx, v->win, 200, v->h - 40, 0xFFFFFF, "moves:");
	str = ft_itoa(v->count);
	mlx_string_put(v->mlx, v->win, 280, v->h - 40, 0xFFFFFF, str);
	free(str);
	str = ft_itoa(v->moves);
	mlx_string_put(v->mlx, v->win, v->w / 2, 5, 0x75e8ff, str);
	free(str);
	mlx_string_put(v->mlx, v->win, v->w / 2 - 100, 5, 0x75e8ff, "moves: ");
}

void	text(t_visu *v)
{
	char	*str;
	t_lst	*room;
	int		scalex;
	int		scaley;

	str = NULL;
	basictext(str, v);
	room = v->v_rooms;
	while (room)
	{
		scaley = 0;
		scalex = scaledx(room->x, v);
		scaley = scaledy(room->y, v);
		if (room->ants > 0)
			ant_in_room(room, scalex, scaley, v);
		else
		{
			if (v->stretch == 0)
			{
				str = room->name;
				mlx_string_put(v->mlx, v->win, scalex, scaley, 0xFFFFFF, str);
			}
		}
		room = room->next;
	}
}
