/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:46:33 by laskolin          #+#    #+#             */
/*   Updated: 2019/11/09 19:20:35 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*strd;
	const char	*strs;

	if (dst == NULL && src == NULL)
		return (dst);
	i = 0;
	strd = (char *)dst;
	strs = (const char *)src;
	while (i < n)
	{
		strd[i] = strs[i];
		i++;
	}
	return (dst);
}
