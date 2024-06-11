/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotcost_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:44:12 by mm-isa            #+#    #+#             */
/*   Updated: 2024/04/26 05:08:32 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	find_nextnum(t_stack *head, long num)
{
	t_stack	*tmp;
	int		size;
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	size = ft_stk_size(head);
	tmp = head;
	while (flag == 0)
	{
		i = 0;
		if (head->id == A)
			num++;
		else if (head->id == B)
			num--;
		tmp = head;
		while (i++ < size)
		{
			if (tmp->nb == num)
				flag = 1;
			tmp = tmp->next;
		}
	}
	return (num);
}

int	findex(t_stack *head, long num)
{
	int			size;
	int			i;

	i = 0;
	size = ft_stk_size(head);
	while (i < size)
	{
		if (head->nb == num)
			break ;
		head = head->next;
		i++;
	}
	return (i);
}

/*remove A+B rotations and replaces with one R/RR*/
void	rotab_dupcheck(t_cmd *moveset)
{
	moveset->rr = 0;
	moveset->rrr = 0;
	while (moveset->ra != 0 && moveset->rb != 0)
	{
		moveset->ra--;
		moveset->rb--;
		moveset->rr++;
	}
	while (moveset->rra != 0 && moveset->rrb != 0)
	{
		moveset->rra--;
		moveset->rrb--;
		moveset->rrr++;
	}
}

/*check on every iteration. if cost is more than calculated for next iteration,
replace cost with cheaper, final round cheapest in the loop will be stored*/
void	cheapest_check(t_cost *lowest, t_cmd *moveset, int flag)
{
	moveset->count = moveset->pb + moveset->ra + moveset->rb + moveset->rr
		+ moveset->rra + moveset->rrb + moveset->rrr;
	if (flag == 0 || (lowest->tally > moveset->count))
	{
		lowest->tally = moveset->count;
		lowest->pb = moveset->pb;
		lowest->ra = moveset->ra;
		lowest->rb = moveset->rb;
		lowest->rr = moveset->rr;
		lowest->rra = moveset->rra;
		lowest->rrb = moveset->rrb;
		lowest->rrr = moveset->rrr;
	}
}
