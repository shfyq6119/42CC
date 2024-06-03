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
	while (ft_stk_size((*motha).head_a) > 3)
	{
		limit_stackcheck(motha);
		check_cmds(motha);
		stackcheapest(motha);
	}
	sort3(motha);
}

void	limit_stackcheck(t_meta *motha)
{
	t_stack	*a;
	t_stack	*b;

	a = (*motha).head_a;
	b = NULL;
	if ((*motha).head_b != NULL)
		b = (*motha).head_b;
	if ((*motha).head_a->id == A)
	{
		(*motha).limits->min_a = (*motha).head_a->nb; //point of contention
		(*motha).limits->max_a = (*motha).head_a->nb;
		limit_check_a(motha, a);
	}
	if (b && (*motha).head_b->id == B)
	{
		(*motha).limits->min_b = (*motha).head_b->nb;
		(*motha).limits->max_b = (*motha).head_b->nb;
		limit_check_b(motha, b);
	}
}

void	check_cmds(t_meta *motha)
{
	t_stack	*a;
	int		i;
	int		size;

	a = (*motha).head_a;
	i = 0;
	size = ft_stk_size(a);
	while (i < size)
	{

	}
}

void	stackcheapest(t_meta *motha)
{
	
}
