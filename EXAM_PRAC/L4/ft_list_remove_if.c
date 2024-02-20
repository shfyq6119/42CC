/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 01:30:32 by mm-isa            #+#    #+#             */
/*   Updated: 2024/01/17 18:16:17 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{											// **begin_list is pointer to linked list, therefore head pointer.
	if (begin_list == NULL || *begin_list == NULL)
		return ;							// no need while loop, just check contents.
	t_list	*current = *begin_list; 		// create pointer to retain head node reference
	if (cmp(current->data, data_ref) == 0)  // if there is current node's data is the same as reference data
	{								 		// remove by
		*begin_list = current->next;	 	// move begin_list pointer to next node (replace new head);
		free(current);				 		// free current node (reference is still head @ one address before)
		ft_list_remove_if(begin_list, data_ref, cmp); // recursive starting from latest node , or back to beginning? (via bl = cur->next)
	}
	else  									// this clause is to move to next node if not the same as data_ref
	{	  							// recursive application to move to next node if previous clause is not met.
		current = *begin_list; //reassign current to *begin_list parameter,
		ft_list_remove_if(&current->next, data_ref, cmp); // each recursion starts with one node less than the previous.
	}							  // the entire else clause does nothing except create a new function accessing one less node in the entire list i.e. prev.
}
