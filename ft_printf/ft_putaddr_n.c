/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:52:32 by mm-isa            #+#    #+#             */
/*   Updated: 2023/10/06 16:21:11 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putaddr_n(unsigned long p)
{
	if (!p)
		return (ft_putstr_n("(nil)"));
/*	if (p >= LONG_MAX)
		return(ft_putstr_n("0x") + ft_puthex_n(UINT_MAX, HEXLOW));*/
	return (ft_putstr_n("0x") + ft_puthex_n(p, HEXLOW));
}
