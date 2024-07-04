/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_module.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:46:39 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/21 20:38:23 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rot_preprocessor(t_meta *motha)
{
	int	rr_count;

	if (motha->cost->rrr > 0)
	{
		rr_count = motha->cost->rrr;
		flag_rev(motha->head_a, FLAG_A, FLAG_RR, &rr_count);
		flag_rev(motha->head_b, FLAG_B, FLAG_RR, &motha->cost->rrr);
	}
	if ((*motha).cost->rra > 0)
		flag_rev((*motha).head_a, FLAG_A, FLAG_RR, &(*motha).cost->rra);
	if ((*motha).cost->rrb > 0)
		flag_rev((*motha).head_b, FLAG_B, FLAG_RR, &(*motha).cost->rrb);
	if (motha->cost->rr > 0)
	{
		rr_count = motha->cost->rr;
		flagforward(motha->head_a, FLAG_A, &rr_count);
		flagforward(motha->head_b, FLAG_B, &motha->cost->rr);
	}
	if ((*motha).cost->ra > 0)
		flagforward((*motha).head_a, FLAG_A, &(*motha).cost->ra);
	if ((*motha).cost->rb > 0)
		flagforward((*motha).head_b, FLAG_B, &(*motha).cost->rb);
}

void	rotate_module(t_meta *motha)
{
	int	sentry;

	sentry = sentinel(motha);
	if ((sentry & FLAG_A) && (sentry & FLAG_B) && !(sentry & FLAG_RR))
	{
		rotate(&motha->head_a, 0);
		rotate(&motha->head_b, 0);
		write(1, "rr\n", 3);
	}
	else
	{
		if ((sentry & FLAG_A) && !(sentry & FLAG_RR))
		{
			rotate(&(*motha).head_a, 0);
			write(1, "ra\n", 3);
		}
		else if ((sentry & FLAG_B) && !(sentry & FLAG_RR))
		{
			rotate(&(*motha).head_b, 0);
			write(1, "rb\n", 3);
		}
	}
}

void	rotate(t_stack **head, int state)
{
	t_stack	*tmp;

	tmp = *head;
	*head = (*head)->next;
	tmp->next = NULL;
	ft_stk_add_last(head, tmp);
	if (state == 1)
		write(1, "ra\n", 3);
	deflag(tmp);
}
