/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:54:22 by mm-isa            #+#    #+#             */
/*   Updated: 2023/10/06 15:34:03 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libprintf.h"

int	ft_puthex_n(unsigned long h, char *hexcase)
{
	if (h < 16)
		return (ft_putchar_n(hexcase[h]));
	return (ft_puthex_n(h / 16, hexcase) + ft_putchar_n(hexcase[h % 16]));
}
