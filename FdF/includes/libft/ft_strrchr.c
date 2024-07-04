/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 05:40:34 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 19:01:42 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *search, int c)
{
	size_t			check;
	unsigned int	ctrchk;

	check = ft_strlen(search) + 1;
	ctrchk = 0;
	while (check-- && ctrchk <= ft_strlen(search))
	{
		if (search[check] == (char)c)
			return ((char *)(search + check));
		ctrchk++;
	}
	return (NULL);
}
