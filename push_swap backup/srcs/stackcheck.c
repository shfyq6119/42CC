/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:40:57 by mm-isa            #+#    #+#             */
/*   Updated: 2024/04/18 19:16:10 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	ft_sortchk(t_stack *a)
{
	int	i;

	i = a->nb;
	while (a)
	{
		if (i > (*a).nb)
			return (0);
		i = a->nb;
		a = a->next;
	}
	return (1);
}

int	dupchk(t_stack *stk_a)
{
	t_stack	*chk;

	chk = (*stk_a).next;
	while (stk_a)
	{
		while (chk)
		{
			if ((*stk_a).nb == chk->nb)
				return (1);
			chk = chk->next;
		}
		stk_a = (*stk_a).next;
	}
	return (0);
}
