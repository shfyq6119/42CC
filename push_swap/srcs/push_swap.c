/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:31:41 by mm-isa            #+#    #+#             */
/*   Updated: 2024/04/20 16:31:44 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;

	a = stackparse(ac, av);
	if (!a || dupchk(a))
	{
		free_load(&a);
		handle_error();
	}
	if (!ft_sortchk(a))
		ft_sortstack(&a);
	free_load(&a);
	return (0);
}
