/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:52:32 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 19:00:23 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putaddr_n(unsigned long p)
{
	int	tally;

	tally = 0;
	if (!p)
		return (ft_putstr_n("(nil)"));
	else
		tally += ft_putstr_n("0x") + ft_puthex_n(p, HEXLOW);
	return (tally);
}
