/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 09:59:08 by laskolin          #+#    #+#             */
/*   Updated: 2019/11/02 20:06:16 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (!s1 || !s2 || n == 0)
		return (1);
	while (i < (n - 1) && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if ((unsigned char)s1[i] == (unsigned char)s2[i])
		return (1);
	return (0);
}
