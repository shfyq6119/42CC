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
	int		sentry;

	sentry = sentinel(motha);
	if ((sentry & FLAG_RR) && (sentry & FLAG_A) && (sentry & FLAG_B))
	{
		revrot(&motha->head_a);
		revrot(&motha->head_b);
		ft_putendl_fd("rrr", 1);
	}
	else
	{
		if ((sentry & FLAG_RR) && (sentry & FLAG_A))
		{
			revrot(&motha->head_a);
			ft_putendl_fd("rra", 1);
		}
		if ((sentry & FLAG_RR) && (sentry & FLAG_B))
		{
			revrot(&motha->head_b);
			ft_putendl_fd("rrb", 1);
		}
	}
}

void	revrot(t_stack **head)
{
	t_stack	*last;
	
	last = ft_stklast(*head);
	if (*head && (last->id & FLAG_RR))
	{
		ft_stkpenultimate(*head)->next = NULL;
		last->next = *head;
		*head = last;
		deflag(*head);
	}
}
