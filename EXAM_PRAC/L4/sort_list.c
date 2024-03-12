/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:08:52 by mm-isa            #+#    #+#             */
/*   Updated: 2024/01/08 20:24:35 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int));
{
	int	swap;
	t_list	*temp = lst;
	while (lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			swap = lst->data; // store data in instance into swap variable
			lst->data = lst->next->data; // move next data instance into current
			lst->next->data = swap; // store next data instance with swao var
			lst = temp; // only to reassign if else condition triggers; this merely restores lst back to beginning, if it wasn't at the beginning already.
		}		 	// i.e. at first loop if triggered, this line doesn't do anything. it only shifts to another node other than the beginning if ELSE is triggered
		else			// i.e. there is no need to swap since the data in the next node is not smaller than the current node.
			lst = lst->next; // only this is shifting the pointer to the subseq nodes.!!!!!  temp will always store head.
	}
	lst = temp; // assign back to head and return.
	return (lst);
}

typedef struct s_list
{
	int	data;
	t_list	*next;
}	t_list;


1 5 2 4 3
