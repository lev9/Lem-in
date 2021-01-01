/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:36:50 by laskolin          #+#    #+#             */
/*   Updated: 2019/10/29 11:58:26 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		a;

	i = 0;
	while (s1[i])
		i++;
	a = 0;
	while (s2[a])
	{
		s1[i] = s2[a];
		i++;
		a++;
	}
	s1[i] = '\0';
	return (s1);
}