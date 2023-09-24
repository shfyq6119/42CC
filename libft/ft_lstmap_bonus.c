/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 04:57:43 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/24 09:15:11 by mm-isa           ###   ########.fr       */
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
