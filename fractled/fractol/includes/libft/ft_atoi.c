/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:29:09 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/17 00:36:32 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *n)
{
	long	pol;
	long	res_long;

	pol = 1;
	res_long = 0;
	while (n && (*n == 32 || (*n >= 9 && *n <= 13)))
		n++;
	if (n && (*n == 45 || *n == 43))
	{
		if (*n == 45)
			pol *= -1;
		n++;
	}
	if (n && !(*n > 47 && *n < 58))
		return (0);
	while (n && *n > 47 && *n < 58)
	{
		res_long = res_long * 10 + (*n - 48);
		n++;
	}
	return (res_long * pol);
}
