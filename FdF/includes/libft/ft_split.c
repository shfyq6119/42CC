/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:34:41 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/04 00:25:20 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	splotcount(char const *sploot, char splett)
{
	size_t	count;

	count = 0;
	while (sploot && *sploot)
	{
		if (*sploot != splett)
		{
			count++;
			while (*sploot && *sploot != splett)
				sploot++;
		}
		else
			sploot++;
	}
	return (count);
}

static char	**ft_retrofree(char **splatfudge, size_t splitcount)
{
	while (splitcount-- && splatfudge[splitcount])
		free (*(splatfudge + splitcount));
	free (splatfudge);
	return (NULL);
}

char	**ft_split(char const *splot, char splet)
{
	char		**splat;
	char const	*split;
	size_t		splut;

	splut = 0;
	splat = (char **)malloc(sizeof(char *) * (splotcount(splot, splet) + 1));
	if (!splat || !splot)
		return (NULL);
	while (*splot)
	{
		if (*splot != splet)
		{
			split = splot;
			while (*splot != splet && *splot)
				splot++;
			splat[splut++] = ft_substr(split, 0, splot - split);
			if (!splat)
				return (ft_retrofree(splat, splut));
		}
		else
			splot++;
	}
	splat[splut] = NULL;
	return (splat);
}
