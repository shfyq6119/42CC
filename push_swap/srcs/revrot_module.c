/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_module.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:46:39 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/08 16:18:14 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	revrot_module(t_meta *motha)
{
	t_stack	*last_a;
	t_stack	*last_b;

	last_a = ft_stklast((*motha).head_a);
	last_b = ft_stklast((*motha).head_b);
	if (last_a && (last_a->id & FLAG_A) && (last_a->id & FLAG_RR)
		&& last_b && (last_b->id & FLAG_B) && (last_b->id & FLAG_RR))
		revrot(&motha->head_a, &motha->head_b, last_a, last_b);
	else
	{
		if (last_a && (last_a->id & FLAG_A) && (last_a->id & FLAG_RR))
			revrot(&motha->head_a, NULL, last_a, NULL);
		if (last_b && (last_b->id & FLAG_B) && (last_b->id & FLAG_RR))
			revrot(&motha->head_b, NULL, last_b, NULL);
	}
}

void	revrot(t_stack **head1, t_stack **head2, t_stack *ptr1, t_stack *ptr2)
{
	t_stack	*tmp;

	if (head1 && *head1 && ((ptr1->id & FLAG_A) || (ptr1->id & FLAG_B))
		&& (ptr1->id & FLAG_RR))
	{
		tmp = ft_stkpenultimate(*head1);
		tmp->next = NULL;
		ptr1->next = *head1;
		*head1 = ptr1;
		if (head1 && !head2 && ptr1->id & FLAG_A)
			ft_putendl_fd("rra", 1);
		else if (head1 && !head2 && ptr1->id & FLAG_B)
			ft_putendl_fd("rrb", 1);
		deflag(ptr1);
	}
	if (head2 && *head2 && (ptr2->id & FLAG_B) && (ptr2->id & FLAG_RR))
	{
		tmp = ft_stkpenultimate(*head2);
		tmp->next = NULL;
		ptr2->next = *head2;
		*head2 = ptr2;
		ft_putendl_fd("rrr", 1);
		deflag(ptr2);
	}
}
