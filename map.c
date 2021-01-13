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

	ft_putstr_fd("  ", 1);
	ft_putstr_fd("\r", 1);
	line = firstline;
	while (line)
	{
		ft_putendl_fd(line->str, 1);
		line = line->prev;
	}
	return (0);
}

int		handle_line(char *str, t_lem *lem)
{
	if (str[0] == '\0')
		return (error_m(15, lem));
	else if (ft_strncmp("#", str, 1) == 0)
		check_comments(str, lem);
	else if (!lem->ants)
		check_ant_line(str, lem);
	else if (lem->start == 0 || lem->end == 0)
	{
		if (is_room_line(str) == 0)
			return (error_m(4, lem));
		create_room(str, lem);
	}
	else if (is_room_line(str) == 1)
	{
		if (lem->link_part == 1)
			return (error_m(8, lem));
		create_room(str, lem);
	}
	else if (is_link_line(str) == 1)
		check_if_time_for_link_line(str, lem);
	else
		return (error_m(9, lem));
	return (0);
}

int		final_validation(t_lem *lem)
{
	if (lem->maplinelist == NULL)
		return (error_m(1, lem));
	lem->maplinelist->prev = NULL;
	if (lem->start != 1 || lem->end != 1)
		return (error_m(2, lem));
	if (lem->startroom->linklist == NULL || lem->endroom->linklist == NULL)
		return (error_m(3, lem));
	return (0);
}

int		read_map(t_lem *lem)
{
	char		*str;
	t_mapline	*newline;
	t_mapline	*temp;

	while (get_next_line(0, &str))
	{
		if (str == NULL)
			return (error_m(16, lem));
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
	final_validation(lem);
	return (0);
}
