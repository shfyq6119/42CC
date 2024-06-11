/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_module.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:46:39 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/08 16:18:14 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	rot_preprocessor(t_meta *motha)
{
	int	rr_count;

	if (motha->cost->rrr > 0)
	{
		rr_count = motha->cost->rrr;
		flag_nodes(motha->head_a, FLAG_A | FLAG_RR, &rr_count);
		flag_nodes(motha->head_b, FLAG_B | FLAG_RR, &motha->cost->rrr);
	}
	if ((*motha).cost->rra > 0)
		flag_nodes((*motha).head_a, FLAG_A | FLAG_RR, &(*motha).cost->rra);
	if ((*motha).cost->rrb > 0)
		flag_nodes((*motha).head_b, FLAG_B | FLAG_RR, &(*motha).cost->rrb);
	if (motha->cost->rr > 0)
	{
		rr_count = motha->cost->rr;
		flag_nodes(motha->head_a, FLAG_A, &rr_count);
		flag_nodes(motha->head_b, FLAG_B, &motha->cost->rr);
	}
	if ((*motha).cost->ra > 0)
		flag_nodes((*motha).head_a, FLAG_A, &(*motha).cost->ra);
	if ((*motha).cost->rb > 0)
		flag_nodes((*motha).head_b, FLAG_B, &(*motha).cost->rb);
}

void	rot_module(t_meta *motha)
{
	t_stack *last_a;
	t_stack	*last_b;

	last_a = ft_stklast((*motha).head_a);
	last_b = ft_stklast((*motha).head_b);
	if (((motha->head_a && (motha->head_a->id & FLAG_A)) ||
		(last_a && (last_a->id & FLAG_RR))) && 
		((motha->head_b && (motha->head_b->id & FLAG_B)) ||
		(last_b && (last_b->id & FLAG_RR))))
		sub_rot(&motha->head_a, &motha->head_b, motha->head_a, motha->head_b);
	else
	{
		if (motha->head_a && (((motha->head_a->id & FLAG_A) &&
			!(motha->head_a->id & FLAG_RR)) ||
			(last_a && (last_a->id & FLAG_RR))))
			sub_rot(&(*motha).head_a, NULL, motha->head_a, NULL);
		if (motha->head_b && (((motha->head_b->id & FLAG_B) &&
			!(motha->head_b->id & FLAG_RR)) ||
			(last_b && (last_b->id & FLAG_RR))))
			sub_rot(&(*motha).head_b, NULL, motha->head_b, NULL);
	}
}

void	sub_rot(t_stack **head1, t_stack **head2, t_stack *ptr1, t_stack *ptr2)
{
	ptr1 = ft_stklast(ptr1);
	ptr2 = ft_stklast(ptr2);
	if ((head1 && *head1 && (*head1)->id & FLAG_A) &&
		!((*head1)->id & FLAG_RR) && head2 && *head2 &&
		((*head2)->id & FLAG_B) && !((*head2)->id & FLAG_RR))
		rotate(head1, head2);
	else if ((ptr1 && (ptr1->id & FLAG_RR)) && (ptr2 && (ptr2->id & FLAG_RR)))
		revrot(head1, head2, ptr1, ptr2);
	else
	{
		if (head1 && *head1 && ((*head1)->id & (FLAG_A | FLAG_B)) &&
			!((*head1)->id & FLAG_RR))
			rotate(head1, NULL);
		/*else if (head2 && *head2 && ((*head2)->id & FLAG_B) &&
			!((*head2)->id & FLAG_RR))
			rotate(head2, NULL);*/
		/*if (ptr2 && (ptr2->id & FLAG_RR))
			revrot(head2, NULL, ptr2, NULL);*/
		if (ptr1 && (ptr1->id & FLAG_RR))
			{revrot(head1, NULL, ptr1, NULL);
			printf("ending revrot head1->nb: %ld, ptr1->nb: %ld, ptr1->id: %d\n", (*head1)->nb, ptr1->nb, ptr1->id);}
	}
}
void	rotate(t_stack **head1, t_stack **head2)
{
	t_stack	*tmp;

	if (head1 && *head1 && (((*head1)->id & FLAG_A) || ((*head1)->id & FLAG_B)) &&
		!((*head1)->id & FLAG_RR))
	{
		tmp = *head1;
		*head1 = (*head1)->next;
		tmp->next = NULL;
		ft_stk_add_last(head1, tmp);
		if (tmp->id & FLAG_A)
			ft_putendl_fd("ra", 1);
		else if (tmp->id & FLAG_B)
			ft_putendl_fd("rb", 1);
		deflag(tmp);
	}
	if (head2 && *head2 && ((*head2)->id & FLAG_B) &&
		!((*head2)->id & FLAG_RR))
	{
		tmp = *head2;
		*head2 = (*head2)->next;
		tmp->next = NULL;
		ft_stk_add_last(head2, tmp);
		ft_putendl_fd("rr", 1);
		deflag(tmp);
	}
}

void	revrot(t_stack **head1, t_stack **head2, t_stack *ptr1, t_stack *ptr2)
{
	t_stack	*tmp;

	if (head1 && *head1 && ((ptr1->id & FLAG_A) || (ptr1->id & FLAG_B)) &&
		(ptr1->id & FLAG_RR))
	{
		tmp = ft_stkpenultimate(*head1);
		tmp->next = NULL;
		ptr1->next = *head1;
		*head1 = ptr1;
		if (ptr1->id & FLAG_A)
			ft_putendl_fd("rra", 1);
		else if (ptr1->id & FLAG_B)
			ft_putendl_fd("rrb", 1);
		deflag(ptr1);
	}
	if (head2 && *head2 && (ptr2->id & FLAG_B) && (ptr2->id & FLAG_RR))
	{
		tmp = ft_stkpenultimate(*head2);
		tmp->next = NULL;
		ptr2->next = *head2;
		*head2 = ptr2;
		ft_putendl_fd("rrr", 1);
		deflag(ptr2);
	}
}
