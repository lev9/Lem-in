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

int		error_m(void)
{
	ft_putstr_fd("ERROR\n", 2);
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
