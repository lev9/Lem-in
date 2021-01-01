/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		print_map(t_mapline *firstline)
{
	t_mapline	*line;

	line = firstline;
	while (line)
	{
		ft_putendl_fd(line->str, 1);
		line = line->prev;
	}
	return (0);
}

int		read_map(t_lem *lem)
{
	char		*str;
	t_mapline	*newline;
	t_mapline	*temp;

	while (get_next_line(0, &str))
	{
		handle_line(str, lem);
		newline = (t_mapline*)malloc(sizeof(t_mapline));
		newline->str = str;
		temp = lem->maplinelist;
		lem->maplinelist = newline;
		newline->next = temp;
		if (temp)
			temp->prev = newline;
		if (newline->next == NULL)
			lem->firstline = newline;
	}
	if (lem->maplinelist == NULL)
		return (error_m());
	lem->maplinelist->prev = NULL;
	if (lem->start != 1 || lem->end != 1)
		return (error_m());
	if (lem->startroom->linklist == NULL || lem->endroom->linklist == NULL)
		return (error_m());
	return (0);
}
