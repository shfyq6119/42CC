/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:35:52 by mm-isa            #+#    #+#             */
/*   Updated: 2024/04/29 16:10:38 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	prelude(t_stack *a)
{
	t_stack	*node;
	int		i;

	node = a;
	i = 3;
	while (i--)
	{
		a->id = B;
		a = a->next;
	}
	a = node;
}

int	sortcheck(t_meta *motherstack)
{
	t_stack	*a;
	int		check;
	int		i;

	a = (*motherstack).head_a;
	check = (*a).nb;
	i = 0;
	while (++i < ft_stk_size((*motherstack).head_a))
	{
		a = (*a).next;
		if (check > (*a).nb)
			return (0);
		check = (*a).nb;
	}
	ff_gg(motherstack);
	exit(EXIT_SUCCESS);
}

/*line 50: this will check through a series of preconditions for push.
if empty, reassign address of top two node_a to new stack pointer*/
void	sortstack(t_meta *motherstack)
{
	/*int	checksize;

	checksize = ft_stk_size((*motherstack).head_a);
	if (!sortcheck(motherstack))
	{
		if (checksize == 2)
			swap((*motherstack).head_a);
		else if (checksize == 3)
			sort3(motherstack);
		else if (checksize == 4)
			sort4(motherstack);
		else*/
		{
			prelude((*motherstack).head_a);
			while (ft_stk_size((*motherstack).head_b) < 3)
				push_module(motherstack);
			chp2gd2(motherstack);
			//restore_sorted(motherstack);
		}
	//}
}
