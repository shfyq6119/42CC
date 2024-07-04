/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:52:00 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 18:59:26 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **ls_node, t_list *node_add)
{
	t_list	*access_node;

	if (!ls_node || !node_add)
		return ;
	if (!*ls_node)
		*ls_node = node_add;
	else
	{
		access_node = ft_lstlast(*ls_node);
		access_node->next = node_add;
	}
}
