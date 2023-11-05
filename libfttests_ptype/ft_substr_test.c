/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:47:04 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/20 15:51:06 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t schlongth)
{
	size_t	schlong;
	char	*sub;
	char	*nullspace;

	schlong = ft_strlen(str) - start;
	if (start >= ft_strlen(str))
	{
		nullspace = malloc(sizeof(char));
		if (nullspace == NULL)
			return (NULL);
		*nullspace = '\0';
		return (nullspace);
	}
	if (schlongth > schlong)
		schlongth = schlong;
	sub = (char *)malloc(sizeof(char) * (schlongth + 1));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, str + start, schlongth + 1);
	return (sub);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char *s1 = ft_substr("tripouille", 100, 1);
	printf("%s\n", s1);
	char *s2 = strdup("1");
	s2 = ft_substr(s2, 42, 42000000);
	printf("%s\n", s2);
	char *s3 = ft_strdup("1");
	s3 = ft_substr(s3, 42, 42000000);
	free(s1);
	free(s2);
	free(s3);
}*/
