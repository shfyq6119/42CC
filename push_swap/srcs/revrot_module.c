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

	last_a = ft_stklast(motha->head_a);
	last_b = ft_stklast(motha->head_b);
	if ((last_a && (last_a->id & FLAG_RR))
		&& (last_b && (last_b->id & FLAG_RR)))
	{
		revrot(&motha->head_a, last_a, FLAG_RR);
		revrot(&motha->head_b, last_b, FLAG_RR);
		ft_putendl_fd("rrr", 1);
	}
	else if ((last_a && (last_a->id & FLAG_RR)) && (last_a->id & FLAG_A))
		revrot(&motha->head_a, last_a, FLAG_A);
	else if ((last_b && (last_b->id & FLAG_RR)) && (last_b->id & FLAG_B))
		revrot(&motha->head_b, last_b, FLAG_B);
}

void	revrot(t_stack **head, t_stack *tail, int flag)
{
	ft_stkpenultimate(*head)->next = NULL;
	tail->next = *head;
	*head = tail;
	if (head && (flag & FLAG_A) && !(flag & FLAG_B) && (tail->id & FLAG_RR))
		ft_putendl_fd("rra", 1);
	if (head && (flag & FLAG_B) && !(flag & FLAG_A) && (tail->id & FLAG_RR))
		ft_putendl_fd("rrb", 1);
	deflag(*head);
}
