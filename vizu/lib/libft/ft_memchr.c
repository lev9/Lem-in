/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:22:03 by laskolin          #+#    #+#             */
/*   Updated: 2019/11/06 10:21:30 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*s1;
	unsigned char	ch;
	size_t			i;

	s1 = (char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)(s1[i]) == ch)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
