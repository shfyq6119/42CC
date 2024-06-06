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
	void	*ptr;

	if ((*motha).head_a)
	{
		while ((*motha).head_a)
		{
			ptr = (*motha).head_a;
			(*motha).head_a = (*motha).head_a->next;
			free(ptr);
		}
	}
	if ((*motha).head_b)
	{
		while ((*motha).head_b)
		{
				ptr = (*motha).head_b;
				(*motha).head_b = (*motha).head_b->next;
				free(ptr);
		}
	}
	free((*motha).cost);
	free((*motha).limits);
	free((*motha).moves);
}

void	handle_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_meta	heap;
	t_stack	*print_a;
	t_stack	*print_b;

	heap.head_a = stackparse(ac, av);
	heap.head_b = NULL;
	print_a = heap.head_a;
	while (print_a)
	{
		printf("a: %ld\n", print_a->nb);
		print_a = print_a->next;
	}
	printf("sorting\n");
	sortstack(&heap);

	print_b = heap.head_b;
	while (print_a)
	{
		printf("a: %ld\n", print_a->nb);
		print_a = print_a->next;
	}
	while (print_b)
	{
		printf("b: %ld\n", print_b->nb);
		print_b = print_b->next;
	}
	printf("%d\n", heap.limits->min_a);
	printf("%d\n", heap.limits->max_a);
	printf("%d\n", heap.limits->min_b);
	printf("%d\n", heap.limits->max_b);
	ff_gg(&heap);
	exit (EXIT_SUCCESS);
}
