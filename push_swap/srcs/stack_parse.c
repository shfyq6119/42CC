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
		if (!ft_chknum(*str))
			handle_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > INT_MAX || (mod * i) < INT_MIN - 1)
		handle_error();
	return (mod * i);
}

t_stack	*ft_stacksplitter(char **str)
{
	
}

t_stack *stackparse(int ac, char **av)
{
	int		i;
	int		idx;
	t_stack	*a;

	i = 1;
	a = NULL;
	if (ac < 2)
		handle_error();
	if (ac == 2)
		ft_stacksplitter(av);
	else
	{
		while (i < ac)
		{
			idx = ft_atoi_nbrk(av[i]);
			ft_add_last(&a, ft_stack_new[j]);
			i++;
		}
	}
	return (a);
}
