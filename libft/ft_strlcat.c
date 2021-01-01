/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:11:21 by laskolin          #+#    #+#             */
/*   Updated: 2019/11/04 10:30:11 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		a;
	size_t		try;

	i = 0;
	while (dst[i])
		i++;
	a = 0;
	while (src[a])
		a++;
	if (i < dstsize)
		try = a + i;
	else
		try = a + dstsize;
	a = 0;
	while (i < dstsize - 1 && src[a] && dstsize != 0)
	{
		dst[i] = src[a];
		i++;
		a++;
	}
	dst[i] = '\0';
	return (try);
}
