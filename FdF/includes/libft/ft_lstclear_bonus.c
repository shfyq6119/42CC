/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 03:50:47 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 18:59:35 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **list, void (*del)(void *))
{
	t_list	*node;

	if (!list || !del)
		return ;
	while (*list)
	{
		node = (*list)->next;
		ft_lstdelone(*list, del);
		*list = node;
	}
}
