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
	double	tmp;
	double	zxsq;
	double	zysq;

	tmp = (cplx->zx * cplx->zx) - (cplx->zy * cplx->zy) + cplx->cx;
	zxsq = cplx->zx * cplx->zx;
	zysq = cplx->zy * cplx->zy;
	while (zxsq + zysq < 4 && *i < frac->max_iter)
	{
		tmp = zxsq - zysq + cplx->cx;
		cplx->zy = 2 * cplx->zx * cplx->zy + cplx->cy;
		cplx->zx = tmp;
		zxsq = cplx->zx * cplx->zx;
		zysq = cplx->zy * cplx->zy;
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

int	mouse(int button, int x, int y, t_fractol *frac)
{
	t_cxy	coords;
	int		i;

	i = 0;
	coords.real = (double)x;
	coords.img = (double)y;
	if (button == 5)
		zoom(frac, coords, ZOOM_IN);
	else if (button == 4)
		zoom(frac, coords, ZOOM_OUT);
	if (frac->type == 1)
		draw_fractal(frac, julia, &i);
	else if (frac->type == 2)
		draw_fractal(frac, mndlbrt, &i);
	return (0);
}

t_cxy	coord_translate(double x, double y, t_fractol *f)
{
	t_cxy	cxy;
	double	halfw;
	double	halfh;

	halfw = WIDTH / 2.0;
	halfh = HEIGHT / 2.0;
	cxy.real = (x - halfw) / halfw * f->zoom + f->off_x;
	cxy.img = (y - halfh) / halfh * f->zoom + f->off_y;
	return (cxy);
}

void	zoom(t_fractol *f, t_cxy coords, double dir)
{
	t_cxy	before;
	t_cxy	after;

	before = coord_translate(coords.real, coords.img, f);
	f->zoom *= dir;
	after = coord_translate(coords.real, coords.img, f);
	f->off_x += before.real - after.real;
	f->off_y += before.img - after.img;
	f->max_iter += 10;
	if (f->max_iter > ITER_MAX)
		f->max_iter = ITER_MAX;
}
