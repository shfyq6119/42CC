/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:04:51 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 18:59:16 by mm-isa           ###   ########.fr       */
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
