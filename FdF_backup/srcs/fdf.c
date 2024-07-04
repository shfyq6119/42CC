/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:25:00 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/04 08:21:28 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int expose_hook(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_map(fdf);
	return (0);
}

int	key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	// printf("Key pressed: %d\n", key);
	if (key == ESC)
		return (close_shop(fdf));
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
	{
		move_map(key, fdf);
		// printf("Arrow key pressed. Moving map.\n");
	}
	if (key == PLUS || key == MINUS)
	{
		zoom_map(key, fdf);
		// printf("Zoom key pressed. zooming map.\n");
	}
	return (0);
}

int	key_release(int key, void *param)
{
	(void)key;
	(void)param;
	return (0);
}

void	orientate_map(t_fdf *fdf)
{
	int		center_x;
	int		center_y;
	double	width;
	double	height;
	t_point	center_point;

	width = 800.0;
	height = 600.0;
	fdf->zoom = fmin(width / (double)fdf->map->width, height
			/ (double)fdf->map->height) * 0.8;
	if (fdf->zoom > ZOOM_MAX)
		fdf->zoom = ZOOM_MAX;
	check_map(fdf, &(fdf->anal));
	scale_map(fdf);
	center_x = (fdf->map->width - 1) / 2;
	center_y = (fdf->map->height - 1) / 2;
	center_point = project(fdf, (double)center_x, (double)center_y, 0);
	fdf->off_x = (width / 2) - center_point.x;
	fdf->off_y = (height / 2) - center_point.y;
	printf("Zoom: %.2f, Z-Scale: %.2f\n", fdf->zoom, fdf->z_scale);
    printf("Center Point: (%.2f, %.2f)\n", center_point.x, center_point.y);
    printf("Offsets: (off_x: %.2f, off_y: %.2f)\n", fdf->off_x, fdf->off_y);

}

int	main(int ac, char **av)
{
	t_fdf	fdf;
	t_map	*map;
	int		w;
	int		h;

	w = 0;
	h = 0;
	heads_up(ac);
	init_fdf(&fdf);
	if (!arg_handler(av[1], &w, &h, &map))
		return (1);
	fdf.map = map;
	orientate_map(&fdf);
	fdf.mlx = mlx_init();
	if (!fdf.mlx)
		return (1);
	fdf.win = mlx_new_window(fdf.mlx, 800, 600, "FdF");
	if (!fdf.win)
		return (1);
	mlx_hook(fdf.win, 2, 1L << 0, key_press, &fdf);
	mlx_hook(fdf.win, 3, 1L << 1, key_release, &fdf);
	mlx_hook(fdf.win, 12, 0, expose_hook, &fdf);
	mlx_hook(fdf.win, 17, 0, close_shop, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
