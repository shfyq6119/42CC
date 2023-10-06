/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:37:01 by mm-isa            #+#    #+#             */
/*   Updated: 2023/10/06 15:34:23 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libprintf.h"

int	ft_putnbr_n(long i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		i = -i;
		count += ft_putchar_n(45);
	}
	if (i > 9)
	{
		count += ft_putnbr_n(i / 10);
		count += ft_putnbr_n(i % 10);
	}
	else
		count += ft_putchar_n(i + 48);
	return (count);
}
