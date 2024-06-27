/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:26:00 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/27 18:33:05 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    destroy_old(t_fractol *f)
{
    if (f->old)
        mlx_destroy_image(f->mlx, f->old);
    f->old = f->img;
}
