/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:01:08 by mm-isa            #+#    #+#             */
/*   Updated: 2023/07/09 19:59:29 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_strcpy(char *str, char *desu)
{
	while (*str)
		*desu++ = *str++;
	return (desu);
}

static char	*nullptr(void)
{
	char	*dest;

	dest = malloc(1);
	dest[0] = '\0';
	return (dest);
}

static int	marshmalloc(int size, char **strs, char *sep)
{
	int	schlongth;
	int	seplength;
	int	tally;

	schlongth = 0;
	seplength = ft_strlen(sep);
	tally = 0;
	while (tally < size)
	{
		schlongth += ft_strlen(strs[tally]);
		tally++;
		schlongth += seplength;
	}
	schlongth -= seplength;
	schlongth++;
	return (schlongth);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*desu;
	char	*desuto;

	desu = (char *)malloc(marshmalloc(size, strs, sep) * sizeof(char));
	if (size <= 0)
		return (nullptr());
	desuto = desu;
	i = 0;
	while (i < size)
	{
		desu = ft_strcpy(strs[i], desu);
		if (i + 1 < size)
			desu = ft_strcpy(sep, desu);
		i++;
	}
	*desu = '\0';
	return (desuto);
}
/*
int	main(void)
{
	char *sep = "1234";
	char *strings[4] = {"Hello","World", "I'm", "Testing!"};
	
	printf("%s\n", ft_strjoin(4, strings, sep));
	return (0);
}*/
