/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:58:13 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 19:00:00 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *list_nodes)
{
	int	i;

	i = 0;
	while (list_nodes)
	{
		list_nodes = list_nodes->next;
		i++;
	}
	return (i);
}
