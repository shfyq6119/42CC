/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:04:09 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 19:00:04 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem, int find, size_t bytes)
{
	size_t	i;

	i = 0;
	while (i < bytes)
	{
		if (*((const unsigned char *)mem + i) == (unsigned char)find)
			return ((void *)mem + i);
		i++;
	}
	return (NULL);
}
