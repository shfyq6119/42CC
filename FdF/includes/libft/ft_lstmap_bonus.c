/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 04:57:43 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 18:59:50 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, void *(*fn)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*refcpl;

	if (!list)
		return (NULL);
	newlist = ft_lstnew(fn(list->content));
	refcpl = list->next;
	while (refcpl)
	{
		ft_lstadd_back(&newlist, ft_lstnew(fn(refcpl->content)));
		refcpl = refcpl->next;
	}
	while (refcpl)
		ft_lstdelone(refcpl, del);
	return (newlist);
}
