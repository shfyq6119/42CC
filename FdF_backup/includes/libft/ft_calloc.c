/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 01:02:10 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 18:58:38 by mm-isa           ###   ########.fr       */
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
	ft_bzero(0, mem, elem * bytes);
	return (mem);
}
