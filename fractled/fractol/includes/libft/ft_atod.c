/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:36:07 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/17 14:17:12 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_atold(char *s)
{
	long double	integer;
	long double	fraction;
	long double	sub;
	int		pol;

	integer = 0;
	fraction = 0;
	sub = 1;
	pol = 1;
	while ((s && *s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (s && (*s == 43 || *s == 45))
		if (*s++ == 45)
			pol = -pol;
	while (s && *s != 46 && *s)
		integer = (integer * 10) + (*s++ - 48);
	if (s && *s == 46)
		s++;
	while (s && *s)
	{
		sub /= 10;
		fraction = fraction + (*s++ - 48) * sub;
	}
	return (pol * (integer + fraction));
}
