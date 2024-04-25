/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotcost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:46:39 by mm-isa            #+#    #+#             */
/*   Updated: 2024/04/26 04:41:49 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	ft_rotcost_ab(t_stack *a, t_stack *b)
{
	int		i;
	int		num;
	t_stack	buff;

	buff = a;
	i = ft_check_rrab(a, b, buff->nb);
	while (buff)
	{
		num = buff->nb;
		if (i > ft_check_rab(a, b, num))
			i = ft_check_rab(a, b, num);
		if (i > ft_check_rrab(a, b, num))
			i = ft_check_rrab(a, b, num);
		if (i > ft_check_rarrb(a, b, num))
			i = ft_check_rarrb(a, b, num);
		if (i > ft_check_rrarb(a, b, num))
			i = ft_check_rrarb(a, b, num);
		buff = buff->next;
	}
	return (i);
}

int	ft_rotcost_ba(t_stack *a, t_stack *b)
{
	int		i;
	int		num;
	t_stack	buff;

	buff = a;
	i = ft_check_rrab_a(a, b, buff->nb);
	while (buff)
	{
		num = buff->nb;
		if (i > ft_check_rab_a(a, b, num))
			i = ft_check_rab_a(a, b, num);
		if (i > ft_check_rrab_a(a, b, num))
			i = ft_check_rrab_a(a, b, num);
		if (i > ft_check_rarrb_a(a, b, num))
			i = ft_check_rarrb_a(a, b, num);
		if (i > ft_check_rrarb_a(a, b, num))
			i = ft_check_rrarb_a(a, b, num);
		buff = buff->next;
	}
	return (i);
}
