/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:12:09 by mm-isa            #+#    #+#             */
/*   Updated: 2024/04/20 20:20:20 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

t_stack	*ft_stack_new(int content)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (!a)
		ft_error();
	a->nb = content;
	a->id = A;
	a->next = NULL;
	return (a);
}

void	ft_stk_add_last(t_stack **a, t_stack *add)
{
	if (!a || !add)
		return ;
	if (!*a)
		*a = add;
	else
		(ft_lstlast(*a))->next = add;
}
