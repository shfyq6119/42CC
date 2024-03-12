/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:34:41 by mm-isa            #+#    #+#             */
/*   Updated: 2024/03/12 21:57:57 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	splotcount(char const *str, char septum)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str != septum)
		{
			count++;
			while (*str && *str != septum)
				str++;
		}
		else
			str++;
	}
	return (count);
}

static char	**ft_retrofree(char **array, size_t splitcount)
{
	while (splitcount-- && array[splitcount])
		free (*(array + splitcount));
	free(array);
	return (NULL);
}

char	**ft_split(char const *str, char sept)
{
	char		**set;
	char const	*split;
	size_t		idx;

	idx = 0;
	set = (char **)malloc(sizeof(char *) * (splotcount(str, sept) + 1));
	if (!set || !str)
		return (NULL);
	while (*str)
	{
		if (*str != sept)
		{
			split = str;
			while (*str != sept && *str)
				str++;
			set[idx++] = ft_substr(split, 0, str - split);
			if (!set)
				return (ft_retrofree(set, idx));
		}
		else
			str++;
	}
	set[idx] = NULL;
	return (set);
}
