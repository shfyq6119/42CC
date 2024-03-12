/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:45:55 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/14 00:59:04 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *mem, int set, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		*((unsigned char *)mem + i) = (unsigned char)set;
		i++;
	}
	return (mem);
}
