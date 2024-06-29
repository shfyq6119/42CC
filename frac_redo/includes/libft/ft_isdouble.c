/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:04:51 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/09 13:30:53 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdouble(char *str)
{
	int	dot;
	int	digit;

	dot = 0;
	digit = 0;
	while (str && *str == ' ')
		str++;
	if (str && (*str == '+' || *str == '-'))
		str++;
	while (str && *str)
	{
		if (*str == '.')
		{
			if (dot)
				return (0);
			dot = 1;
		}
		else if (!ft_isdigit(*str))
			return (0);
		else
			digit = 1;
		str++;
	}
	return (digit);
}
