/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:06:00 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/17 14:33:05 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	iter_frac(t_complex *cplx, t_fractol *frac, int *i)
{
	long double	tmp;
	long double	zx2;
	long double	zy2;

	tmp = (cplx->zx * cplx->zx) - (cplx->zy * cplx->zy) + cplx->cx;
	zx2 = cplx->zx * cplx->zx;
	zy2 = cplx->zy * cplx->zy;
	while (zx2 + zy2 < 4 && *i < frac->max_iter)
	{
		tmp = (cplx->zx * cplx->zx) - (cplx->zy * cplx->zy) + cplx->cx;
		cplx->zy = 2 * cplx->zx * cplx->zy + cplx->cy;
		zx2 = cplx->zx * cplx->zx;
		zy2 = cplx->zy * cplx->zy;
		cplx->zx = tmp;
		(*i)++;
	}
	return (*i);
}

int	itercolour(t_fractol *frac, int iteration)
{
	double	ratio;
	int		r;
	int		g;
	int		b;

	if (iteration == frac->max_iter)
		return (0x000000);
	ratio = (double)iteration / (double)frac->max_iter;
	r = (int)(9 * (1 - ratio) * pow(ratio, 3) * 255);
	g = (int)(15 * pow((1 - ratio), 2) * pow(ratio, 2) * 255);
	b = (int)(8.5 * pow((1 - ratio), 3) * ratio * 255);
	return ((r << 16) | (g << 8) | b);
}

// int	itercolour(t_fractol *frac, int iteration, long double zx,
//		long double zy)
// {
// 	int		red;
// 	int		green;
// 	int		blue;
// 	double	log_zn;
// 	double	nu;

// 	if (iteration == frac->max_iter)
// 		return (0x000000);
// 	log_zn = log(zx * zx + zy * zy) / 2.0;
// 	nu = log(log_zn / log(2)) / log(2);
// 	iteration = iteration + 1 - nu;
// 	red = (int)(sin(0.016 * iteration + 4) * 230 + 25);
// 	green = (int)(sin(0.013 * iteration + 2) * 230 + 25);
// 	blue = (int)(sin(0.01 * iteration + 1) * 230 + 25);
// 	return (red << 16 | green << 8 | blue);
// }

int	mouse(int button, int x, int y, t_fractol *frac)
{
	t_cxy	coords;

	coords.real = (double)x;
	coords.img = (double)y;
	if (button == 4)
		zoom(frac, coords, ZOOM_IN);
	else if (button == 5)
		zoom(frac, coords, ZOOM_OUT);
	if (frac->type == 1)
		draw_fractal(frac, julia);
	else if (frac->type == 2)
		draw_fractal(frac, mndlbrt);
	return (0);
}

t_cxy	coord_translate(long double x, long double y, t_fractol *f)
{
	t_cxy	cxy;

	cxy.real = (x - WIDTH / 2.0) / (WIDTH / 2.0) * (f->zoom) + f->off_x;
	cxy.img = (y - HEIGHT / 2.0) / (HEIGHT / 2.0) * (f->zoom) + f->off_y;
	return (cxy);
}

void	zoom(t_fractol *f, t_cxy coords, long double dir)
{
	t_cxy	before;
	t_cxy	after;

	before = coord_translate(coords.real, coords.img, f);
	f->zoom *= dir;
	after = coord_translate(coords.real, coords.img, f);
	f->off_x += before.real - after.real;
	f->off_y += before.img - after.img;
}
