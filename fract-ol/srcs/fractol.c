/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 06:45:44 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/02 19:05:49 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_shop(t_fractol *f)
{
	if (f->img)
	{
		mlx_destroy_image(f->mlx, f->img);
		f->img = NULL;
	}
	if (f->win)
	{
		mlx_destroy_window(f->mlx, f->win);
		f->win = NULL;
	}
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
		f->mlx = NULL;
	}
	exit(0);
}

void	start_fractal(t_fractol *f, t_func init)
{
	int	i;

	i = 0;
	f->old = NULL;
	f->img = NULL;
	frac_regen(f);
	draw_fractal(f, init, &i);
	mlx_hook(f->win, 2, 1L << 0, key_press, f);
	mlx_hook(f->win, 3, 1L << 1, key_release, f);
	mlx_mouse_hook(f->win, mouse, f);
	mlx_hook(f->win, 17, 0, (int (*)())close_shop, f);
	mlx_loop(f->mlx);
}

void	frac_parse(t_fractol *frac, char *str, double comp, double img)
{
	frac->off_y = 0.0;
	frac->max_iter = 100;
	if (!ft_memcmp(str, "julia", 5))
	{
		frac->zoom = 1.157;
		frac->off_x = 0.0;
		frac->type = 1;
		frac->c_real = comp;
		frac->c_img = img;
	}
	else if (!ft_memcmp(str, "mandelbrot", 10))
	{
		frac->zoom = 1.0;
		frac->off_x = -0.5;
		frac->type = 2;
		frac->c_real = 0;
		frac->c_img = 0;
	}
}

void	arg_handler(t_fractol *frac, int ac, char **av)
{
	char	**str;

	str = NULL;
	if (ac == 2)
		str = ft_split(av[1], ' ');
	else if (ac == 4)
		str = &av[1];
	if (str && *str && !ft_strncmp(str[0], "mandelbrot", 11))
		frac_parse(frac, *str, 0, 0);
	else if (str && *str && !ft_strncmp(str[0], "julia", 6))
	{
		if (!ft_isdouble(str[1]) || !ft_isdouble(str[2]))
			suggestions(&ac, str);
		if (ft_isdouble(str[1]) && ft_isdouble(str[2]))
			frac_parse(frac, *str, ft_atod(str[1]), ft_atod(str[2]));
	}
	else
		suggestions(&ac, str);
	if (str != &av[1])
		ft_free((void **)str);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac == 1 || ac == 3 || ac > 4)
	{
		suggestions(NULL, NULL);
		return (1);
	}
	arg_handler(&fractol, ac, av);
	init_keys(&fractol);
	fractol.mlx = mlx_init();
	if (!fractol.mlx)
		return (1);
	fractol.win = mlx_new_window(fractol.mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!fractol.win)
		return (1);
	if (fractol.type == 1)
		start_fractal(&fractol, julia);
	else if (fractol.type == 2)
		start_fractal(&fractol, mndlbrt);
}
