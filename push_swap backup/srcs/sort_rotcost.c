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
	t_stack	*b;

	b = (*motha).head_b;
	init_limits(motha, (*motha).limits);
	while (ft_stk_size((*motha).head_a) != 3)
	{
		b = (*motha).head_b;
		limit_check(&(*motha).limits->min_b, &(*motha).limits->max_b, b);
		check_cmds(motha);
		stackcheapest(motha);
	}
	sort3(motha);
	clean_costs(motha);
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

	a = (*motha).head_a;
	idx = 0;
	size = ft_stk_size(a);
	while (idx <= size - 1)
	{
		pushcost_rotcalc(motha, a, idx);
		if (a->nb > (*motha).limits->max_b || a->nb < (*motha).limits->min_b)
			pushsort_calc_a(motha, NULL);
		else
			pushsort_calc_a(motha, &a->nb);
		rotab_dupcheck((*motha).moves);
		cheapest_check((*motha).cost, (*motha).moves, idx);
		a = a->next;
		idx++;
	}
}

void	stackcheapest(t_meta *motha)
{
	t_stack *last_a;
	t_stack	*last_b;

	rot_preprocessor(motha);
	while (true)
	{
		last_a = ft_stklast((*motha).head_a);
		last_b = ft_stklast((*motha).head_b);
		if (((*motha).head_a && ((*motha).head_a->id & FLAG_A) &&
			!((*motha).head_a->id & FLAG_RR)) ||
			((*motha).head_b && ((*motha).head_b->id & FLAG_B) &&
			!((*motha).head_b->id & FLAG_RR)) ||
			(last_a && (last_a->id & FLAG_RR)) ||
			(last_b && (last_b->id & FLAG_RR)))
			rot_module(motha);
		else
			break;
	}
	while ((*motha).cost->pb != 0)
	{
		push_module(motha);
		(*motha).cost->pb--;
	}
}

void	init_limits(t_meta *motha, t_limits *range)
{
	if ((*motha).head_b->nb > (*motha).head_b->next->nb)
	{
		range->max_b = (*motha).head_b->nb;
		range->min_b = (*motha).head_b->next->nb;
	}
	else
	{
		range->min_b = (*motha).head_b->nb;
		range->max_b = (*motha).head_b->next->nb;
	}
	range->min_a = INT_MAX;
	range->max_a = INT_MIN;
}

void	limit_check(int *min, int *max, t_stack *head)
{
	t_stack	*tmp;

	*min = head->nb;
	*max = head->nb;
	tmp = head->next;
	while (tmp)
	{
		if (tmp->nb < *min)
			*min = tmp->nb;
		if (*max < tmp->nb)
			*max = tmp->nb;
		tmp = tmp->next;
	}
}
