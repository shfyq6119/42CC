/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:52:00 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/24 03:34:45 by mm-isa           ###   ########.fr       */
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
