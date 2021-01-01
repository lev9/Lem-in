/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		print_moves(t_visu *v)
{
	t_move	*tmp;
	int		i;

	tmp = v->movelist;
	while (tmp)
	{
		i = 0;
		while (tmp->moves[i] != NULL)
		{
			ft_putstr_fd_col(tmp->moves[i], 1, N);
			ft_putstr_fd_col(" ", 1, N);
			i++;
		}
		ft_putstr_fd_col("\n", 1, N);
		tmp = tmp->next;
	}
	return (0);
}

void	move_add(t_move **head, t_move *new)
{
	t_move	*temp;

	if (*head)
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	else
		*head = new;
}

t_move	*move_new(char **info)
{
	t_move	*new;

	new = (t_move*)malloc(sizeof(t_move));
	if (new)
	{
		new->moves = info;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

int		add_move(char *str, t_visu *v)
{
	char	**info;
	t_move	*newmove;

	info = ft_strsplit(str, ' ');
	newmove = move_new(info);
	move_add(&v->movelist, newmove);
	v->moves++;
	return (0);
}
