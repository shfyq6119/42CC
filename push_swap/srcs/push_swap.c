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
	t_metastack	heap;

	heap.head_a = stackparse(ac, av);
	if (!heap.head_a || dupchk(heap.head_a))
	{
		free_load(&heap);
		handle_error();
	}
	if (!ft_sortchk(heap.head_a))
		ft_sortstack(&heap);
	free_load(&heap);
	return (0);
}
