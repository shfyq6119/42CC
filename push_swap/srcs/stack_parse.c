/* ****************************:StdheaderWidth******************************* */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stoll_nbrk(char *str)
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
	if ((mod * i) > INT_MAX || (mod * i) < INT_MIN - 1)
		handle_error();
	return (mod * i);
}

t_stack	*ft_stacksplitter(char **str)
{
	char	**parse;
	t_stack *a;
	int		i;
	int		j;
	
	a = NULL;
	parse = ft_split(*str[i], ' ');
	i = -1;
	while (parse[++i])
	{
		j = ft_stoll_nbrk(parse[i]);
		ft_stk_add_back(&a, ft_stk_new(j));
	}
	free_array(parse);
	return(a);
}


void	check_args(int count)
{
	if (count < 2)
		handle_error();
	if (count == 2)
		ft_stacksplitter(av);
	else
		return ();
}

t_stack *stackparse(int ac, char **av)
{
	int		i;
	int		idx;
	t_stack	*a;

	i = 0;
	a = NULL;
	check_args(ac);
	while (++i < ac)
	{
		idx = ft_stoll_nbrk(av[i]);
		ft_stk_add_back(&a, ft_stack_new(idx);
	}
	return (a);
}
/* ************************************************************************** */
