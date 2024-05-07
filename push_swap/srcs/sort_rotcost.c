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

int	ft_rotcost(t_stack *a, t_stack *b)
{
	int		i;
	int		num;
	t_stack	*buff;

	if (a->id == A)
		buff = a;
	else if (b->id == B)
		buff = b;
	i = ft_check_rrab(a, b, buff->nb);
	while (buff)
	{
		num = buff->nb;
		if (i > check_rab(a, b, num))
			i = check_rab(a, b, num);
		if (i > check_rrab(a, b, num))
			i = check_rrab(a, b, num);
		if (i > check_rarrb(a, b, num))
			i = check_rarrb(a, b, num);
		if (i > check_rrarb(a, b, num))
			i = check_rrarb(a, b, num);
		buff = buff->next;
	}
	return (i);
}

t_stack	**ft_chknsort(t_stack **a, t_stack **b, t_stack *buf)
{
	int i;
	
	while (i >= 0)
	{
		if (i == check_rab(*a, *b, buf->nb))
			i = ft_rab(a, b, buf->nb, 'a');
		else if (i == check_rrab(*a, *b, buf->nb))
			i = ft_rrab(a, b, buf->nb, 'a');
		else if (i == check_rarrb(*a, *b, buf->nb))
			i = ft_rarrb(a, b, buf->nb, 'a');
		else if (i == check_rrarb(*a, *b, buf->nb))
			i = ft_rrarb(a, b, buf->nb, 'a');
		else
			buf = buf->next;
	}
}
/*
int	ft_rotcost_ba(t_stack *a, t_stack *b)
{
	int		i;
	int		num;
	t_stack	*buff;

	buff = a;
	i = ft_check_rrab_a(a, b, buff->nb);
	while (buff)
	{
		num = buff->nb;
		if (i > check_rab_a(a, b, num))
			i = check_rab_a(a, b, num);
		if (i > check_rrab_a(a, b, num))
			i = check_rrab_a(a, b, num);
		if (i > check_rarrb_a(a, b, num))
			i = check_rarrb_a(a, b, num);
		if (i > check_rrarb_a(a, b, num))
			i = check_rrarb_a(a, b, num);
		buff = buff->next;
	}
	return (i);
}*/
