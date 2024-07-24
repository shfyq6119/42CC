/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 04:32:31 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/24 04:57:15 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list *list, void (*fn)(void *))
{
	if (list)
	{
		while (list)
		{
			fn(list->content);
			list = list->next;
		}
	}
	else
		return ;
}
