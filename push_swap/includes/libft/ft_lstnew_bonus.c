/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 05:18:17 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/24 00:49:41 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*start;

	start = malloc(sizeof(t_list));
	if (!start)
		return (NULL);
	start->content = content;
	start->next = NULL;
	return (start);
}
