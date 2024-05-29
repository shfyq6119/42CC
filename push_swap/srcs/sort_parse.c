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

t_stack	*pushsort_ab(t_metastack *motherstack)
{
	t_stack	*stk_b;
	int		b_two;

	b_two = 3;
	stk_b = NULL;

	if (ft_lstsize(*) > 3 && !ft_sortchk(*stk_a))
		pushsort_b3(stk_a, &stk_b);
	if (!ft_sortchk(*stk_a))
		sortstack_a3(stk_a);
	return (stk_b);
}

t_stack	*return_to_a(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*tmp;
	int		i;
}

void	ft_sortstack(t_metastack *motherstack)
{
	t_stack	*b;
	t_cmd	*mv;
	t_cost	*chp2gd2;
	int		idx;

	
}
