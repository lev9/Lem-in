/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:02:14 by laskolin          #+#    #+#             */
/*   Updated: 2019/11/04 09:55:39 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*str;
	unsigned char	ch;

	i = 0;
	str = (char *)b;
	ch = (unsigned char)c;
	while (i < len)
	{
		str[i] = ch;
		i++;
	}
	return (str);
}
