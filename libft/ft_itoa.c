/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:49:19 by laskolin          #+#    #+#             */
/*   Updated: 2019/11/08 19:22:17 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	put_to_res(char *res, int nb, int i)
{
	int	a;

	a = 1;
	while (nb / a >= 10)
		a *= 10;
	while (a >= 1)
	{
		res[i] = (nb / a) + '0';
		nb = nb % a;
		a /= 10;
		i++;
	}
}

char		*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		len;

	len = ft_len(n);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	i = 0;
	if (n < 0)
	{
		res[i] = '-';
		i++;
		if (n == -2147483648)
		{
			res[i] = '2';
			n = -147483648;
			i++;
		}
		n = -n;
	}
	put_to_res(res, n, i);
	res[len] = '\0';
	return (res);
}
