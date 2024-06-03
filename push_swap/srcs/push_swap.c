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

void	ff_gg(t_meta *motha)
{
	t_stack	*ptr;

	if ((*motha).head_a)
	{
		while ((*motha).head_a)
		{
			ptr = (*motha).head_a;
			(*motha).head_a = (*motha).head_a->next;
			free(ptr);
		}
	}
}

void	handle_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_meta	heap;
	t_stack	*print;

	heap.head_a = stackparse(ac, av);
	heap.head_b = NULL;
	/*sortstack(&heap);
	print = heap.head_a;
	while (print)
	{
		printf("%ld\n", print->nb);
		print = print->next;
	}
	printf("%d\n", heap.limits->min_a);
	printf("%d\n", heap.limits->max_a);*/
	ff_gg(&heap);
	exit (EXIT_SUCCESS);
}
