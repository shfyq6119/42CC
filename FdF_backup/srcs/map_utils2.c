/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 03:35:56 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/04 10:27:40 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_sizer(t_map *map, t_anal *anal)
{
	int	x;
	int	y;

	y = 0;
	anal->max_x = map->pts[0][0].x;
	anal->max_y = map->pts[0][0].y;
	anal->max_z = map->pts[0][0].z;
	anal->min_x = anal->max_x;
	anal->min_y = anal->max_y;
	anal->min_z = anal->max_z;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map_analyse(map, anal, x, y);
			x++;
		}
		y++;
	}
	anal->x_range = fabs(anal->max_x - anal->min_x);
	anal->y_range = fabs(anal->max_y - anal->min_y);
	anal->z_range = fabs(anal->max_z - anal->min_z);
}

void	map_analyse(t_map *map, t_anal *anal, int x, int y)
{
	if (map->pts[y][x].x < anal->min_x)
		anal->min_x = map->pts[y][x].x;
	if (map->pts[y][x].x > anal->max_x)
		anal->max_x = map->pts[y][x].x;
	if (map->pts[y][x].y < anal->min_y)
		anal->min_y = map->pts[y][x].y;
	if (map->pts[y][x].y > anal->max_y)
		anal->max_y = map->pts[y][x].y;
	if (map->pts[y][x].z < anal->min_z)
		anal->min_z = map->pts[y][x].z;
	if (map->pts[y][x].z > anal->max_z)
		anal->max_z = map->pts[y][x].z;
}

void	check_map(t_fdf *fdf, t_anal *anal)
{
	double	map_area;
	double	map_plot;

	map_sizer(fdf->map, anal);
	map_area = fdf->map->width * fdf->map->height;
	map_plot = anal->x_range * anal->y_range;
	anal->density = map_plot / map_area;
	printf("anal->x_range: %f, anal->y_range: %f\n", anal->x_range, anal->y_range);
	printf("density: %f\n", anal->density);
	printf ("map area: %f, xy_plot: %f\n", map_area, map_plot);
	if (anal->density > 1.0)
		fdf->step = 10;
	else if (anal->density > 0.97)
		fdf->step = 5;
	else if (anal->density > 0.95)
		fdf->step = 2;
	else
		fdf->step = 1;
	printf("step: %d\n", fdf->step);
}

// void	scale_map(t_fdf *fdf)
// {
// 	double	xy;
// 	double	max;

// 	xy = fmax(fdf->anal.x_range, fdf->anal.y_range);
// 	max = fmax(fdf->map->width, fdf->map->height);
// 	printf ("max: %f, xy_range: %f\n", max, xy);
// 	if (xy < max * fdf->anal.density)
// 	{
// 		fdf->z_scale = (fdf->zoom / xy) * (fdf->anal.z_range / xy);
// 		if (fdf->z_scale > 10.0)
// 			fdf->z_scale = 10.0;
// 		else if (fdf->z_scale < 0.1)
// 			fdf->z_scale = 0.1;
// 	}
// 	else
// 		fdf->z_scale = 1.0;
// }

void	scale_map(t_fdf *fdf)
{
	double	xy;
	double	max;
	double	ratio;

	xy = fmax(fdf->anal.x_range, fdf->anal.y_range);
	max = fmax(fdf->map->width, fdf->map->height);
	ratio = xy / max;
	if (fdf->anal.z_range)
	{
		// scale = (xy / fdf->anal.z_range) * 0.1;
		fdf->z_scale = fdf->zoom / (xy * ratio) * 0.1;
		if (fdf->z_scale > 1.0)
			fdf->z_scale = 1.0;
		else if (fdf->z_scale < 0.1)
			fdf->z_scale = 0.5;
	}
	else
		fdf->z_scale = 1.0;
	printf("Calculated z_scale: %f\n", fdf->z_scale);
}