/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:04:14 by cooi              #+#    #+#             */
/*   Updated: 2023/11/21 22:22:35 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nb)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*nb == '\t' || *nb == '\n' || *nb == '\v'
		|| *nb == '\f' || *nb == '\r' || *nb == ' ')
		nb++;
	if (*nb == '-' || *nb == '+')
	{
		if (*nb == '-')
			sign = -1;
		nb++;
	}
	while ('0' <= *nb && *nb <= '9')
	{
		res = res * 10 + (*nb - '0');
		nb++;
	}
	return (res * sign);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
