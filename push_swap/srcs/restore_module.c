/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_module.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 06:04:12 by mm-isa            #+#    #+#             */
/*   Updated: 2024/08/05 06:05:32 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	restore_sorted(t_meta *motha)
{
	long		*min_a;
	long		*max_a;

	min_a = &(*motha).limits->min_a;
	max_a = &(*motha).limits->max_a;
	while ((*motha).head_b)
	{
		limit_check(min_a, max_a, (*motha).head_a);
		if ((*motha).head_b->nb < *min_a || (*motha).head_b->nb > *max_a)
			pushsort_calc_b(motha, NULL);
		else
			pushsort_calc_b(motha, &(*motha).head_b->nb);
		rot_postprocessor(motha);
		if ((*motha).head_b && (*motha).moves->pa > 0)
			push_module(motha);
	}
}

void	pushsort_calc_b(t_meta *motha, long *num)
{
	int	i;
	int	size;

	(*motha).moves->pa = 1;
	(*motha).moves->ra = 0;
	(*motha).moves->rra = 0;
	(*motha).head_b->id = A;
	i = 0;
	size = ft_stk_size((*motha).head_a);
	if (!num && ((*motha).head_a->nb != (*motha).limits->min_a))
		i = findex((*motha).head_a, (*motha).limits->min_a);
	else if (!num && ft_stklast((*motha).head_a)->nb != (*motha).limits->max_a)
	{
		i = findex((*motha).head_a, (*motha).limits->max_a);
		median_rotmax(motha, size, i);
		push_module(motha);
		(*motha).moves->pa = 0;
		(*motha).moves->ra = 1;
		(*motha).head_a->id |= FLAG_A;
		rot_postprocessor(motha);
		return ;
	}
	else if (num)
		i = findex((*motha).head_a, find_nextnum((*motha).head_a, *num));
	median_rotcost(&(*motha).moves->rra, &(*motha).moves->ra, size, i);
}

void	rot_postprocessor(t_meta *motha)
{
	int		sent;

	sent = sentinel(motha);
	if ((*motha).moves->rra > 0)
		flag_rev((*motha).head_a, FLAG_A, FLAG_RR, &(*motha).moves->rra);
	if ((*motha).moves->ra > 0)
		flagforward((*motha).head_a, FLAG_A, &(*motha).moves->ra);
	while (true)
	{
		sent = sentinel(motha);
		if (!sent)
			break ;
		if ((sent & FLAG_A) && !(sent & FLAG_RR))
			rotate_module(motha);
		else if (sent & (FLAG_A | FLAG_RR))
			revrot_module(motha);
	}
}

void	median_rotmax(t_meta *motha, int size, int idx)
{
	if (size % 2 == 0)
	{
		if (idx + 1 > size / 2)
			(*motha).moves->rra = (size - idx) - 1;
		else
			(*motha).moves->ra = idx + 1;
	}
	else
	{
		if (idx + 1 > size / 2)
			(*motha).moves->rra = (size - idx) - 1;
		else
			(*motha).moves->ra = idx + 1;
	}
	rot_postprocessor(motha);
}

void	finish(t_meta *mother)
{
	int	i;
	int	size;

	(*mother).moves->rra = 0;
	(*mother).moves->ra = 0;
	i = 0;
	size = ft_stk_size((*mother).head_a);
	limit_check(&mother->limits->min_a, &mother->limits->max_a, mother->head_a);
	if ((*mother).head_a->nb != (*mother).limits->min_a)
	{
		i = findex((*mother).head_a, (*mother).limits->min_a);
		median_rotcost(&(*mother).moves->rra, &(*mother).moves->ra, size, i);
		rot_postprocessor(mother);
	}
}
