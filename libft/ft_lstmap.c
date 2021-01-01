/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:31:28 by laskolin          #+#    #+#             */
/*   Updated: 2019/11/09 19:43:13 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*tmp;
	t_list	*new;

	if (!lst)
		return (NULL);
	tmp = (*f)(lst);
	fresh = ft_lstnew(tmp->content, tmp->content_size);
	lst = lst->next;
	new = fresh;
	while (lst)
	{
		tmp = (*f)(lst);
		new->next = ft_lstnew(tmp->content, tmp->content_size);
		lst = lst->next;
		new = new->next;
	}
	return (fresh);
}
