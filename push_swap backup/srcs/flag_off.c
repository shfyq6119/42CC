/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_off.c		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:35:39 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/08 11:36:14 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	flag_nodes(t_stack *stack, int flag, int *count)
{
	t_stack	*current;
	t_stack	*prev;

	current = stack;
	if (flag & FLAG_RR) 
	{
		while (current && current->next)
			current = current->next;
		while (current && (*count)-- > 0)
		{
			if (!(current->id & flag))
				current->id |= flag;
			prev = stack;
			while (prev && prev->next != current)
				prev = prev->next;
			current = prev;
		}
	}
	while (stack && (*count)-- > 0)
	{
		if (!(stack->id & flag))
			stack->id |= flag;
		stack = stack->next;
	}
}

void	deflag(t_stack *node)
{
	if (node && (node->id & FLAG_A))
		node->id &= ~FLAG_A;
	if (node && (node->id & FLAG_B))
		node->id &= ~FLAG_B;
	if (node && (node->id & FLAG_RR))
		node->id &= ~FLAG_RR;
}