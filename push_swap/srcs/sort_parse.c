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

void	sortstack(t_meta *motherstack)
{
	int	checksize;

	checksize = ft_stk_size((*motherstack).head_a);
	if (!sortcheck(motherstack))
	{
		if (checksize == 2)
			swap((*motherstack).head_a);
		else if (checksize == 3)
			sort3(motherstack);
		else if (checksize == 4)
			sort4(motherstack);
		else
		{
			while (ft_stk_size((*motherstack).head_b) <= 2)
			{
				ft_push(motherstack); //this will check through a series of preconditions for push. if empty, typecast
				limit_check_b(motherstack, (*motherstack).head_b);
			}
			chp2gd2(motherstack);
			restore_sorted(motherstack);
		}
	}
}
