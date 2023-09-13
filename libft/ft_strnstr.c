/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:35:43 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/13 23:04:38 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *smol, size_t schlong)
{
	size_t	schmol;

	schmol = ft_strlen(smol);
	if (!*big)
		return (0);
	if (!*smol)
		return ((char *)big);
	while (*big && schlong-- >= ft_strlen(smol))
	{
		if (!ft_memcmp(big, smol, schmol) && *big == *smol)
			return ((char *)big);
		big++;
	}
	return (0);
}
