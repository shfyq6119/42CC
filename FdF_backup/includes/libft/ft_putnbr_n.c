/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:37:01 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 19:00:48 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
