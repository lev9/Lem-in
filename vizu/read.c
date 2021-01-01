/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		link_line(char *str)
{
	int		i;

	i = 0;
	if (str[0] == 'L')
		return (0);
	while (ft_isprint(str[i]) && str[i] != '-')
		i++;
	if (str[i] != '-')
		return (0);
	i++;
	while (str[i] != '\0')
	{
		if (!(ft_isprint(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int		room_line(char *str)
{
	int		i;

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
		if (!(ft_isalnum(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int		handle_line(char *str, int i, t_visu *v)
{
	if (ft_strcmp("##start", str) == 0)
		v->start = 0;
	else if (ft_strcmp("##end", str) == 0)
		v->end = 0;
	else if (ft_strncmp("#", str, 1) == 0)
		v->haha = 1;
	else if (i == 0)
		v->ants = ft_atoi(str);
	else if (room_line(str))
		add_v_room(str, v);
	else if (link_line(str))
		add_v_link(str, v);
	else if (str[0] == 'L')
		add_move(str, v);
	else if (str[0] == '\0')
	{
		if (!v->antlist)
			create_ants(v->ants, v);
	}
	return (0);
}

int		read_stats(t_visu *v)
{
	char	*str;
	int		i;
	int		fd;

	fd = open("vizu/jep", O_RDWR);
	i = 0;
	while (get_next_line(fd, &str))
	{
		handle_line(str, i, v);
		i++;
		free(str);
	}
	system("cat vizu/jep");
	system("rm vizu/jep");
	return (0);
}
