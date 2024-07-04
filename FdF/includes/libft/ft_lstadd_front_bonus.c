/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:39:30 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 18:59:30 by mm-isa           ###   ########.fr       */
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
