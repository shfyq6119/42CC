/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:53:56 by mm-isa            #+#    #+#             */
/*   Updated: 2023/12/13 03:45:28 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	conv_base(char num, int base)
{
	int	r_max;
	if (r_max <= 10)
		r_max = base - 48;
	else
		r_max = base - 10 + 97;
	if (num > 47 && num < 58 && num <= r_max)
		return (num - 48);
	else if (num >= 97 && num <= 102 && num <= r_max)
		return (10 + num - 97);
	else
		return (-1);
}

char	to_lower(char c)
{
	if (c > 64 && c < 91)
		return (c + 32);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int r = 0;
	int p = 1;
	int	d;
	while (*str == 32 || *str == 9)
		str++;
	if (*str == '-')
	{
		p = -p;
		str++;
	}
	while ((d = conv_base(to_lower(*str), str_base)) >= 0)
	{
		r = r * str_base;
		r = r + (d * p);
		str++;
	}
	return (r);
}
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_atoi_base("123abc", 16));
}
