/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 04:32:31 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 18:59:43 by mm-isa           ###   ########.fr       */
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
