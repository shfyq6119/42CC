/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:06:00 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/16 17:11:26 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	iter_frac(t_complex *cplx, t_fractol *frac, int *i)
{
	double	tmp;

	tmp = (cplx->zx * cplx->zx) - (cplx->zy * cplx->zy) + cplx->cx;
	while ((cplx->zx * cplx->zx) + (cplx->zy * cplx->zy) < 4
		&& *i < frac->max_iter)
	{
		tmp = (cplx->zx * cplx->zx) - (cplx->zy * cplx->zy) + cplx->cx;
		cplx->zy = 2 * cplx->zx * cplx->zy + cplx->cy;
		cplx->zx = tmp;
		(*i)++;
	}
	return (*i);
}

int	itercolour(t_fractol *frac, int iteration)
{
	int	colour;

	colour = 0x000000;
	if (colour == frac->max_iter)
		colour = 0x000000;
	else
	{
		colour = (iteration * 255 / frac->max_iter) << 16
			| (iteration * 255 / frac->max_iter) << 8
			| (iteration * 255 / frac->max_iter);
	
	}
	return (colour);
}

int	mouse(int button, int x, int y, t_fractol *frac)
{
	t_cxy	before;
	t_cxy	after;
	double	zfactor;

	before = coord_translate((double)x, (double)y, frac);
	if (button == 4 || button == 5)
	{
		if (button == 4)
			zfactor = 1.11;
		else
			zfactor = 0.9;
		frac->zoom *= zfactor;
		after = coord_translate((double)x, (double)y, frac);
		frac->offX += before.real - after.real;
		frac->offY += before.img - after.img;
		if (frac->type == 1)
			draw_fractal(frac, julia);
		else if (frac->type == 2)
			draw_fractal(frac, mndlbrt);
	}
	return (0);
}

t_cxy	coord_translate(double x, double y, t_fractol *f)
{
	t_cxy	cxy;

	cxy.real = (x - WIDTH / 2.0) / (WIDTH / 2.0) * (f->zoom * 2.0) + f->offX;
	cxy.img = (y - HEIGHT / 2.0) / (HEIGHT / 2.0) * (f->zoom * 2.0) + f->offY;
	return (cxy);
}
