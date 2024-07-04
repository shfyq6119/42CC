/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:07:35 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/04 10:11:01 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_map(t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	**space;

	y = 0;
	space = fdf->map->pts;

	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x < fdf->map->width - fdf->step)
				draw_x(fdf, space, x, y);
			if (y < fdf->map->height - fdf->step)
				draw_y(fdf, space, x, y);
			x += fdf->step;
		}
		y += fdf->step;
	}
}

void	draw_x(t_fdf *fdf, t_point **space, int x, int y)
{
	t_point	p1;
	t_point	p2;
	int		xs;

	xs = x + fdf->step;
	p1 = project(fdf, space[y][x].x, space[y][x].y, space[y][x].z);
	p2 = project(fdf, space[y][xs].x, space[y][xs].y, space[y][xs].z);
	draw_line(fdf, p1, p2);
}

void	draw_y(t_fdf *fdf, t_point **space, int x, int y)
{
	t_point	p1;
	t_point	p2;
	int		ys;

	ys = y + fdf->step;
	p1 = project(fdf, space[y][x].x, space[y][x].y, space[y][x].z);
	p2 = project(fdf, space[ys][x].x, space[ys][x].y, space[ys][x].z);
	draw_line(fdf, p1, p2);
}

void	draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	t_line	line;

	line.dx = fabs(p2.x - p1.x);
	line.dy = fabs(p2.y - p1.y);
	line.x = p1.x;
	line.y = p1.y;
	if (p2.x > p1.x)
		line.x_inc = 1.0;
	else
		line.x_inc = -1.0;
	if (p2.y > p1.y)
		line.y_inc = 1.0;
	else
		line.y_inc = -1.0;
	if (line.dx > line.dy)
		draw_line_x(fdf, &line, p2);
	else
		draw_line_y(fdf, &line, p2);
}
