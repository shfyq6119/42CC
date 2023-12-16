/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 08:14:11 by mm-isa            #+#    #+#             */
/*   Updated: 2023/12/16 10:13:06 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
//space == 32 tab == 9 nl == 10

char	*ft_strncpy(char *dest, char *src, int len)
{
	int i = -1;
	while(++i < len && src[i])
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char *str)
{
	int		i = 0;
	int		j = i;
	int		k = 0;
	int		wc = 0;
	char	**split;
	if (!str || !split)
		return (NULL);
	while (str[i])
	{
		while (str[i] && (str[i] == 32 || str[i] == 10 || str[i] == 9)) 
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != 32 && str[i] != 10 && str[i] != 9))
			i++;
	}
	split = malloc(sizeof(char *) * (wc + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == 32 || str[i] == 10 || str[i] == 9)) 
			i++;
		j = i;
		while (str[i] && (str[i] != 32 && str[i] != 10 && str[i] != 9))
			i++;
		if (i > j)
		{
			split[k] = malloc(i - j + 1);
			ft_strncpy(split[k++], &str[j], i - j);
		}
	}
	split[k] = NULL;
	return (split);
}
