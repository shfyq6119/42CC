/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:54:22 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 19:00:39 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
