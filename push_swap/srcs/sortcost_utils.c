/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortcost_utils_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:44:12 by mm-isa            #+#    #+#             */
/*   Updated: 2024/04/26 05:08:32 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	ft_check_rab(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = ft_find_bindex(b, c);
	if (i < ft_findex(a, c))
		i = ft_findex(a, c);
	return (i);
}

int	ft_check_rrab(t_stack *a, t_stack *b, int c)
{
	int i;

	i = 0;
	if (ft_find_bindex(b, c))
		i = ft_lstsize(b) - ft_find_bindex(b, c);
	if ((i < (ft_lstsize(a) - ft_findex(a, c))) && ft_findex(a ,c))
		i = ft_lstsize(a) - ft_findex(a, c);
	return (i);
}

int ft_check_rarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_bindex(a, c))
		i = ft_lstsize(b) - ft_find_bindex(b, c);
	i = ft_findex(a, c) + i;
	return (i);
}

int	ft_check_rrarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_findex(a, c))
		i = ft_lstsize(a) - ft_findex(a, c);
	i = ft_find_bindex(b, c) + i;
	return (i);
}
