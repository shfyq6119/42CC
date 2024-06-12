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
		rotate(&motha->head_a);
		rotate(&motha->head_b);
		ft_putendl_fd("rr", 1);
	}		
	else
	{
		if ((sentry & FLAG_A) && !(sentry & FLAG_RR))
		{
			rotate(&(*motha).head_a);
			ft_putendl_fd("ra", 1);
		}
		else if ((sentry & FLAG_B) && !(sentry & FLAG_RR))
		{
			rotate(&(*motha).head_b);
			ft_putendl_fd("rb", 1);
		}
	}
}

void	rotate(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	*head = (*head)->next;
	tmp->next = NULL;
	ft_stk_add_last(head, tmp);
	ft_putendl_fd("rr", 1);
	deflag(tmp);
}
