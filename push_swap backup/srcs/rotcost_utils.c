/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotcost_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:44:12 by mm-isa            #+#    #+#             */
/*   Updated: 2024/04/26 05:08:32 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/*this looks okay*/
void	pushcost_rotcalc(t_meta *motha, t_stack *a, int i)
{
	int	size;

	(*motha).moves->pb = 1;
	(*motha).moves->ra = 0;
	(*motha).moves->rra = 0;
	if ((*motha).head_a->nb == a->nb)
		return ;
	size = ft_stk_size((*motha).head_a);
	median_rotcost(&(*motha).moves->rra, &(*motha).moves->ra, size, i);
}

void	median_rotcost(int *revrot, int *rotate, int size, int idx)
{
	if (size % 2 == 0)
	{
		if (idx + 1 > size / 2)
			*revrot = (size - idx);
		else
			*rotate = idx;
	}
	else
	{
		if (idx > size / 2)
			*revrot = (size - idx);
		else
			*rotate = idx;
	}
}

/* before pushing A to B, check A->nb's landing target number and index */
void	pushsort_calc_a(t_meta *motha, long *num)
{
	int	i;
	int	size;
	
	motha->moves->rb = 0;
	motha->moves->rrb = 0;
	size = ft_stk_size((*motha).head_b);
	i = 0;
	if ((*motha).head_b->nb == (*motha).limits->max_b)
		return ;
	if (!num)
		i = findex((*motha).head_b, motha->limits->max_b);
	else if (num)
	{
		if ((*motha).head_b->nb == find_nextnum((*motha).head_b, *num))
			return ;
		i = findex((*motha).head_b, find_nextnum((*motha).head_b, *num));
	}
	median_rotcost(&(*motha).moves->rrb, &(*motha).moves->rb, size, i);
}

void	clean_costs(t_meta *motha)
{
	(*motha).cost->pa = 0;
	(*motha).cost->pb = 0;
	(*motha).cost->ra = 0;
	(*motha).cost->rb = 0;
	(*motha).cost->rr = 0;
	(*motha).cost->pa = 0;
	(*motha).cost->rra = 0;
	(*motha).cost->rrb = 0;
	(*motha).cost->rrr = 0;
	(*motha).moves->pa = 0;
	(*motha).moves->pb = 0;
	(*motha).moves->ra = 0;
	(*motha).moves->rb = 0;
	(*motha).moves->rr = 0;
	(*motha).moves->rra = 0;
	(*motha).moves->rrb = 0;
	(*motha).moves->rrr = 0;
}
