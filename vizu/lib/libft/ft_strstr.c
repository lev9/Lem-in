/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:03:12 by laskolin          #+#    #+#             */
/*   Updated: 2019/11/08 22:28:51 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		a;
	int		b;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		a = 0;
		b = i;
		while (haystack[b] == needle[a])
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
