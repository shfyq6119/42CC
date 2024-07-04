/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:36:07 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/21 12:54:20 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(char *s)
{
	double	integer;
	double	fraction;
	double	sub;
	int		pol;

	integer = 0;
	fraction = 0;
	sub = 1;
	pol = 1;
	while (s && ((*s >= 9 && *s <= 13) || *s == 32))
		s++;
	while (s && (*s == 43 || *s == 45))
		if (*s++ == 45)
			pol *= -1;
	while (s && *s != 46 && ft_isdigit((int)*s))
		integer = (integer * 10) + (*s++ - 48);
	if (s && *s == 46)
		s++;
	while (s && ft_isdigit((int)*s))
	{
		sub /= 10;
		fraction = fraction + (*s++ - 48) * sub;
	}
	return (pol * (integer + fraction));
}
