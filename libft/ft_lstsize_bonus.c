/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:58:13 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/24 02:39:32 by mm-isa           ###   ########.fr       */
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
