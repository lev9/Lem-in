/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int	is_link_line(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '-')
		return (0);
	if (str[0] == '#' || str[0] == 'L')
		return (0);
	while (ft_isprint(str[i]) && str[i] != '-')
		i++;
	if (str[i] != '-')
		return (0);
	i++;
	if (str[i] == '-')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '-' && str[i + 1] == 0)
			return (0);
		if (!(ft_isprint(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int	is_room_line(char *str)
{
	int	i;

	if (str[0] == '#' || str[0] == 'L')
		return (0);
	i = 0;
	while (ft_isprint(str[i]) && str[i] != ' ')
		i++;
	if (str[i] != ' ')
		return (0);
	i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != ' ')
		return (0);
	i++;
	while (str[i] != '\0')
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int	check_comments(char *str, t_lem *lem)
{
	if (lem->start == 0 || lem->end == 0)
		return (error_m(4, lem));
	else if (ft_strcmp("##start", str) == 0)
	{
		if (lem->start == 1)
			return (error_m(5, lem));
		lem->start = 0;
	}
	else if (ft_strcmp("##end", str) == 0)
	{
		if (lem->end == 1)
			return (error_m(6, lem));
		lem->end = 0;
	}
	else if (ft_strncmp("#Here is the number of lines required:", str, 38) == 0)
	{
		lem->required = 1;
		lem->req = str;
	}
	return (0);
}

int	check_ant_line(char *str, t_lem *lem)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (error_m(7, lem));
		i++;
		if (i == 9 && str[0] >= 2)
			return (error_m(7, lem));
	}
	lem->ants = ft_atoi(&str[0]);
	return (0);
}

int	check_if_time_for_link_line(char *str, t_lem *lem)
{
	if (lem->end == 1 && lem->start == 1)
	{
		lem->room_part = 0;
		lem->link_part = 1;
		create_link(str, lem);
	}
	else
		return (error_m(14, lem));
	return (0);
}
