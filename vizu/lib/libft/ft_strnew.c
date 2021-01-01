/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:56:06 by laskolin          #+#    #+#             */
/*   Updated: 2019/11/06 15:19:11 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	new = (char *)malloc(size * sizeof(char) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}
