/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		test_move_ant(t_ant *ant, t_lem *lem)
{
	t_linklist	*nextlink;

	nextlink = ant->link->next;
	if (nextlink->room == lem->endroom || nextlink->room->ants == 0)
	{
		ant->link->room->ants--;
		ant->link = nextlink;
		nextlink->room->ants++;
	}
	return (0);
}

int		test_send_ants(t_lem *lem)
{
	t_ant	*ant;
	int		ants_left;
	int		count;

	count = 0;
	ants_left = 1;
	while (ants_left)
	{
		ants_left = 0;
		ant = lem->antlist;
		while (ant)
		{
			if (ant->link->room != lem->endroom)
				test_move_ant(ant, lem);
			if (ant->link->room != lem->endroom)
				ants_left = 1;
			ant = ant->next;
		}
		count++;
	}
	return (count);
}

int		test_sign_ways_to_ants(t_lem *lem, t_linklist **option)
{
	t_ant	*ant;
	int		i;

	i = 0;
	ant = lem->antlist;
	while (ant)
	{
		ant->link = option[i];
		option[i]->signed_ants++;
		ant = ant->next;
		if (i == lem->ways - 1 || option[i]->size +
		option[i]->signed_ants <= option[i + 1]->size)
			i = 0;
		else
			i++;
	}
	return (0);
}

int		test_final_steps(t_lem *lem, t_linklist **option)
{
	int		steps;
	int		i;

	if (lem->ways == 0)
		return (1000);
	lem->startroom->ants = lem->ants;
	test_sign_ways_to_ants(lem, option);
	steps = test_send_ants(lem);
	i = 0;
	while (i < lem->ways)
	{
		option[i]->signed_ants = 0;
		i++;
	}
	if (lem->endroom->ants != lem->ants)
		steps = 10000;
	lem->endroom->ants = 0;
	return (steps);
}
