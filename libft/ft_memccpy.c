/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:24:25 by laskolin          #+#    #+#             */
/*   Updated: 2019/11/10 10:44:30 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*dst2;
	const char		*src2;
	unsigned char	ch;
	size_t			i;

	dst2 = (char *)dst;
	src2 = (const char *)src;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dst2[i] = (unsigned char)src2[i];
		if ((unsigned char)src2[i] == ch)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
