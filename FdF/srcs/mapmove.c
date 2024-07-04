/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:06:10 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/04 10:28:42 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom_map(int key, t_fdf *fdf)
{
	// printf("entered zoom\n");
	if (key == PLUS)
		fdf->zoom -= 1;
	else if (key == MINUS)
		fdf->zoom += 1;
	if (fdf->zoom < 1)
		fdf->zoom = 1;
	expose_hook(fdf);
}

void	move_map(int key, t_fdf *fdf)
{
	// printf("entered move\n");
	if (key == UP)
		fdf->off_y += 10;
	if (key == DOWN)
		fdf->off_y -= 10;
	if (key == LEFT)
		fdf->off_x += 10;
	if (key == RIGHT)
		fdf->off_x -= 10;		
	expose_hook(fdf);				
}