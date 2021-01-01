/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_col.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:28:10 by laskolin          #+#    #+#             */
/*   Updated: 2019/10/31 20:35:55 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	final(int n, int fd, int i)
{
	char	c;

	while (i > 1)
	{
		c = ((n / i) + '0');
		write(fd, &c, 1);
		n = n % i;
		i = i / 10;
	}
	c = (n + '0');
	write(fd, &c, 1);
}

void		ft_putnbr_fd_col(int n, int fd, char *col)
{
	int		i;

	ft_putstr_fd(col, 1);
	i = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2", 1);
			n = -147483648;
		}
		n = -n;
	}
	while (n / i >= 10)
		i = i * 10;
	final(n, fd, i);
}
