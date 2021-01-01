/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		next_step(int i, t_visu *v)
{
	char	*move;
	char	**movesplit;
	char	*roomname;
	int		antname;

	v->toimage = 0;
	mlx_put_image_to_window(v->mlx, v->win, v->screen, 0, 0);
	if (v->stretch == 1)
		print_ants(v, 0xe6ff00e6, 1);
	while (v->curmove->moves[i] != NULL)
	{
		move = v->curmove->moves[i] + 1;
		movesplit = ft_strsplit(move, '-');
		antname = ft_atoi(movesplit[0]);
		roomname = movesplit[1];
		move_ant(antname, roomname, v);
		i++;
		free_info(movesplit);
	}
	v->count++;
	if (v->stretch == 0)
		print_ants(v, 0xFF00FF, 0);
	text(v);
	return (0);
}

int		space_key(t_visu *v)
{
	if (v->curmove == NULL && v->started == 0)
	{
		v->count = 0;
		start(v);
		return (0);
	}
	else if (v->curmove == NULL && v->started == 1)
		v->curmove = v->movelist;
	else
		v->curmove = v->curmove->next;
	if (v->curmove == NULL)
	{
		finish(v);
		return (0);
	}
	if (v->curmove->next == NULL)
	{
		mlx_put_image_to_window(v->mlx, v->win, v->screen, 0, 0);
		text(v);
	}
	if (v->curmove)
		next_step(0, v);
	return (0);
}

int		deal_key(int key, t_visu *v)
{
	if (key == 53)
		exit(0);
	if (key == 49)
		space_key(v);
	return (1);
}
