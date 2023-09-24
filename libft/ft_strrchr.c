/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 05:40:34 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/23 03:24:54 by mm-isa           ###   ########.fr       */
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
