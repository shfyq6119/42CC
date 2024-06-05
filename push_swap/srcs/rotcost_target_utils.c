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

void	rot_target(t_cmd *lowest, t_stack *node)
{
	int ra;
	int rb;
	t_stack *tmp;

	tmp = node;
	if ((*lowest).ra)
	{
		ra = (*lowest).ra;
		while (ra--)
			node = node->next;
		node->id = A;
	}
	else if ((*lowest).rb)
	{
		rb = (*lowest).rb;
		while (rb--)
			node = node->next;
		node->id = B;
	}
	node = tmp;
}