/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:19:15 by laskolin          #+#    #+#             */
/*   Updated: 2019/11/09 19:03:03 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	tmp = *alst;
	if (tmp)
	{
		while (tmp)
		{
			(*del)((tmp)->content, (tmp)->content_size);
			free(tmp);
			tmp = tmp->next;
		}
	}
	*alst = NULL;
}
