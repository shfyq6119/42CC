/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 21:52:54 by mm-isa            #+#    #+#             */
/*   Updated: 2024/01/24 17:57:42 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*unsigned char	reverse_bits(unsigned char octet)
{
	int i = 8;
	unsigned char	bitres = 0;
	while (i > 0)
	{
		bitres = bitres * 2 + (octet % 2); // mod 2 = only either 1 or 0;
		octet /= 2;							//THEN divide
		i--;								// binary placing = n = 128; 128 / 64 / 32 / 16 / 8 / 4 / 2 / 1
	}
	return (bitres);
}

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	r = 0;
	unsigned int	b = 8;
	while (b--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return (r);
}
*/


unsigned char	reverse_bits(unsigned char octet)     //numbers representable in 1 byte = 0 ~ 255 (8-bit numbers)
{													  //0000	1100 vs 0000 1011 
	unsigned char res = octet;
	res = (res & 0xF0) >> 4 | (res & 0x0F) << 4; //1111 0000 vs 0000 1111 (mask first THEN shift)
	res = (res & 0xCC) >> 2 | (res & 0x33) << 2; //1100 1100 vs 0011 0011 (mask first THEN shift)
	res = (res & 0xAA) >> 1 | (res & 0x55) << 1; //1010 1010 vs 0101 0101 (mask first THEN shift)
	return (res);
}
// F0 = 240, F = 15
// CC = 204, 33 = 51
// AA = 170, 55 = 85
#include <stdio.h>
int	main()
{
	printf("%d\n", reverse_bits(1));
}
