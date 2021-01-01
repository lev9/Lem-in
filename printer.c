/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void		print_option_results(int count, t_lem *lem)
{
	ft_putstr_fd_col("\nfound options: ", 1, N);
	if (count == lem->len1)
		ft_putnbr_fd_col(lem->len1, 1, P);
	else
		ft_putnbr_fd_col(lem->len1, 1, G);
	ft_putstr_fd_col(" ", 1, N);
	if (count == lem->len2)
		ft_putnbr_fd_col(lem->len2, 1, P);
	else
		ft_putnbr_fd_col(lem->len2, 1, G);
	ft_putstr_fd_col(" ", 1, N);
	if (count == lem->len3)
		ft_putnbr_fd_col(lem->len3, 1, P);
	else
		ft_putnbr_fd_col(lem->len3, 1, G);
	ft_putstr_fd_col(" ", 1, N);
	if (count == lem->len4)
		ft_putnbr_fd_col(lem->len4, 1, P);
	else
		ft_putnbr_fd_col(lem->len4, 1, G);
	ft_putstr_fd_col(" ", 1, N);
	if (count == lem->len5)
		ft_putnbr_fd_col(lem->len5, 1, P);
	else
		ft_putnbr_fd_col(lem->len5, 1, G);
}

void		print_results(int count, t_lem *lem)
{
	ft_putstr_fd_col("\n", 1, N);
	if (lem->required)
		ft_putstr_fd(lem->req, 1);
	ft_putstr_fd_col("\n", 1, N);
	if (lem->fast)
		ft_putstr_fd_col("\nAnts have moved straight to the end room!\n", 1, N);
	else if (lem->links >= 1000)
		print_option_results(count, lem);
	ft_putstr_fd_col("\n", 1, N);
	ft_putstr_fd_col("ants: ", 1, N);
	ft_putnbr_fd_col(lem->ants, 1, R);
	ft_putstr_fd_col(" rooms: ", 1, N);
	ft_putnbr_fd_col(lem->rooms, 1, R);
	ft_putstr_fd_col(" links: ", 1, N);
	ft_putnbr_fd_col(lem->links, 1, R);
	ft_putstr_fd_col("    MOVES: ", 1, N);
	ft_putnbr_fd_col(count, 1, N);
	ft_putstr_fd_col("\n", 1, N);
	ft_putstr_fd_col("\n", 1, N);
}

void		print_ants(int i, int count, t_lem *lem)
{
	if (i == 1)
	{
		ft_putstr_fd_col("start room ants: ", 1, R);
		ft_putnbr_fd_col(lem->startroom->ants, 1, R);
		ft_putstr_fd_col("   end room ants: ", 1, G);
		ft_putnbr_fd_col(lem->endroom->ants, 1, G);
		ft_putstr_fd_col("\n", 1, N);
	}
	else if (i == 2)
	{
		ft_putnbr_fd_col(lem->startroom->ants, 1, R);
		ft_putstr_fd_col(" | ", 1, N);
		ft_putnbr_fd_col(lem->endroom->ants, 1, G);
		ft_putstr_fd_col("\n", 1, N);
	}
	else if (i == 3)
		print_results(count, lem);
	else
	{
		ft_putstr_fd("          ", 1);
		ft_putnbr_fd_col(lem->finalcount + 1, 1, P);
		ft_putstr_fd_col(".\n", 1, N);
	}
}
