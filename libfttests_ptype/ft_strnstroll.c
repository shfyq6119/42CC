/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:01:15 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/12 23:05:16 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include "libft.h"*/
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *smol, size_t schlong)
{
	if (!*smol)
		return ((char *)big);
	if (!*big || schlong == 0)
		return (0);
	if (*big == *smol || schlong != 0)
	{
		if (*(ft_strnstr(big + 1, smol + 1, schlong - 1) - 1) == *smol)
			return ((char *)big);
	}
	return (ft_strnstr(big + 1, smol, schlong - 1));
}
/*
int	main(void)
{
	printf("%s", ft_strnstr("lorem ipsum dolor sit amet", "sit", 10));
}*/
