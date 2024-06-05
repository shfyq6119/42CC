/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:12:09 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/01 00:47:12 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

t_stack	*ft_stack_new(int content)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (!a)
		handle_error();
	a->nb = content;
	a->id = A;
	a->next = NULL;
	return (a);
}

t_stack	*ft_stklast(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

void	ft_stk_add_last(t_stack **a, t_stack *add)
{
	t_stack	*node;

	node = *a;
	if (!a || !add)
		return ;
	if (!*a)
		*a = add;
	else
		(ft_stklast(node))->next = add;
}

int	ft_stk_size(t_stack	*head)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = head;
	if (!head)
		return (0);
	while (head)
	{
		head = (*head).next;
		i++;
	}
	head = tmp;
	return (i);
}
