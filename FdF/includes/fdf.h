/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:27:14 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/04 10:28:47 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
//#include <X11/keysym.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define MINUS 24
# define PLUS 27
# define ESC 53
# define ZOOM_MAX 100.0

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		colour;
}			t_point;

typedef struct s_map
{
	t_point	**pts;
	int		width;
	int		height;
}			t_map;

typedef struct s_line
{
	double	dx;
	double	dy;
	double	x;
	double	y;
	double	p;
	double	x_inc;
	double	y_inc;
}			t_line;

typedef struct s_anal
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	min_z;
	double	max_z;
	double	x_range;
	double	y_range;
	double	z_range;
	double	density;
}			t_anal;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	double	zoom;
	double	off_x;
	double	off_y;
	double	z_scale;
	int		step;
	t_map	*map;
	t_anal	anal;
}			t_fdf;

/* **********************************draw map******************************** */
t_map		*readmap(int fd, int w, int h);
t_map		*init_map(int wd, int ht);
t_point		project(t_fdf *fdf, double x, double y, double z);
void		draw_map(t_fdf *fdf);
void		init_fdf(t_fdf *fdf);
void		draw_x(t_fdf *fdf, t_point **space, int x, int y);
void		draw_y(t_fdf *fdf, t_point **space, int x, int y);
/* *********************************parse line******************************* */
int			parse_line(char *line, t_map *map, int y);
void		draw_line(t_fdf *fdf, t_point p1, t_point p2);
void		draw_line_x(t_fdf *fdf, t_line *line, t_point p2);
void		draw_line_y(t_fdf *fdf, t_line *line, t_point p2);
/* **********************************map ctrl******************************** */
void		orientate_map(t_fdf *fdf);
void		move_map(int key, t_fdf *fdf);
void		zoom_map(int key, t_fdf *fdf);
/* ******************************map ANALyser******************************** */
void		check_map(t_fdf *fdf, t_anal *anal);
void		map_analyse(t_map *map, t_anal *anal, int x, int y);
void		map_sizer(t_map *map, t_anal *anal);
void		scale_map(t_fdf *fdf);
/* *********************************file utils******************************* */
void		heads_up(int ac);
int			file_error(void);
int			arg_handler(char *filename, int *w, int *h, t_map **map);
/* **********************************aux utils******************************* */
void		*free_map(t_map *map);
int			map_dimensions(int fd, int *w, int *h);
int			expose_hook(t_fdf *fdf);
int			key_press(int key, void *param);
int			key_release(int key, void *param);
int			close_shop(t_fdf *fdf);

#endif