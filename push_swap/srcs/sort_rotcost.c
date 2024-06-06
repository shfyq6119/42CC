/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotcost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:46:39 by mm-isa            #+#    #+#             */
/*   Updated: 2024/04/29 16:18:14 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/* find de cheap2 good2 */
void	chp2gd2(t_meta *motha)
{
	t_cmd		*move;
	t_cost		*lowest;
	t_limits	*range;

	move = ft_calloc(1, sizeof(t_cmd));
	lowest = ft_calloc(1, sizeof(t_cost));
	range = ft_calloc(1, sizeof(t_limits));
	(*motha).moves = move;
	(*motha).cost = lowest;
	(*motha).limits = range;
	init_limits(motha, (*motha).limits);
	while (ft_stk_size((*motha).head_a) != 3)
	{
		limit_stackcheck(motha);
		check_cmds(motha);
		stackcheapest(motha);
	}
	//sort3(motha);
}

/*check max/min limit in each stack*/
void	limit_stackcheck(t_meta *motha)
{
	t_stack	*a;
	t_stack	*b;

	a = (*motha).head_a;
	b = NULL;
	if ((*motha).head_b != NULL)
		b = (*motha).head_b;
	if ((*motha).head_a->id == A)
		limit_check_a(motha, a);
	if (b && (*motha).head_b->id == B)
		limit_check_b(motha, b);
}

/*calculate and check cmd list for cheapest push
to the top of B against max,min, or in-between.
if number is going to be a new max or new min,
use the number directly from metadata. else find
based on the current node's nearest match (closest smallest)*/
void	check_cmds(t_meta *motha)
{
	t_stack	*a;
	int		idx;
	int		size;
	int		num;

	a = (*motha).head_a;
	idx = 0;
	size = ft_stk_size(a);
	num = (*motha).head_a->nb;
	while (idx <= size - 1)
	{
		pushcost_rotcalc(motha, a, idx);
		if (a->nb > (*motha).limits->max_b || a->nb < (*motha).limits->min_b)
			pushsort_calc(motha, NULL);
		else
			pushsort_calc(motha, &num);
		rotab_dupcheck((*motha).moves);
		cheapest_check((*motha).cost, (*motha).moves, idx);
		a = a->next;
		idx++;
	}
}

void	stackcheapest(t_meta *motha)
{
	rot_preprocessor(motha);
	while (((*motha).head_a && (*motha).head_a->id & FLAG_A) || ((*motha).head_b
			&& (*motha).head_b->id & FLAG_B))
		rot_module(motha);
	while ((*motha).cost->pb != 0)
	{
		push_preprocessor(motha);
		push_module(motha);
		(*motha).cost->pb--;
	}
}

