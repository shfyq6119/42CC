/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:35:43 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 19:01:41 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *smol, size_t schlong)
{
	size_t	schmol;

	schmol = ft_strlen(smol);
	if (!*smol)
		return ((char *)big);
	while (*big && schlong-- >= schmol)
	{
		if (!ft_memcmp(big, smol, schmol) && *big == *smol)
			return ((char *)big);
		big++;
	}
	return (0);
}
