/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 06:45:44 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/16 17:10:01 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_shop(void)
{
	printf("Exiting program.\n");
	exit (0);
	return (0);
}

void	start_fractal(t_fractol *f, init_f init)
{
	 printf("Starting fractal\n");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->img_data = mlx_get_data_addr(f->img, &f->bpp, &f->linesize, &f->endian);
	draw_fractal(f, init);
	mlx_hook(f->win, 2, 1L<<0, key_press, f);
	mlx_hook(f->win, 3, 1L<<1, key_release, f);
	mlx_mouse_hook(f->win, mouse, f);
	mlx_hook(f->win, 17, 0, close_shop, f);
	  printf("Entering mlx_loop\n");
	mlx_loop(f->mlx);
}

void	frac_parse(t_fractol *frac, char *str, int c, int i)
{
		frac->zoom = 1.0;
		frac->offX = 0;
		frac->offY = 0.0;
		frac->max_iter = 100;
		if (!ft_memcmp(str, "julia", 5))
		{
			frac->type = 1;
			frac->c_real = c;
			frac->c_img = i;
			if (c == 0 && i == 0)
			{
				frac->c_real = -0.7;
				frac->c_img = 0.27015;
			}
		}
		else if (!ft_memcmp(str, "mandelbrot", 10))
		{
			frac->type = 2;
			frac->c_real = 0;
			frac->c_img = 0;
		}
		else
			frac->type = 0;
}

void	arg_handler(t_fractol *frac, int ac, char **av)
{
	char	**str;

	str = NULL;
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		if (!ft_memcmp(*str, "mandelbrot", 10) || !ft_memcmp(*str, "julia", 5))
		{	
			if (str[1] && str[2])
				frac_parse(frac, *str, ft_atoi(str[1]), ft_atoi(str[2]));
			else
				frac_parse (frac, *str, 0, 0);
		}
		ft_free((void **)str);
	}
	else if (ac == 4)
	{
		if (!ft_memcmp(av[1], "mandelbrot", 10) || !ft_memcmp(av[1], "julia", 5))
			frac_parse(frac, av[1], ft_atoi(av[2]), ft_atoi(av[3]));
	}
	else
		frac->type = 0;
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.mlx = mlx_init();
	if (!fractol.mlx)
		return (1);
	fractol.win = mlx_new_window(fractol.mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!fractol.win)
		return (1);
	init_keys(&fractol);
	arg_handler(&fractol, ac, av);
	printf("fractype: %d\n", fractol.type);
	if (fractol.type == 1)
		start_fractal(&fractol, julia);
	else if (fractol.type == 2)
		start_fractal(&fractol, mndlbrt);
	else
	{
		ft_printf("Usage: ./fractol: <type> [real] [imaginary], OR " "\n");
		ft_printf("fracs available: julia, mandelbrot\n");
		return (1);
	}
	mlx_destroy_window(fractol.mlx, fractol.win);
	return (0);
}
