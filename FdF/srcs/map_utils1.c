/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:43:35 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/04 10:28:39 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	project(t_fdf *fdf, double x, double y, double z)
{
	t_point	point;
	double	angle;

	angle = 0.523599;
	z *= fdf->z_scale;
	point.x = (x - y) * cos(angle);
	point.y = (x + y) * sin(angle) - z;
	point.x *= fdf->zoom;
	point.y *= fdf->zoom;
	point.x += fdf->off_x;
	point.y += fdf->off_y;
	return (point);
}

void	draw_line_x(t_fdf *fdf, t_line *line, t_point p2)
{
	line->p = 2 * line->dy - line->dx;
	while ((int)line->x != (int)p2.x)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, (int)line->x, (int)line->y, 0xFFFFFF);
		line->x += line->x_inc;
		if (line->p >= 0)
		{
			line->y += line->y_inc;
			line->p += 2 * (line->dy - line->dx);
		}
		else
			line->p += 2 * line->dy;
	}
}

void	draw_line_y(t_fdf *fdf, t_line *line, t_point p2)
{
	line->p = 2 * line->dx - line->dy;
	while ((int)line->y != (int)p2.y)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, (int)line->x, (int)line->y, 0xFFFFFF);
		line->y += line->y_inc;
		if (line->p >= 0)
		{
			line->x += line->x_inc;
			line->p += 2 * (line->dx - line->dy);
		}
		else
			line->p += 2 * line->dx;
	}
}
