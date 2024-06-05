/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotcost_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:44:12 by mm-isa            #+#    #+#             */
/*   Updated: 2024/04/26 05:08:32 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/*remove A+B rotations and replaces with one R/RR*/
void	rotab_dupcheck(t_cmd *moveset)
{
	moveset->rr = 0;
	moveset->rrr = 0;
	while (moveset->ra && moveset->rb)
	{
		moveset->ra--;
		moveset->rb--;
		moveset->rr++;
	}
	while (moveset->rra && moveset->rrb)
	{
		moveset->rra--;
		moveset->rrb--;
		moveset->rrr++;
	}
}
/*check on every iteration. if cost is more than calculated for next iteration,
replace cost with cheaper, final iteration cheapest in the loop will be stored*/
void	cheapest_check(t_cost *lowest, t_cmd *moveset, int flag)
{
	moveset->count = moveset->pb + moveset->ra + moveset->rb + moveset->rr
		+ moveset->rra + moveset->rrb + moveset->rrr;
	if (flag == 1 || (lowest->cost > moveset->count))
	{
		lowest->cost = moveset->count;
		lowest->pb = moveset->pb;
		lowest->ra = moveset->ra;
		lowest->rb = moveset->rb;
		lowest->rr = moveset->rr;
		lowest->rra = moveset->rra;
		lowest->rrb = moveset->rrb;
		lowest->rrr = moveset->rrr;
	}
}

void	target_acquisition(t_cmd *lowest, t_stack *node)
{
	t_cmd *lowest_r;
	t_cmd *lowest_rr;
	int *push_b;
	int *push_a;

	lowest_r = lowest;
	lowest_rr = lowest;
	push_b = &((*lowest).pb);
	push_a = &((*lowest).pa);

	rot_target(lowest_r, node);
	revrot_target(lowest_rr, node);
}