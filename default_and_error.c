/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_and_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		set_default_values(t_lem *lem)
{
	lem->ants = 0;
	lem->start = -1;
	lem->end = -1;
	lem->room_part = 1;
	lem->link_part = 0;
	lem->rooms = 0;
	lem->links = 0;
	lem->roomlist = NULL;
	lem->startroom = NULL;
	lem->endroom = NULL;
	lem->antlist = NULL;
	lem->maplinelist = NULL;
	lem->required = 0;
	lem->fast = 0;
	return (0);
}

int		error_m2(int why, t_lem *lem)
{
	if (why == 9)
	{
		if (lem->rooms == 0)
			ft_putstr_fd("no rooms.\n", 2);
		else
			ft_putstr_fd("unvalid line.\n", 2);
	}
	else if (why == 10)
		ft_putstr_fd("same room name or same coordinates twice.\n", 2);
	else if (why == 11)
		ft_putstr_fd("unvalid room name.\n", 2);
	else if (why == 12)
		ft_putstr_fd("ant farm has no solution.\n", 2);
	else if (why == 13)
		ft_putstr_fd("one of linked rooms doesn't exist.\n", 2);
	else if (why == 14)
		ft_putstr_fd("link line before defining start room or end room.\n", 2);
	else if (why == 15)
		ft_putstr_fd("empty line.\n", 2);
	else
		ft_putstr_fd("unvalid line.\n", 2);
	exit(0);
}

int		error_m(int why, t_lem *lem)
{
	ft_putstr_fd("ERROR\n", 2);
	if (why == 1)
		ft_putstr_fd("empty ant farm.\n", 2);
	else if (why == 2)
		ft_putstr_fd("start room or end room missing.\n", 2);
	else if (why == 3)
		ft_putstr_fd("start room or end room is isolated.\n", 2);
	else if (why == 4)
		ft_putstr_fd("not a valid room line after ##start or ##end.\n", 2);
	else if (why == 5)
		ft_putstr_fd("##start appears multiple times.\n", 2);
	else if (why == 6)
		ft_putstr_fd("##end appears multiple times.\n", 2);
	else if (why == 7)
		ft_putstr_fd("does not begin with a valid ant number.\n", 2);
	else if (why == 8)
		ft_putstr_fd("room line in a link section.\n", 2);
	else
		error_m2(why, lem);
	exit(0);
}

int		final_error(t_lem *lem)
{
	int		i;

	if (lem->endroom->ants != lem->ants)
	{
		i = 0;
		while (i < 1000)
		{
			ft_putendl_fd("PROGRAM FAILED!", 1);
			i++;
		}
		return (0);
	}
	return (0);
}
