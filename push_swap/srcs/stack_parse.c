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

/*t_stack	*ft_stackload(int ac, char **av)
{
	t_stack	*a;

}*/

void	handle_error(void)
{
	perror("Error");
	return ;
}

t_stack	*stackparse(int ac, char **av)
{
	t_stack	*a;
	int		i;

	i = 1;
	argcheck(ac, av);
	a = ft_stack_new(ft_atoi_lbrk(av[i]));
	while (++i < ac) //i = 2, ac = 6, i = 5
	{
		ft_stk_add_last(&a, ft_stack_new(ft_atoi_lbrk(av[i])));
	}
	return (a);
}
