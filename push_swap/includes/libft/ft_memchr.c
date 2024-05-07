/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:04:09 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/14 03:01:04 by mm-isa           ###   ########.fr       */
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
