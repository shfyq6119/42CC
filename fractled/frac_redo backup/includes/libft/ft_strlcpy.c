/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:09:26 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/10 17:32:03 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *desu, const char *src, size_t slimit)
{
	size_t	idx;
	size_t	schlongth;

	idx = 0;
	schlongth = ft_strlen(src);
	if (slimit)
	{
		while (src[idx] && idx < slimit - 1)
		{
			desu[idx] = src[idx];
			idx++;
		}
		desu[idx] = '\0';
	}
	return (schlongth);
}
