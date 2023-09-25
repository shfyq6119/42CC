/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 01:26:18 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/24 09:22:42 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	sos;

	sos = ft_strlen(src) + 1;
	dest = ft_calloc(sos, sizeof(char));
	if (!dest)
		return (0);
	if (ft_strlcpy(dest, (char *)src, sos) != sos - 1)
	{
		free(dest);
		return (0);
	}
	return (dest);
}
/*
#include <stdio.h>
size_t ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int main()
{
	char *src = "this is a normal test";
	size_t size1 =  ft_strlen(src);
	char *dest = ft_strdup(src);

	printf("%ld\n", size1);
	printf("%s\n", dest);
	printf("%ld\n", ft_strlen(dest));
	
	free(dest);
}*/
