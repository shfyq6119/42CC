/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c          		                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:46:39 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/09 16:18:14 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	sort4(t_meta *motha)
{
	t_cost		*lowest;
	t_cmd		*move;
	t_limits	*range;

	lowest = ft_calloc(1, sizeof(t_cost));
	move = ft_calloc(1, sizeof(t_cost));
	range = ft_calloc(1, sizeof(t_limits));
	(*motha).cost = lowest;
	(*motha).moves = move;
	(*motha).limits = range;
	(*motha).head_a->id = B;
	if (!sortcheck(motha))
	{
		push(&(*motha).head_a, &(*motha).head_b);
		sort3(motha);
		restore_sorted(motha);
		t_stack *print = (*motha).head_a;
		int i = 1;
		while (print)
		{
			printf("a%d: %ld\n", i, print->nb);
			print = print->next;
			i++;
		}
		ff_gg(motha);
		exit(EXIT_SUCCESS);
	}
}

void	sort3(t_meta *motha)
{
	int		first;
	int		second;
	int		third;

	first = (*motha).head_a->nb;
	second = (*motha).head_a->next->nb;
	third = (*motha).head_a->next->next->nb;
	if (!sortcheck(motha))
	{
		if (first > second && second < third && third > first)
			swap(&(*motha).head_a);
		else
			tinysortflag(motha, first, second, third);
	}
	if ((*motha).head_b == NULL)
	{
		ffs(motha);
		exit(EXIT_SUCCESS);
	}
		
}

void	tinysortflag(t_meta *motha, int first, int second, int third)
{
	t_stack	*a;

	a = ft_stklast((*motha).head_a);
	if (first > second && second > third)
	{
		swap(&(*motha).head_a);
		a->id |= (FLAG_A | FLAG_RR);
		revrot(&(*motha).head_a, NULL, a, NULL);
	}
	else if (first < second && second > third && third > first)
	{
		swap(&(*motha).head_a);
		(*motha).head_a->id |= FLAG_A;
		rotate(&(*motha).head_a, NULL);
	}
	else if (first < second && second > third)
	{
		a->id |= (FLAG_A | FLAG_RR);
		revrot(&(*motha).head_a, NULL, a, NULL);
	}
	else if (first > second && second < third)
	{
		(*motha).head_a->id |= FLAG_A;
		rotate(&(*motha).head_a, NULL);
	}
}

void	swap(t_stack **header)
{
	t_stack	*tmp;

	if (header && *header && (*header)->next)
	{
		tmp = *header;
		*header = (*header)->next;
		tmp->next = (*header)->next;
		(*header)->next = tmp;
	}
	ft_putendl_fd("sa", 1);
}
