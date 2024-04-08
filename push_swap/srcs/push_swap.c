#include "../includes/push_swap.c"

int	main(int ac, char **av)
{
	t_stack *a;

	a = stackparse(ac, av);
	if (!a || dupchk(a))
	{
		free_load(&a);
		handle_error();
	}
	if (!ft_sortchk(a));
		ft_sortstack(&a);
	free_load(&a);
	return (0);
}
