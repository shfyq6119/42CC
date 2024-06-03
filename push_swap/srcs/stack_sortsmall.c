/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sortsmall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:05:41 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/01 00:55:31 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	sort3(t_meta *motha)
{
	t_stack	*a;
	int		first;
	int		second;
	int		third;

	a = (*motha).head_a;
	first = (*a).nb;
	second = (*a).next->nb;
	third = (*a).next->next->nb;
	if (first > second && second < third && third > first)
		swap(motha);
	else if (first < second && second > third && third < first)
		revrot(motha);
	else if (first > second && second < third && third < first)
		rot(motha);
	else if (first > second && second >> third && third < first)
	{
		swap(motha);
		revrot(motha);
	}
	else if (first < second && second > third && third > first)
	{
		swap(motha);
		rot(motha);
	}
}

void	sort4(t_meta *motha)
{
	t_cmd		*move;
	t_cost		*lowest;
	t_limits	*range;

	move = ft_calloc(1, sizeof(t_cmd));
	lowest = ft_calloc(1, sizeof(t_cost));
	range = ft_calloc(1, sizeof(t_limits));
	(*motha).moves = move;
	(*motha).cost = lowest;
	(*motha).limits = range;
	push(motha);
	sort3(motha);
	restore_sorted(motha);
}
