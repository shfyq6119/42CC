#include "../includes/push_swap.h"

void	rot_module(t_meta *motha)
{
	if (((*motha).head_a && ((*motha).head_a->id & FLAG_A)) && ((*motha).head_b
			&& ((*motha).head_b->id & FLAG_B)))
		ft_rotate(&(*motha).head_a, &(*motha).head_b);
	else
	{
		if ((*motha).head_a && ((*motha).head_a->id & FLAG_A))
			ft_rotate(&(*motha).head_a, NULL);
		if ((*motha).head_b && ((*motha).head_b->id & FLAG_B))
			ft_rotate(&(*motha).head_b, NULL);
	}
	flagdrop((*motha).head_a, (*motha).head_b, FLAG_A, FLAG_B);
}

void	rot_preprocessor(t_meta *motha)
{
	int	rr_count;

	if (motha->cost->rr > 0)
	{
		rr_count = motha->cost->rr;
		mark_nodes(motha->head_a, FLAG_A, &rr_count);
		mark_nodes(motha->head_b, FLAG_B, &(motha->cost->rr));
	}
	if ((*motha).moves->ra > 0)
		mark_nodes((*motha).head_a, FLAG_A, &(*motha).moves->ra);
	if ((*motha).moves->rb > 0)
		mark_nodes((*motha).head_b, FLAG_B, &(*motha).moves->rb);
	if (motha->cost->rrr > 0)
	{
		rr_count = motha->cost->rrr;
		mark_nodes(motha->head_a, FLAG_A, &rr_count);
		mark_nodes(motha->head_b, FLAG_B, &(motha->cost->rrr));
	}
	if ((*motha).moves->rra > 0)
		mark_nodes((*motha).head_a, FLAG_A, &(*motha).moves->rra);
	if ((*motha).moves->rrb > 0)
		mark_nodes((*motha).head_b, FLAG_B, &(*motha).moves->rrb);
}

void	mark_nodes(t_stack *stack, int flag, int *count)
{
	t_stack	*current;

	current = stack;
	while (current && count > 0)
	{
		if (!(current->id & flag))
		{
			current->id |= flag;
			(*count)--;
		}
		current = current->next;
	}
}

void	ft_rotate(t_stack **head1, t_stack **head2)
{
	t_stack	*tmp;

	if (head1 && *head1 && (((*head1)->id & FLAG_A) || ((*head1)->id & FLAG_B)))
	{
		tmp = *head1;
		*head1 = (*head1)->next;
		while ((*head1)->next != NULL)
			*head1 = (*head1)->next;
		(*head1)->next = tmp;
		tmp->next = NULL;
		if (tmp->id & FLAG_A)
			ft_putendl_fd("ra", 1);
		else if (tmp->id & FLAG_B)
			ft_putendl_fd("rb", 1);
	}
	if (head2 && *head2 && (((*head2)->id & FLAG_A) || ((*head2)->id & FLAG_B)))
	{
		tmp = *head2;
		*head2 = (*head2)->next;
		while ((*head2)->next != NULL)
			*head2 = (*head2)->next;
		(*head2)->next = tmp;
		tmp->next = NULL;
		ft_putendl_fd("rr", 1);
	}
}

void	flagdrop(t_stack *node1, t_stack *node2, int flag1, int flag2)
{
	t_stack	*current;

	if (node1)
	{
		current = node1;
		while (current)
		{
			current->id &= ~flag1;
			current = current->next;
		}
	}
	if (node2)
	{
		current = node2;
		while (current)
		{
			current->id &= ~flag2;
			current = current->next;
		}
	}
}
