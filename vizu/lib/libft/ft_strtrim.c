/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:50:57 by laskolin          #+#    #+#             */
/*   Updated: 2019/11/06 10:50:35 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_wsp(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char	*fresh;
	int		last;
	int		first;

	if (!s)
		return (NULL);
	last = ft_strlen(s) - 1;
	while (ft_is_wsp(s[last]) && last > 0)
		last--;
	if (last == 0)
		fresh = ft_strsub(s, last, 0);
	else
	{
		first = 0;
		while (ft_is_wsp(s[first]))
			first++;
		fresh = ft_strsub(s, first, last - (first - 1));
	}
	return (fresh);
}
