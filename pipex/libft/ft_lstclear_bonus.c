/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 03:50:47 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/24 04:31:19 by mm-isa           ###   ########.fr       */
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
