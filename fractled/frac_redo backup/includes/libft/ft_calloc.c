/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 01:02:10 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/20 13:51:50 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t elem, size_t bytes)
{
	void	*mem;

	if (bytes != 0 && elem > SIZE_MAX / bytes)
		return (NULL);
	mem = malloc(elem * bytes);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, elem * bytes);
	return (mem);
}
