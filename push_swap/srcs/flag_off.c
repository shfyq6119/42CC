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

void	flag_rev(t_stack *stack, int flag, int flagrev, int *count)
{
	t_stack	*current;
	t_stack	*prev;

	current = stack;
	while (current && current->next)
		current = current->next;
	while (current && (*count) > 0)
	{
		if (!(current->id & flag) && !(current->id & flagrev))
		{
			current->id |= flag;
			current->id |= flagrev;
			(*count)--;
		}
		prev = stack;
		while (prev && prev->next != current)
			prev = prev->next;
		current = prev;
	}
}

void	deflag(t_stack *node)
{
	if (node && (node->id & FLAG_A))
		node->id = node->id & ~FLAG_A;
	if (node && (node->id & FLAG_B))
		node->id = node->id & ~FLAG_B;
	if (node && (node->id & FLAG_RR))
		node->id = node->id & ~FLAG_RR;	
}

void	flagforward(t_stack *stack, int flag, int *count)
{
	while (stack && *count > 0)
	{
		if (!(stack->id & flag))
		{
			stack->id |= flag;
			(*count)--;
		}
		stack = stack->next;
	}
}
