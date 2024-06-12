#include "../includes/push_swap.h"

t_stack	*hairsplitter(int i, char **str)
{
	t_stack	*a;
	int		ac;
	void	*ptr;

	a = NULL;
	ac = 0;
	ptr = str;
	while (str[ac])
		ac++;
	if (!inting_check(ac, str) && !dupcheck(ac, str))
	{
		while (str[i])
		{
			ptr = str;
			free(ptr);
			str++;
		}
		handle_error();
	}
	a = ft_stack_new(ft_atoi_lbrk(str[i]));
	while (++i < ac)
			ft_stk_add_last(&a, ft_stack_new(ft_atoi_lbrk(str[i])));
	return (a);
}

