/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkedlist_deltest.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 05:39:54 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/24 07:04:20 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_memclear(void *content)
{
	char *str = (char *)content;
	if (str == NULL)
		return ;
	free(content);
}

void	*ft_fargdischiet(t_list *node)
{
		while (node->content)
			node->content -= 32;
		return (node);
}

#include <stdio.h>

int	main()
{
	char	*test = "this is test la siol";
	char	*list = "this testlist is fun la siol";
	char	*last = "this one is last siol";
	printf("The contents of string 0 is: %s\n", test);
	printf("The contents of string 1 is: %s\n", list);
	printf("The contents of string 2 is: %s\n", last);
	printf("\n");
	t_list	*node0 = ft_lstnew(test);
	t_list	*node1 = ft_lstnew(list);
	t_list 	*node2 = ft_lstnew(last);
	printf("t_list *node0 = ft_lstnew(test)\nt_list *node1 = ft_lstnew(list)\nt_list *node2 = ft_lstnew(last)\n");
	printf("\n");
	printf("The contents of node 0 is: %s\n", (char *)node0->content);
	printf("The contents of node 1 is: %s\n", ( char *)node1->content);
	printf("The contents of node 2 is: %s\n", (char *)node2->content);
	printf("\n");
	printf("Addr of node 0->next is: %p\n", node0->next);
	printf("Addr of node 1->next is: %p\n", node1->next);
	printf("Addr of node 2->next is: %p\n", node2->next);
	ft_lstadd_back(&node0, node2);
	ft_lstadd_back(&node0, node1);
	ft_lstadd_back(&node1, node0);
	printf("ft_lstadd_back(&node0, node2)\n");
	printf("ft_lstadd_back(&node0, node1)\n");
	printf("ft_lstadd_back(&node0, node1)\n");
	printf("\n");
	printf("The contents of node 0 is: %s\n", (char *)node0->content);
	printf("The contents of node 1 is: %s\n", ( char *)node1->content);
	printf("The contents of node 2 is: %s\n", (char *)node2->content);
	printf("\n");
	printf("Addr of node 0 is: %p\n", &node0);
	printf("\n");
	printf("Addr of node 0->next is: %p\n", node0->next);
	printf("Addr of node 2 is: %p\n", node2);
	printf("Addr of node 2->next is: %p\n", node2->next);
	printf("Addr of node 1 is: %p\n", node1);
	printf("\n");
	printf("Addr of &node0->next is: %p\n", &node0->next);
	printf("Addr of node 1->next is: %p\n", node1->next);
	printf("Addr of &node1->next is: %p\n", &node1->next);
	printf("Addr of node 1 is: %p\n", node1);
	printf("Addr of &node2->next is: %p\n", &node2->next);
	printf("\n");
	printf("Addr of node 0->content is: %p\n", node0->content);
	printf("Addr of node 1->content is: %p\n", node1->content);
	printf("Addr of node 2->content is: %p\n", node2->content);
	
	printf("\n");
	ft_lstadd_front(&node0, node1);
	printf("ft_lstadd_front(&node0, node1);\n");
	printf("The contents of node 0 (node0->content) is: %s\n", (char *)node0->content);
	printf("The contents of node 1 (node1->content) is: %s\n", ( char *)node1->content);
	printf("The contents of node 2 (node2->content) is: %s\n", ( char *)node2->content);
	printf("\n");
	printf("Addr of node 0->next is: %p\n", node0->next);
	printf("Addr of &node0->next is: %p\n", &node0->next);
	printf("Addr of node 1->next is: %p\n", node1->next);
	printf("Addr of &node1->next is: %p\n", &node1->next);
	printf("Addr of node 2->next is: %p\n", node2->next);
	printf("Addr of &node2->next is: %p\n", &node2->next);
	printf("\n");
	//t_list	*nodelulz = ft_lstmap(nodelulz, ft_fargdischiet, ft_memclear);
	//printf("%p\n", &nodelulz);
}
