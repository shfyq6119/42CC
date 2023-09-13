/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 01:48:20 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/14 02:02:22 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t i)
{
	size_t	idx;

	idx = 0;
	while ((s1[idx] || s2[idx]) && idx < i)
	{
		if (s1[idx] != s2[idx])
			return ((unsigned char) s1[idx] - s2[idx]);
		idx++;
	}
	return (0);
}
