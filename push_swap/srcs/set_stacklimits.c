/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacklimits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 04:37:58 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/01 04:38:02 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	limit_check_a(t_meta *motha, t_stack *a)
{
	int			i;
	int			size;
	t_stack		*tmp;

	i = -1;
	size = ft_stk_size(a);
	tmp = a;
	while (++i < size)
	{
		if (a->nb < (*motha).limits->min_a) //min)a
			(*motha).limits->min_a = a->nb;
		a = a->next;
	}
	i = -1;
	a = tmp;
	while (++i < size)
	{
		if ((*motha).limits->max_a < a->nb) //max_a
			(*motha).limits->max_a = a->nb;
		a = a->next;
	}
	a = tmp;
}

void	limit_check_b(t_meta *motha, t_stack *b)
{
	int			i;
	int			size;
	t_stack		*tmp;

	i = -1;
	size = ft_stk_size(b);
	tmp = b;
	while (++i < size)
	{
		if (b->nb < (*motha).limits->min_b)
			(*motha).limits->min_b = b->nb;
		b = b->next;
	}
	i = -1;
	b = tmp;
	while (++i < size)
	{
		if ((*motha).limits->max_b < b->nb)
			(*motha).limits->max_b = b->nb;
		b = b->next;
	}
	b = tmp;
}
