/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:43:49 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/28 15:55:53 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_fractal(t_fractol *frac, t_func init, int *i)
{
	int			x;
	int			y;
	int			colour;
	t_complex	cplx;
	t_cxy		coords;

	y = 0;
	frac_regen(frac);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			*i = 0;
			coords.real = (double)x;
			coords.img = (double)y;
			init(&cplx, &coords, frac);
			colour = itercolour(frac, iter_frac(&cplx, frac, i));
			pxl_to_image(frac, x, y, colour);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 0, 0);
	frac_refresh(frac);
}

void	pxl_to_image(t_fractol *frac, int x, int y, int colour)
{
	int	idx;

	idx = (x * (frac->bpp / 8)) + (y * frac->linesize);
	frac->img_data[idx] = colour;
	frac->img_data[idx + 1] = colour >> 8;
	frac->img_data[idx + 2] = colour >> 16;
}

void	julia(t_complex *cplx, t_cxy *coords, t_fractol *frac)
{
	t_cxy	cxy;

	cxy = coord_translate(coords->real, coords->img, frac);
	cplx->zx = cxy.real;
	cplx->zy = cxy.img;
	cplx->cx = frac->c_real;
	cplx->cy = frac->c_img;
}

void	mndlbrt(t_complex *cplx, t_cxy *coords, t_fractol *frac)
{
	t_cxy	cxy;

	cxy = coord_translate(coords->real, coords->img, frac);
	cplx->cx = cxy.real;
	cplx->cy = cxy.img;
	cplx->zx = 0;
	cplx->zy = 0;
}

void	suggestions(int *ac, char **str)
{
	if (ac && *ac == 2 && str)
		ft_free((void **)str);
	ft_printf("\nUsage: ./fractol <type> [real] [imaginary], OR '' ''\n");
	ft_printf("E.g.: ./fractol ''<type> [real] [imaginary]''\n\n");
	ft_printf("fracs available: julia, mandelbrot\n");
	ft_printf("IF ./fractol <mandelbrot>; no numbers will be passed in.\n");
	ft_printf("1.	Classic Julia Set: Real: -0.7 Img: 0.27015,\n");
	ft_printf("2.	Douady's Rabbit: Real: -0.123 Img: 0.745\n");
	ft_printf("3.	San Marco Dragon: Real: -0.75 Img: 0.11\n");
	ft_printf("4.	Siegel Disk: Real: -0.391 Img: -0.587\n");
	ft_printf("5.	Spiral: Real: -0.4 Img: 0.6\n");
	exit(EXIT_SUCCESS);
}
