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

void	ff(t_stack *node)
{
	t_stack	*ptr;

	if (node)
	{
		while (node)
		{
			ptr = node;
			node = node->next;
			free(ptr);
		}
	}
}

int	main(int ac, char **av)
{
	t_meta	heap;
	t_stack	*print;

	heap.head_a = stackparse(ac, av);
	print = heap.head_a;
	while (print)
	{
		printf("%ld\n", print->nb);
		printf("%d\n", print->id);
		print = print->next;
	}
	ff(heap.head_a);
	return (0);
}
