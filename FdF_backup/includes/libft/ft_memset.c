/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:45:55 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 19:00:17 by mm-isa           ###   ########.fr       */
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
