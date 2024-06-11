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
	int	*min_a;
	int	*max_a;
	t_stack	*print_a;
	t_stack	*print_b;
	int i = 1;
	int j = 1;

	min_a = &(*motha).limits->min_a;
	max_a = &(*motha).limits->max_a;
	while ((*motha).head_b)
	{
		print_a = (*motha).head_a;
		print_b = (*motha).head_b;
		i = 1;
		while (print_a)
		{
			printf("loop %d, a%d: %ld\n", j, i, print_a->nb);
			print_a = print_a->next;
			i++;
		}
		i = 1;
		while (print_b)
		{
			printf("loop %d, b%d: %ld\n", j, i, print_b->nb);
			print_b = print_b->next;
			i++;
		}
		limit_check(min_a, max_a, (*motha).head_a);
		printf("min_a: %d, max_a: %d\n", *min_a, *max_a);
		if ((*motha).head_b->nb < *min_a || (*motha).head_b->nb > *max_a)
			pushsort_calc_b(motha, NULL);
		else
			pushsort_calc_b(motha, &(*motha).head_b->nb);
		rot_postprocessor(motha);
		if ((*motha).head_b && (*motha).moves->pa > 0)
			push_module(motha);
		j++;
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
{		i = findex((*motha).head_a, (*motha).limits->min_a);
		printf("index: %d, min_a: %d\n", i, (*motha).limits->min_a);}
	else if (!num && ft_stklast((*motha).head_a)->nb != (*motha).limits->max_a)
	{
		i = findex((*motha).head_a, (*motha).limits->max_a);
		printf("index: %d, max_a: %d\n", i, (*motha).limits->max_a);
		median_rotmax(motha, &motha->moves->rra, &motha->moves->ra, size, i);
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
	t_stack *last_a;
	t_stack	*print = (*motha).head_a;

	if ((*motha).moves->rra > 0)
		flag_nodes((*motha).head_a, FLAG_A | FLAG_RR, &(*motha).moves->rra);
	if ((*motha).moves->ra > 0)
		flag_nodes((*motha).head_a, FLAG_A, &(*motha).moves->ra);
	while (true)
	{
		int i = 1;
		while (print)
		{
			printf("a%d->id: %d\n", i, print->id);
			print = print->next;
			i++;
		}
		last_a = ft_stklast((*motha).head_a);
		if ((*motha).head_a && ((((*motha).head_a->id & FLAG_A) &&
			!((*motha).head_a->id & FLAG_RR)) ||
			(last_a && (last_a->id & (FLAG_A | FLAG_RR)))))
			rot_module(motha);
		else
			break;
	}
}

void	median_rotmax(t_meta *motha, int *rev, int *rot, int size, int idx)
{
	if (size % 2 == 0)
	{
		if (idx + 1 > size / 2)
			*rev = (size - idx) - 1;
		else
			*rot = idx + 1;
	}
	else
	{
		if (idx > size / 2)
			*rev = (size - idx) - 1;
		else
			*rot = idx + 1;
	}
	rot_postprocessor(motha);
	(*motha).head_b->id = A;
}

void	finish(t_meta *mother)
{
	int i;
	int size;

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