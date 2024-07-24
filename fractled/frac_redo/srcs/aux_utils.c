/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:26:00 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/28 17:00:19 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	frac_regen(t_fractol *f)
{
	void	*new;
	char	*new_data;

	new = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	new_data = mlx_get_data_addr(new, &f->bpp, &f->linesize, &f->endian);
	f->old = f->img;
	f->img = new;
	f->img_data = new_data;
}

void	frac_refresh(t_fractol *f)
{
	if (f->old)
		mlx_destroy_image(f->mlx, f->old);
	f->old = NULL;
}
