/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:39:30 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/24 01:02:42 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **ls_node, t_list *node_zero)
{
	if (!ls_node || !node_zero)
		return ;
	node_zero->next = *ls_node;
	*ls_node = node_zero;
}
