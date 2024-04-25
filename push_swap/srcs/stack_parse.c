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

int	ft_atoi_nbrk(char *str)
{
	int			pol;
	long long	res;

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
		if (!ft_isdigit(*str))
			handle_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((pol * res) > INT_MAX || (pol * res) < INT_MIN - 1)
		handle_error();
	return (pol * res);
}

t_stack	*ft_stacksplitter(char **str)
{
	char	**parse;
	t_stack	*a;
	int		i;
	int		j;

	a = NULL;
	parse = ft_split(*str[i], ' ');
	i = -1;
	while (parse[++i])
	{
		j = ft_atoi_nbrk(parse[i]);
		ft_stk_add_last(&a, ft_stk_new(j));
	}
	free_array(parse);
	return (a);
}

void	check_args(int count)
{
	if (count < 2)
		handle_error();
	if (count == 2)
		ft_stacksplitter(av);
}

t_stack	*stackparse(int ac, char **av)
{
	int		i;
	int		idx;
	t_stack	*a;

	i = 0;
	a = NULL;
	check_args(ac);
	while (++i < ac)
	{
		idx = ft_atoi_nbrk(av[i]);
		ft_stk_add_last(&a, ft_stack_new(idx));
	}
	return (a);
}
