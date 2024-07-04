/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:33:19 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/04 06:47:01 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	map_dimensions(int fd, int *w, int *h)
{
	int		cur_w;
	char	*line;

	*h = 0;
	*w = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd, line);
		if (!line)
			break;
		cur_w = ft_wordcount(line, ' ');
		if (cur_w > *w)
			*w = cur_w;
		(*h)++;
		free(line);
		line = NULL;
	}
	return (1);
}

t_map	*readmap(int fd, int w, int h)
{
	int		y;
	char	*line;
	t_map	*map;

	map = init_map(w, h);
	if (!map)
		return (NULL);
	y = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd, line);
		if (!line)
			break;
		if (!parse_line(line, map, y))
		{
			free(line);
			return (free_map(map));
		}
		free(line);
		line = NULL;
		y++;
	}
	return (map);
}

int	parse_line(char *line, t_map *map, int y)
{
	int		x;
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return (0);
	x = 0;
	while (split[x])
	{
		map->pts[y][x].x = (double)x;
		map->pts[y][x].y = (double)y;
		map->pts[y][x].z = (double)ft_atoi(split[x]);
		free(split[x]);
		x++;
	}
	free(split);
	return (1);
}

t_map	*init_map(int w, int h)
{
	t_map	*map;
	int		y;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = w;
	map->height = h;
	map->pts = (t_point **)malloc(sizeof(t_point *) * h);
	if (!map->pts)
		return (free_map(map));
	y = 0;
	while (y < h)
	{
		map->pts[y] = (t_point *)malloc(sizeof(t_point) * w);
		if (!map->pts[y])
				return (free_map(map));
		y++;
	}
	return (map);
}
