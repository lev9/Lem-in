/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "./lib/libft/libft.h"
# include "./lib/libmlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define B "\033[0;34m"
# define G "\x1B[32m"
# define R "\x1b[31m"
# define Y "\x1b[33m"
# define N "\033[0;0m"

typedef struct s_linklist	t_linklist;
typedef struct s_lst		t_lst;
typedef struct s_ant		t_ant;
typedef struct s_move		t_move;
typedef struct s_draw		t_draw;
typedef struct s_visu		t_visu;
typedef struct s_xy		t_xy;
typedef struct s_wh		t_wh;

struct		s_xy
{
	int		x;
	int		y;
};

struct		s_wh
{
	int		w;
	int		h;
};

struct		s_linklist
{
	t_lst		*room;
	t_linklist	*next;
};

struct		s_lst
{
	int			x;
	int			y;
	int			ants;
	char		*name;
	t_lst		*next;
	t_linklist	*linklist;
};

struct		s_ant
{
	int			name;
	t_ant		*next;
	t_lst		*room;
};

struct		s_move
{
	char	**moves;
	t_move	*next;
};

struct		s_draw
{
	int		oldx;
	int		oldy;
	int		x_len;
	int		y_len;
	double	x_step;
	double	y_step;
	double	jumpy;
	double	jumpx;
};

struct		s_visu
{
	void	*mlx;
	void	*win;
	void	*screen;
	char	*map;
	int		*buf;
	int		size;
	int		w;
	int		h;
	int		rooms;
	int		ymax;
	int		ymin;
	int		xmax;
	int		xmin;
	int		ants;
	int		start;
	int		end;
	int		links;
	int		coming;
	int		toimage;
	int		started;
	int		count;
	int		moves;
	int		zerox;
	int		zeroy;
	int		stretch;
	int		haha;
	t_lst	*v_rooms;
	t_lst	*startroom;
	t_lst	*endroom;
	t_ant	*antlist;
	t_move	*movelist;
	t_move	*curmove;
	t_draw	*draw;
};

/*
**	visu.c
*/

int			min_max2(int i, char **split, t_visu *v);
int			get_min_max(t_visu *v);
int			fix_x_y(t_visu *v);
int			main(int argc, char **argv);

/*
**	help.c
*/

int			scaledx(int x, t_visu *v);
int			scaledy(int y, t_visu *v);
int			set_defaults2(t_visu *v);
int			set_defaults(int size, t_visu *v);
int			free_info(char **info);

/*
**	read.c
*/

int			link_line(char *str);
int			room_line(char *str);
int			handle_line(char *str, int i, t_visu *v);
int			read_stats(t_visu *v);

/*
**	key1.c
*/

int			next_step(int i, t_visu *v);
int			space_key(t_visu *v);
int			deal_key(int key, t_visu *v);

/*
**	key2.c
*/

int			start(t_visu *v);
int			finish(t_visu *v);
int			move_ant(int antname, char *roomname, t_visu *v);

/*
**	room.c
*/

int			draw_room (t_lst *room, t_visu *v);
void		lst_add(t_lst **head, t_lst *new);
t_lst		*lst_new(char **info, t_visu *v);
int			add_v_room(char *str, t_visu *v);

/*
**	link.c
*/

int			draw_a_link(t_lst *room, t_lst *room2, int ant, t_visu *v);
int			link_add(t_linklist **linklist, t_linklist *link);
t_linklist	*new_link(t_lst *tmp);
int			add_v_link(char *str, t_visu *v);

/*
**	move.c
*/

int			print_moves(t_visu *v);
void		move_add(t_move **head, t_move *new);
t_move		*move_new(char **info);
int			add_move(char *str, t_visu *v);

/*
**	ant.c
*/

int			print_ants(t_visu *v, int color, int n);
void		ant_add(t_ant **head, t_ant *new);
t_ant		*ant_new(int i, t_visu *v);
int			create_ants(int size, t_visu *v);

/*
**	window.c
*/

void		get_images(t_visu *v);
int			paint_window(t_visu *v);
int			panel(t_visu *v);

/*
**	text.c
*/

void		ant_in_room2(t_lst *room, char *str, t_xy xy, t_visu *v);
void		free_3(char *s1, char *s2, char *s3);
void		ant_in_room(t_lst *room, int scalex, int scaley, t_visu *v);
void		basictext(char *str, t_visu *v);
void		text(t_visu *v);

/*
**	paint.c
*/

void		paint(t_xy xy, t_wh wh, t_visu *v, int color);
void		draw(int steps, int col, int ant, t_visu *v);
int			draw_line(t_xy oldxy, t_xy newxy, int ant, t_visu *v);

#endif
