/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:43:49 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/16 16:14:40 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_fractal(t_fractol *frac, init_f init)
{
	int			x;
	int			y;
	int			i;
	t_complex	cplx;
	t_xy		coords;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			i = 0;
			coords.x = x;
			coords.y = y;
			init(&cplx, &coords, frac);
			pxl_to_image(frac, x, y, itercolour(frac, iter_frac(&cplx, frac,
						&i)));
			x++;
		}
		y++;
		printf("x = %d, y = %d\n", x, y);
	}
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 0, 0);
}

void	pxl_to_image(t_fractol *frac, int x, int y, int colour)
{
	int	idx;

	idx = (x * (frac->bpp / 8)) + (y * frac->linesize);
	frac->img_data[idx] = colour;
	frac->img_data[idx + 1] = colour >> 8;
	frac->img_data[idx + 2] = colour >> 16;
}

void	julia(t_complex *cplx, t_xy *coords, t_fractol *frac)
{
	t_cxy cxy;
	
	cxy = coord_translate((double)coords->x, (double)coords->y, frac);
	cplx->zx = cxy.real;
	cplx->zy = cxy.img;
	cplx->cx = frac->c_real;
	cplx->cy = frac->c_img;
}

void	mndlbrt(t_complex *cplx, t_xy *coords, t_fractol *frac)
{
	t_cxy cxy;
	
	cxy = coord_translate((double)coords->x, (double)coords->y, frac);
	cplx->cx = cxy.real;
	cplx->cy = cxy.img;
	cplx->zx = 0;
	cplx->zy = 0;
}

void	init_keys(t_fractol *frac)
{
	frac->key.up = 0;
	frac->key.down = 0;
	frac->key.left = 0;
	frac->key.right = 0;
	frac->key.zoom_in = 0;
	frac->key.zoom_out = 0;
	frac->key.esc = 0;
}
