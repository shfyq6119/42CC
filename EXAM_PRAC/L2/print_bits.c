/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 03:45:50 by mm-isa            #+#    #+#             */
/*   Updated: 2023/12/12 21:03:51 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char bit;
	while (i--)
	{
		bit = (octet >> i & 1) + 48;  // bit is used to store the bitshifted values
		write(1, &bit, 1);
	}		
}
