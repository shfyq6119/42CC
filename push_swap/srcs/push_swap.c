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

void	freethe(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ffs(t_meta *motha)
{
	void	*ptr;

	while ((*motha).head_a)
	{
		ptr = (*motha).head_a;
		(*motha).head_a = (*motha).head_a->next;
		free(ptr);
	}
	while ((*motha).head_b)
	{
		ptr = (*motha).head_b;
		(*motha).head_b = (*motha).head_b->next;
		free(ptr);
	}
}

void	ff_gg(t_meta *motha)
{
	ffs(motha);
	free((*motha).cost);
	free((*motha).limits);
	free((*motha).moves);
	exit(EXIT_SUCCESS);
}

void	handle_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_meta	heap;

	if (ac < 2)
		handle_error();
	heap.head_a = stackparse(ac, av);
	heap.head_b = NULL;
	if (!sortcheck(&heap))
	{
		sortstack(&heap);
		ff_gg(&heap);
	}
	ffs(&heap);
}
