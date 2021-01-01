/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:57:06 by laskolin          #+#    #+#             */
/*   Updated: 2019/10/28 12:57:34 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		a;

	i = 0;
	while (s1[i])
		i++;
	a = 0;
	while (s2[a] && a < n)
	{
		s1[i] = s2[a];
		i++;
		a++;
	}
	s1[i] = '\0';
	return (s1);
}