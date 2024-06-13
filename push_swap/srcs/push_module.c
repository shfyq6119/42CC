/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_module.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:04:12 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/05 22:05:32 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	push_module(t_meta *motha)
{
	if ((*motha).cost->pb > 0)
		(*motha).head_a->id = B;
	else if ((*motha).moves->pa > 0)
		(*motha).head_b->id = A;
	if ((*motha).head_a->id == B)
	{
		if ((*motha).head_b == NULL)
			first_push(&((*motha).head_a), &((*motha).head_b));
		else
			push(&((*motha).head_a), &((*motha).head_b));
	}
	else if ((*motha).head_b->id == A)
	{
		if ((*motha).head_b == NULL)
			return ;
		if ((*motha).head_b->next == NULL)
			last_push(&(*motha).head_a, &(*motha).head_b);
		else
			push(&((*motha).head_b), &((*motha).head_a));
	}
}

void	first_push(t_stack **ptr1, t_stack **ptr2)
{
	*ptr2 = *ptr1;
	*ptr1 = (*ptr1)->next;
	(*ptr2)->next = NULL;
	write(1, "pb\n", 3);
}

void	push(t_stack **ptr1, t_stack **ptr2)
{
	t_stack	*node;

	node = *ptr2;
	*ptr2 = *ptr1;
	*ptr1 = (*ptr1)->next;
	(*ptr2)->next = node;
	if ((*ptr2)->id == B)
		write(1, "pb\n", 3);
	else if ((*ptr2)->id == A)
		write(1, "pa\n", 3);
}

void	last_push(t_stack **ptr1, t_stack **ptr2)
{
	t_stack	*node;

	node = *ptr2;
	*ptr2 = (*ptr2)->next;
	node->next = *ptr1;
	*ptr1 = node;
	write(1, "pa\n", 3);
	return ;
}
