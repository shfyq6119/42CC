/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 03:45:50 by mm-isa            #+#    #+#             */
/*   Updated: 2024/01/30 21:42:53 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char bit;
	while (i--)						  //track backwards from least sig to most sig bit
	{
		bit = (octet >> i & 1) + 48;  // bit is used to store the bitshifted values
		write(1, &bit, 1);			  // shift to least sig bit AND 1 to check if 1 or 0, convert to int (+48)
	}		
}
