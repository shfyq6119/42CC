/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:54:22 by mm-isa            #+#    #+#             */
/*   Updated: 2023/10/07 12:08:59 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex_n(unsigned long h, char *hexcase)
{
	int	tally;

	tally = 0;
	if (h < 16)
		return (ft_putchar_n(hexcase[h]));
	else
		tally += ft_puthex_n(h / 16, hexcase) + ft_putchar_n(hexcase[h % 16]);
	return (tally);
}
