/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:09:33 by laskolin          #+#    #+#             */
/*   Updated: 2019/11/08 22:23:02 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] || (s[i] == '\0' && c == '\0'))
	{
		if ((s[i]) == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
