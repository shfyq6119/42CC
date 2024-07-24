/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 05:14:44 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/16 16:09:46 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_press(int key, t_fractol *frac)
{
	    printf("Key Pressed: %d\n", key); 
	update_key(key, frac, 1);
	process_key(frac);
	return (0);
}

int	key_release(int key, t_fractol *frac)
{
	printf("Key Released: %d\n", key);
	update_key(key, frac, 0);
	process_key(frac);
	return (0);
}

void update_key(int key, t_fractol *frac, int state)
{
	  printf("Updating Key: %d, State: %d\n", key, state);
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
	   printf("Key States -> Up: %d, Down: %d, Left: %d, Right: %d, Zoom In: %d, Zoom Out: %d, ESC: %d\n", frac->key.up, frac->key.down, frac->key.left, frac->key.right,
           frac->key.zoom_in, frac->key.zoom_out, frac->key.esc);
}

void	process_key(t_fractol *f)
{
	t_cxy	before;

	printf("Processing Key\n"); // Debug print
	before = coord_translate(WIDTH / 2.0, HEIGHT / 2.0, f);
	if (f->key.up)
		f->offY -= MOVE_STEP / (f->zoom * 2);
	if (f->key.down)
		f->offY += MOVE_STEP / (f->zoom * 2);
	if (f->key.left)
		f->offX -= MOVE_STEP / (f->zoom * 2);
	if (f->key.right)
		f->offX += MOVE_STEP / (f->zoom * 2);
	if (f->key.zoom_in)
		zoom(f, before, 1.1);
	if (f->key.zoom_out)
		zoom(f, before, 0.9);
	if (f->key.esc)
		close_shop();
	if (f->type == 1)
		draw_fractal(f, julia);
	else if (f->type == 2)
		draw_fractal(f, mndlbrt);
}

void	zoom(t_fractol *f, t_cxy before, double order)
{
	t_cxy	after;

	(f->zoom) *= order;
	after = coord_translate(WIDTH / 2.0, HEIGHT / 2.0, f);
	f->offX += before.real - after.real;
	f->offY += before.img - after.img;
	if (f->type ==1)
		draw_fractal(f, julia);
	else if (f->type == 2)
		draw_fractal(f, mndlbrt);
}