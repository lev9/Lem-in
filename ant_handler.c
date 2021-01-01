/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		move_ant(t_ant *ant, t_lem *lem)
{
	t_linklist	*nextlink;

	nextlink = ant->link->next;
	if (nextlink->room == lem->endroom || nextlink->room->ants == 0)
	{
		ant->link->room->ants--;
		ant->link = nextlink;
		nextlink->room->ants++;
		ft_putstr_fd("L", 1);
		ft_putnbr_fd(ant->name, 1);
		ft_putstr_fd("-", 1);
		ft_putstr_fd(nextlink->room->name, 1);
		ft_putstr_fd(" ", 1);
	}
	return (0);
}

void	send_ants(t_lem *lem)
{
	t_ant	*ant;
	int		ants_left;

	if (ANTCOUNT == 1)
		print_ants(1, 0, lem);
	lem->finalcount = 0;
	while (lem->endroom->ants < lem->ants)
	{
		if (ANTCOUNT == 1)
			print_ants(4, lem->finalcount, lem);
		ants_left = 0;
		ant = lem->antlist;
		while (ant)
		{
			if (ant->link->room != lem->endroom)
				move_ant(ant, lem);
			ant = ant->next;
		}
		ft_putstr_fd("\n", 1);
		if (ANTCOUNT == 1)
			print_ants(2, lem->finalcount, lem);
		lem->finalcount++;
	}
}

int		sign_ways_to_ants(t_lem *lem)
{
	t_ant	*ant;
	int		i;

	i = 0;
	ant = lem->antlist;
	while (ant)
	{
		ant->link = lem->final_ways[i];
		lem->final_ways[i]->signed_ants++;
		if (i == lem->ways - 1 || lem->final_ways[i]->size +
		lem->final_ways[i]->signed_ants <= lem->final_ways[i + 1]->size)
			i = 0;
		else
			i++;
		ant = ant->next;
	}
	lem->startroom->ants = lem->ants;
	return (0);
}

int		create_ants(int ants, t_lem *lem)
{
	int		i;
	t_ant	*newant;
	t_ant	*temp;

	i = ants;
	while (i >= 1)
	{
		newant = (t_ant*)malloc(sizeof(t_ant));
		newant->name = i;
		temp = lem->antlist;
		lem->antlist = newant;
		newant->next = temp;
		i--;
	}
	lem->startroom->ants = lem->ants;
	return (0);
}
