/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_collector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int			add_to_rooms_links(t_linklist **linklist, t_linklist *link)
{
	t_linklist	*tmp;

	if (*linklist)
	{
		tmp = *linklist;
		while (tmp->next != NULL)
		{
			if (tmp->room == link->room || tmp->next->room == link->room)
			{
				free(link);
				return (0);
			}
			tmp = tmp->next;
		}
		tmp->next = link;
	}
	else
		*linklist = link;
	return (1);
}

t_linklist	*new_link(t_room *tmp)
{
	t_linklist	*new;

	new = (t_linklist*)malloc(sizeof(t_linklist));
	if (new)
	{
		new->room = tmp;
		new->next = NULL;
		new->checked = 0;
		new->signed_ants = 0;
		return (new);
	}
	return (NULL);
}

int			free_info(char **info)
{
	free(info[0]);
	info[0] = NULL;
	free(info[1]);
	info[1] = NULL;
	if (info[2])
	{
		free(info[2]);
		info[2] = NULL;
	}
	free(info);
	return (0);
}

int			create_link(char *str, t_lem *lem)
{
	char		**info;
	t_room		*tmp;
	t_room		*tmp2;
	t_linklist	*newlink;
	t_linklist	*newlink2;

	info = ft_strsplit(str, '-');
	tmp = lem->roomlist;
	while (tmp && ft_strcmp(tmp->name, info[0]) != 0)
		tmp = tmp->next;
	tmp2 = lem->roomlist;
	while (tmp2 && ft_strcmp(tmp2->name, info[1]) != 0)
		tmp2 = tmp2->next;
	if (tmp == NULL || tmp2 == NULL)
		return (error_m());
	newlink = new_link(tmp2);
	add_to_rooms_links(&tmp->linklist, newlink);
	newlink2 = new_link(tmp);
	if (add_to_rooms_links(&tmp2->linklist, newlink2) == 1)
		lem->links++;
	free_info(info);
	return (0);
}
