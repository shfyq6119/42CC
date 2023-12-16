/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 04:06:00 by mm-isa            #+#    #+#             */
/*   Updated: 2023/12/09 04:27:18 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	abs(int pol)
{
	if (pol < 0)
		return (-pol);
	return (pol);
}

int	*ft_range(int start, int end)
{
	int	*tab;
	int	i = 0;
	int	numlen = abs(start - end) + 1;
	tab = malloc(sizeof(int) * numlen);
	if (!tab)
		return (NULL);
	while (start > end)
		tab[i++] = start--;
	while (end > start)
		tab[i++] = start++;
	tab[i] = start;
	return (tab);
}
/*
#include <stdio.h>

int	main()
{
	int	*tab = ft_range(4,2);
	printf("%d, ", tab[0]);
	printf("%d, ", tab[1]);
	printf("%d, ", tab[2]);
	printf("%d, ", tab[3]);
	printf("%d\n", tab[4]);
	printf("%d\n", tab[5]);
	free(tab);
}*/
	
