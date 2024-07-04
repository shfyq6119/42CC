/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:46:11 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/04 10:28:41 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	heads_up(int ac)
{
	if (ac != 2)
	{
		ft_putendl_fd("Usage: ./fdf <filename>", 2);
		exit(EXIT_SUCCESS);
	}
}

int	file_error(void)
{
	perror("open file error");
	return (0);
}

int	arg_handler(char *filename, int *w, int *h, t_map **map)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (file_error());
	if (!map_dimensions(fd, w, h))
	{
		close(fd);
		return (0);
	}
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (file_error());
	*map = readmap(fd, *w, *h);
	close(fd);
	if (!*map)
		return (0);
	return (1);
}

void	init_fdf(t_fdf *fdf)
{
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->map = NULL;
	fdf->zoom = 1.0;
	fdf->z_scale = 1.0;
	fdf->off_x = 0.0;
	fdf->off_y = 0.0;
	fdf->step = 1;
}
