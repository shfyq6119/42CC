/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:09:26 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/10 17:32:03 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t slimit)
{
	size_t	idx;
	size_t 	schlongth;

	idx = 0;
	schlongth = ft_strlen(src);
	if (slimit)
	{
		while (*src && idx < slimit - 1)
		{
			dest[idx] = src[idx];
			idx++;
		}
		dest[idx] = '\0';
	}
	return (schlongth);
}
