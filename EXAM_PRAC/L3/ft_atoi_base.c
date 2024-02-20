/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:53:56 by mm-isa            #+#    #+#             */
/*   Updated: 2023/12/20 18:07:53 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	conv_base(char num, int base) 						// set hard limit with r_max
{
	int	r_max;
	if (base <= 10)
		r_max = base + 48; 								// for single digit, just find difference to ASCII '0' (i.e. 48)
	else
		r_max = base - 10 + 97; 						// else, logically is hex i.e. base 16x i.e. > 10d, so difference above 'a' + 10 = max 16
	if (num > 47 && num < 58 && num <= r_max)
		return (num - 48); 								// return for single digits if 10d;
	else if (num >= 'a' && num <= 'f' && num <= r_max)	// requires to_lower to convert to lowercase range
		return (10 + num - 97); 						// additional calcuation for bases above 10, double digits rep if hex etc;
	else
		return (-1); 									// not a convertible number, errornum.
}

char	to_lower(char c) //self-explanatory.
{
	if (c > 64 && c < 91)
		return (c + 32);
	return (c);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int r = 0; //result; starts from 0 to give start from ones place to next in magnitude.
	int p = 1; //polarity; for -ve numbers.
	int	d; //to find digit at current str pointer.
	while (*str == 32 || *str == 9) //ignore spaces
		str++;
	if (*str == '-') // only one '-'
	{
		p = -p;
		str++;
	}
	while ((d = conv_base(to_lower(*str), str_base)) >= 0) //checks what is the digit or value at current pointer, converts even if 0.
	{
		r = r * str_base; //increases magnitude in order according to base value.
		r = r + (d * p); // since int, next result is to multiply, not mod or divide; ADD on to prev value * polarity
		str++;		 // i.e. -ve + -ve = -ve. take note: there must be a conditional check for bases above 10? minus zero only for base 10: minus a + 10.
	}
	return (r);
}
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_atoi_base("19", 8));
}
