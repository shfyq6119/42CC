/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:40:57 by mm-isa            #+#    #+#             */
/*   Updated: 2024/04/18 19:16:10 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sortchk(t_stack *a)
{
	int i;

	i = stk_a->nb;
	while (stk_a)
	{
		if(i > stk_a->nb)
			return (0);
		i = stk_a->nb;
		stk_a = stk_a->next;
	}
	return (1);
}

int	dupchk(t_stack *stk_a)
{
	t_stack	*chk;

	chk = stk_a->next;
	while (stk_a)
	{
		while (chk)
		{
			if (stk_a->nb == chk->nb)
				return (1);
			chk = chk->next;
		}
		stk_a = stk_a->next;
	}
	return (0);
}
