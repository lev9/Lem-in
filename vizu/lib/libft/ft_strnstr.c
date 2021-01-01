/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 08:25:32 by laskolin          #+#    #+#             */
/*   Updated: 2019/11/04 10:37:12 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		a;
	size_t		b;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		a = 0;
		b = i;
		while (b < len && haystack[b] == needle[a])
		{
			if (needle[a + 1] == '\0')
				return ((char *)haystack + i);
			b++;
			a++;
		}
		i++;
	}
	return (NULL);
}
