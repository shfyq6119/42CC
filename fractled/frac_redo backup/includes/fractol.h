/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 06:45:39 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/28 16:40:35 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>
//# include <X11/keysym.h>

# define WIDTH 400
# define HEIGHT 400
# define ZOOM_IN 0.85
# define ZOOM_OUT 1.05
# define ITER_MAX 1000

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
	void		*old;
	char		*img_data;
	int			bpp;
	int			linesize;
	int			endian;
	int			type;
	int			max_iter;
	t_key		key;
	double		zoom;
	double		off_x;
	double		off_y;
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

typedef void	(*t_func)(t_complex *cplx, t_cxy *coords, t_fractol *fract);

/* ****************************** main_init ********************************* */
void			mndlbrt(t_complex *complex, t_cxy *coords, t_fractol *fract);
void			julia(t_complex *complex, t_cxy *coords, t_fractol *fract);
void			start_fractal(t_fractol *fractol, t_func init);
void			init_keys(t_fractol *frac);
/* **************************** event_handling ****************************** */
int				mouse(int button, int x, int y, t_fractol *frac);
t_cxy			coord_translate(double x, double y, t_fractol *frac);
int				key_press(int key, t_fractol *frac);
int				key_release(int key, t_fractol *frac);
void			update_key(int key, t_fractol *frac, int state);
void			process_key(t_fractol *f);
void			zoom(t_fractol *f, t_cxy coords, double dir);
/* ******************************* arg_proc ********************************* */
void			arg_handler(t_fractol *frac, int ac, char **av);
void			frac_parse(t_fractol *frac, char *str, double c, double i);
void			suggestions(void);
/* ****************************** draw_image ******************************** */
void			draw_fractal(t_fractol *frac, t_func init, int *i);
void			frac_regen(t_fractol *f);
void			frac_refresh(t_fractol *f);
void			pxl_to_image(t_fractol *frac, int x, int y, int colour);
int				iter_frac(t_complex *cplx, t_fractol *frac, int *i);
int				itercolour(t_fractol *frac, int iteration);
/* ****************************** close_shop ******************************** */
int				close_shop(t_fractol *f);
#endif
