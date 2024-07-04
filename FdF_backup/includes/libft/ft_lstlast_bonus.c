/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:05:22 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 18:59:46 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *node_zero)
{
	if (!node_zero)
		return (NULL);
	while (node_zero->next)
		node_zero = node_zero->next;
	return (node_zero);
}
