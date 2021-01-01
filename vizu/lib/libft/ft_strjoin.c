/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:59:58 by laskolin          #+#    #+#             */
/*   Updated: 2019/12/05 12:47:15 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*fresh;
	size_t		i;
	size_t		a;

	if (!s1 || !s2)
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!fresh)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		fresh[i] = s1[i];
		i++;
	}
	a = 0;
	while (s2[a])
	{
		fresh[i] = s2[a];
		i++;
		a++;
	}
	fresh[i] = '\0';
	return (fresh);
}
