/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 06:45:39 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/16 15:47:04 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 600
# define MIN_ZOOM 0.01
# define MOVE_STEP 0.00005

typedef struct t_key
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			zoom_in;
	int			zoom_out;
	int			esc;
}				t_key;

typedef struct t_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			bpp;
	int			linesize;
	int			endian;
	int			type;
	int			max_iter;
	t_key		key;
	double		zoom;
	double		offX;
	double		offY;
	double		c_real;
	double		c_img;
}				t_fractol;

typedef struct t_complex
{
	double		zx;
	double		zy;
	double		cx;
	double		cy;
}				t_complex;

typedef struct t_xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct t_cxy
{
	double		real;
	double		img;
}				t_cxy;


typedef void	(*init_f)(t_complex *cplx, t_xy *coords, t_fractol *fract);

/* ****************************** main_init ********************************* */
void			mndlbrt(t_complex *complex, t_xy *coords, t_fractol *fract);
void			julia(t_complex *complex, t_xy *coords, t_fractol *fract);
void			start_fractal(t_fractol *fractol, init_f init);
void			init_keys(t_fractol *frac);
/* **************************** event_handling ****************************** */
int				mouse(int button, int x, int y, t_fractol *frac);
t_cxy			coord_translate(double x, double y, t_fractol *frac);
int				key_press(int key, t_fractol *frac);
int				key_release(int key, t_fractol *frac);
void			update_key(int key, t_fractol *frac, int state);
void			process_key(t_fractol *f);
void			zoom(t_fractol *f, t_cxy before, double order);
/* ******************************* arg_proc ********************************** */
void			arg_handler(t_fractol *frac, int ac, char **av);
void			frac_parse(t_fractol *frac, char *str, int c, int i);
/* ****************************** draw_image ********************************* */
void			draw_fractal(t_fractol *frac, init_f init);
void			pxl_to_image(t_fractol *frac, int x, int y, int colour);
int				iter_frac(t_complex *cplx, t_fractol *frac, int *i);
int				itercolour(t_fractol *frac, int iteration);
/* ****************************** close_shop ********************************** */
int				close_shop(void);
#endif