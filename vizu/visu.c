/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		min_max2(int i, char **split, t_visu *v)
{
	int		x;
	int		y;

	x = ft_atoi(split[1]);
	if (x > v->xmax)
		v->xmax = x;
	y = ft_atoi(split[2]);
	if (y > v->ymax)
		v->ymax = y;
	if (i == 0)
	{
		v->xmin = x;
		v->ymin = y;
	}
	else
	{
		if (x < v->xmin)
			v->xmin = x;
		if (y < v->ymin)
			v->ymin = y;
	}
	i++;
	v->rooms++;
	return (i);
}

int		get_min_max(t_visu *v)
{
	char	*str;
	char	**split;
	int		fd;
	int		i;

	i = 0;
	system("touch vizu/jep");
	fd = open("vizu/jep", O_RDWR);
	while (get_next_line(0, &str))
	{
		if (ft_strcmp(str, "ERROR") == 0)
		{
			system("rm vizu/jep");
			exit(0);
		}
		ft_putendl_fd(str, fd);
		if (room_line(str))
		{
			split = ft_strsplit(str, ' ');
			i = min_max2(i, split, v);
			free_info(split);
		}
		free(str);
	}
	return (i);
}

int		fix_x_y(t_visu *v)
{
	int		i;

	i = get_min_max(v);
	if (i == 0)
	{
		system("rm vizu/jep");
		exit(0);
	}
	if (v->xmax == v->xmin)
	{
		v->xmax = i;
		v->zerox = 1;
	}
	if (v->ymax == v->ymin)
	{
		v->ymax = i;
		v->zeroy = 1;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_visu	*v;
	t_visu	newvisu;
	int		size;

	v = &newvisu;
	if (argc == 2 && ft_atoi(argv[1]) == 1)
		v->stretch = ft_atoi(argv[1]);
	else
		v->stretch = ft_atoi(argv[0]);
	size = 800;
	set_defaults(size, v);
	ft_putstr_fd("🐜\n\n", 1);
	get_images(v);
	paint_window(v);
	fix_x_y(v);
	read_stats(v);
	panel(v);
	mlx_put_image_to_window(v->mlx, v->win, v->screen, 0, 0);
	text(v);
	mlx_key_hook(v->win, deal_key, v);
	mlx_loop(v->mlx);
	return (0);
}
