/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_col.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:17:39 by laskolin          #+#    #+#             */
/*   Updated: 2019/11/06 10:54:21 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd_col(char const *s, int fd, char *col)
{
	int		i;

	if (s)
	{
		ft_putstr_fd(col, 1);
		i = 0;
		while (s[i])
			i++;
		write(fd, s, i);
	}
}
