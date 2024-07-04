/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:11:57 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/04 06:46:57 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*free_map(t_map *map)
{
	int	y;

	if (map->pts)
	{
		y = map->height;
		while (--y >= 0)
		{
			if (map->pts[y])
				free(map->pts[y]);
		}
		free(map->pts);
	}
	free(map);
	return (NULL);
}

int	close_shop(t_fdf *fdf)
{
	if (fdf->map)
		fdf->map = free_map(fdf->map);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
	{
		//mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	exit(0);
	return (0);
}
