/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:31:08 by mm-isa            #+#    #+#             */
/*   Updated: 2024/04/20 16:54:06 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

t_stack	*stackparse(int ac, char **av)
{
	t_stack	*a;
	char	**str;
	int		i;

	i = 1;
	if (ac == 2)
	{
		str = ft_split(av[i], ' ');
		if (!str)
			handle_error();
		a = hairsplitter(i - 1, str);
		freethe(str);
	}
	else
	{
		if (!inting_check(i, av) || !dupcheck(i, av))
			handle_error();
		a = ft_stack_new(ft_atoi_lbrk(av[i]));
		while (++i < ac)
			ft_stk_add_last(&a, ft_stack_new(ft_atoi_lbrk(av[i])));
	}
	return (a);
}

int	inting_check(int start, char **arglist)
{
	int	i;
	int	j;

	i = start;
	while (arglist[i])
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_lbrk(char *str)
{
	int		pol;
	long	res;

	pol = 1;
	res = 0;
	while ((*str == 9 || *str == 10 || *str == 11 || *str == 12 || *str == 13
		|| *str == 32))
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

int	dupcheck(int start, char **av)
{
	int	i;
	int	j;

	i = start;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi_lbrk(av[i]) == ft_atoi_lbrk(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_stack	*hairsplitter(int start, char **str)
{
	t_stack	*a;
	int		ac;

	a = NULL;
	ac = start;
	while (str[ac])
		ac++;
	if (!inting_check(start, str) || !dupcheck(start, str))
	{
		freethe(str);
		handle_error();
	}
	a = ft_stack_new(ft_atoi_lbrk(str[start]));
	while (++start < ac)
		ft_stk_add_last(&a, ft_stack_new(ft_atoi_lbrk(str[start])));
	return (a);
}
