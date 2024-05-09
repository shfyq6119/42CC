/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:35:52 by mm-isa            #+#    #+#             */
/*   Updated: 2024/04/29 16:10:38 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	pushsort_b3(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*buf;

	while (ft_lstsize(*a) > 3 && !ft_sortcheck(*a))
	{
		buf = *a;
		i = ft_rotcost(*a, *b);
		while (i >= 0)
		{
			if (i == check_rab(*a, *b, buf))
				i = ft_rab(a, b, buf);
			else if (i == check_rrab(*a, *b, buf))
				i = ft_rrab(a, b, buf);
			else if (i == check_rarrb(*a, *b, buf))
				i = ft_rarrb(a, b, buf);
			else if (i == check_rrarb(*a, *b, buf))
				i = ft_rrarb(a, b, buf);
			else
				buf = buf->next;
		}
	}
}

t_stack	*swapsort_b(t_stack **stk_a)
{
	t_stack	*stk_b;
	int		b_two;

	b_two = 3;
	stk_b = NULL;

	if (ft_lstsize(*stk_a) > 3 && !ft_sortchk(*stk_a))
		pushsort_b3(stk_a, &stk_b);
	if (!ft_sortchk(*stk_a))
		sortstack_a3(stk_a);
	return (stk_b);
}

t_stack	*swapsort_a(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*tmp;
	int		i;
}

void	ft_sortstack(t_metastack *motha)
{
	t_stack	*b;
	t_cmd	*mv;
	t_cost	*chp2gd2;
	int		idx;

	b = NULL;
	if (ft_lstsize(motha) == 2)
		swapsort2(motha);
	else if (ft_lstsize(motha) == 3)
		swapsort3(motha);
	else if (ft_lstsize(motha) == 4)
		swapsort4(motha);
	else
	{
		mv = ft_calloc(1, sizeof(t_cmd));
		motha->moves = mv;
		chp2gd2 = ft_calloc(1, sizeof(t_cost));
		motha->cost = chp2gd2;
		b = swapsort(motha);
		motha = swapsort(b);
	}
}
