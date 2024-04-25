/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:35:52 by mm-isa            #+#    #+#             */
/*   Updated: 2024/04/26 00:01:00 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	pushsort_b3(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*buf;

	while (ft_lstsize(*a) > 3 && !ft_sortcheck(*stk_a))
	{
		buf = *stk_a;
		i = ft_rotcost_ab(*a, *b);
		while (i >= 0)
		{
			if (i == ft_check_rab(*a, *b, buf->nb))
				i = ft_rab(a, b, buf->nb, 'a');
			else if (i == ft_check_rrab(*a, *b, buf->nb))
				i = ft_rrab(a, b, buf->nb, 'a');
			else if (i == ft_check_rarrb(*a, *b, buf->nb))
				i = ft_rarrb(a, b, buf->nb, 'a');
			else if (i == ft_check_rrarb(*a, *b, buf->nb))
				i = ft_rrarb(a, b, buf->nb, 'a');
			else
				buf = buf->next;
		}
	}
}

t_stack	*swapsort_b(t_stack **stk_a)
{
	t_stack	*stk_b;
	int		b_two;

	b_two = 2;
	stk_b = NULL;
	if (ft_lstsiize(*stk_a) > 3 && !ft_sortchk(*stk_a))
		push_b(stk_a, &stk_b, 0);
	if (ft_lstsize(*stk_a) > 3 && !ft_sortchk(*stk_a))
		push_b(stk_a, &stk_b, 0);
	if (ft_lstsize(*stk_a) > 3 && !ft_sortchk(*stk_a))
		pushsort_b3(stk_a, &stk_b);
	if (!ft_sortchk(*stk_a))
		sortstack_a(stk_a);
	return (stk_b);
}

void	ft_sortstack(t_stack **a)
{
	t_stack	*b;
	int		idx;

	b = NULL;
	if (ft_lstsize(*a) == 2)
		swap_a(a, 0);
	else
	{
		b = swapsort_b(a);
		a = swapsort_a(a, &b);
		idx = ft_stack_index(*a, find_min(*a));
		if (idx < ft_lstsize(*a) - idx)
		{
			while ((*a)->nb != find_min(*a))
				rot1_stk_a(a, 0);
		}
		else
		{
			while ((*a)-> nb != find_min(*a))
				rev1_stk_a(a, 0);
		}
	}
}
