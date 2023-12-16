/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:46:27 by mm-isa            #+#    #+#             */
/*   Updated: 2023/12/06 01:29:36 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int abs(int i)
{
	if (i < 0)
		return(-i);
	return (i);
}

int	*ft_range(int start, int end)
{
	int	*seq;
	int	len;
	int	i;

	i = 0;
	len = abs(start - end) + 1;
	seq = malloc(sizeof(int) * len);
	if (!seq)
		return (NULL);
	while (end > start)
	{
		seq[i] = start;
		start++;
		i++;
	}
	while (start > end)
	{
		seq[i] = start;
		start--;
		i++;
	}
	return (seq);
}
