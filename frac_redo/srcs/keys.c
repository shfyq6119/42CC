/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 05:14:44 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/28 16:48:46 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

int	key_press(int key, t_fractol *frac)
{
	update_key(key, frac, 1);
	process_key(frac);
	return (0);
}

int	key_release(int key, t_fractol *frac)
{
	update_key(key, frac, 0);
	process_key(frac);
	return (0);
}

void	update_key(int key, t_fractol *frac, int state)
{
	if (key == XK_Up)
		frac->key.up = state;
	else if (key == XK_Down)
		frac->key.down = state;
	else if (key == XK_Right)
		frac->key.right = state;
	else if (key == XK_Left)
		frac->key.left = state;
	else if (key == XK_plus || key == XK_equal)
		frac->key.zoom_in = state;
	else if (key == XK_minus)
		frac->key.zoom_out = state;
	else if (key == XK_Escape)
		frac->key.esc = state;
}
/*void	update_key(int key, t_fractol *frac, int state)
{
	if (key == 126)
		frac->key.up = state;
	else if (key == 125)
		frac->key.down = state;
	else if (key == 124)
		frac->key.right = state;
	else if (key == 123)
		frac->key.left = state;
	else if (key == 24)
		frac->key.zoom_in = state;
	else if (key == 27)
		frac->key.zoom_out = state;
	else if (key == 53)
		frac->key.esc = state;
}*/

void	process_key(t_fractol *f)
{
	t_cxy	coords;
	int		i;

	i = 0;
	coords.real = WIDTH / 2.0;
	coords.img = HEIGHT / 2.0;
	if (f->key.up)
		f->off_y -= (0.05 * f->zoom);
	if (f->key.down)
		f->off_y += (0.05 * f->zoom);
	if (f->key.left)
		f->off_x -= (0.05 * f->zoom);
	if (f->key.right)
		f->off_x += (0.05 * f->zoom);
	if (f->key.zoom_in)
		zoom(f, coords, ZOOM_IN);
	if (f->key.zoom_out)
		zoom(f, coords, ZOOM_OUT);
	if (f->key.esc)
		close_shop(f);
	if (f->type == 1)
		draw_fractal(f, julia, &i);
	else if (f->type == 2)
		draw_fractal(f, mndlbrt, &i);
}
