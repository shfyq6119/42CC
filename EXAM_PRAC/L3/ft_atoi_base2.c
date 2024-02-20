/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:31:44 by mm-isa            #+#    #+#             */
/*   Updated: 2024/01/01 21:25:05 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	conv_base(char nb, int base)		//conv to dec i.e. after *= base, + str[i] - 0, or 'a' if hex (>= 10)
{										//
	int	radix_max;						//important to limit number within the radix.
	if (base <= 10)						//for base binary thru dec.
		radix_max = base + 48;			//add onto zero to get radix max value from 0 to base
	else								//for anything else above 10 i.e. <= 16
		radix_max = base - 10 + 97;		// get max radix for hex and below i.e. + a - 10 (a thru <= f)
	if (nb >= '0' && nb <= '9' && nb < radix_max)	// if base 4, radix_max will be 3 
		return (nb - '0');				// return difference to '0' for dec base or less.
	if (nb >= 'a' && nb <= 'f' && nb < radix_max) //if hex,
		return (nb + 10 - 'a');			//+10 - 'a'(97) since any letters encountered = >= 10 in dec.
	else
		return (-1);					//error handling; if none of the above,
}										// not an expected number, return (-1).

int	to_lower(char c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	return (c);
}

int	ft_atoi_base(const char *nbr, unsigned int base)
{
	int	r = 0;
	int p = 1;
	int i = 0;
	int d;
	while (nbr[i] == 32 || nbr[i] == 9)
		i++;
	if (nbr[i] == '-')
	{
		p = -p;
		i++;
	}
	while ((d = conv_base(to_lower(nbr[i]), base)) >= 0)
	{
		r *= base;		 //where dec=10, oct=8, hex=10, bin=2 etc...order of magnitude from 1 to n to n^2 etc...
		r += d * p; //where d == str[i] - '0' or 'a';
		i++;
	}
	return (r);
}
#include <stdio.h>
int main()
{
	printf("%d\n", ft_atoi_base("80000002", 16));
	return(0);
}
