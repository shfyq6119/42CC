/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:06:01 by mm-isa            #+#    #+#             */
/*   Updated: 2024/05/17 17:25:26 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	inting_check(int count, char **arglist)
{
	int	i;
	int	j;

	i = 1;
	while (i < count)
	{
		j = 0;
		if (arglist[i][j] == 0)
			handle_error();
		while (j < (int)ft_strlen(arglist[i]))
		{
			if (j == 0 && (arglist[i][j] == 43 || arglist[i][j] == 45)
				&& (int)ft_strlen(arglist[i]) != 1)
			{
				j++;
				continue ;
			}
			if (!ft_isdigit(arglist[i][j]))
				handle_error();
			j++;
		}
		i++;
	}
}

int	ft_atoi_lbrk(char *str)
{
	int		pol;
	long	res;

	pol = 1;
	res = 0;
	while (*str == 9 || *str == 10 || *str == 11 || *str == 12
		|| *str == 13 || *str == 32)
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			pol = -pol;
		str++;
	}
	while (*str)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if ((pol * res) > INT_MAX || (pol * res) < INT_MIN)
		handle_error();
	return (pol * res);
}

void dupcheck(int ac, char **av)
{
	int	i;
	int	j;
	
	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi_lbrk(av[i]) == ft_atoi_lbrk(av[j]))
				handle_error();
			j++;
		}
		i++;
	}
}

void	argcheck(int ac, char **av)
{
	if (ac <= 2)
		handle_error();
	inting_check(ac, av);
	dupcheck(ac, av);
}
