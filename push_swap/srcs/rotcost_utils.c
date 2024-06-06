/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotcost_utils_1.c                                  :+:      :+:    :+:   */
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

/* this looks good*/
void	rotcost_calc(t_stack *node, t_cmd *moveset, int size, int idx)
{
	if (node->id == A)
		median_rotcost(&moveset->rra, &moveset->ra, size, idx);
	else if (node->id == B)
		median_rotcost(&moveset->rrb, &moveset->rb, size, idx);
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
void	pushsort_calc(t_meta *motha, int *num)
{
	int	i;
	int	size;
	int	nbr;

	motha->moves->rb = 0;
	motha->moves->rrb = 0;
	size = ft_stk_size((*motha).head_b);
	i = 0;
	if (!num)
		i = findex_stack_b(motha, motha->limits->max_b);
	else
	{
		nbr = find_nextnum_b(motha, *num);
		if ((*motha).head_b->nb == nbr)
			return ;
		i = findex_stack_b(motha, nbr);
	}
	rotcost_calc((*motha).head_b, (*motha).moves, size, i);
}
