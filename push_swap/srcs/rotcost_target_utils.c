/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotcost_target_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:04:12 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/05 22:05:32 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	rot_target(t_cmd *lowest, t_stack *node_a, t_stack *node_b)
{
	int	ra;
	int	rb;
	int	rr;

	if ((*lowest).ra)
	{
		ra = (*lowest).ra;
		while (ra--)
			node_a = node_a->next;
		node_a->id = A;
	}
	if ((*lowest).rb)
	{
		rb = (*lowest).rb;
		while (rb--)
			node_a = node_a->next;
		node_b->id = A;
	}
	else if ((*lowest).rr)
	{
		rr = (*lowest).rr;
		while (rr--)
			node_a = node_a->next;
		node_a->id = B;
	}
}
