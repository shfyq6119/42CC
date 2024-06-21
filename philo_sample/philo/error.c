/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:28:08 by cooi              #+#    #+#             */
/*   Updated: 2023/11/19 13:22:02 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_error(int i)
{
	if (i == 1)
	{
		printf("Invalid args! Try: ./philo philosophers time_death ");
		printf("time_eat time_sleep optional[minimum_times_eaten]\n");
		return (1);
	}
	else if (i == 2)
	{
		printf("Insufficient philosophers!\n");
		return (1);
	}
	else if (i == 3)
	{
		printf("Philosophers must eat at least once!\n");
		return (1);
	}
	else if (i == 4)
	{
		printf("Time must be at least 1!\n");
		return (1);
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (arg_error(1));
	if (ft_atoi(argv[1]) < 1)
		return (arg_error(2));
	if (argc == 6 && ft_atoi(argv[5]) < 0)
		return (arg_error(3));
	i = 1;
	while (i < argc && i < 5)
	{
		if (!ft_isdigit(argv[i][0]) && ft_atoi(argv[i]) < 1)
			return (arg_error(4));
		i++;
	}
	return (0);
}
