/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:04:28 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/12 17:34:31 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *m1, const void *m2, size_t match)
{
	while (match)
	{
		if ((*(unsigned char *)m1) != (*(unsigned char *)m2))
			return ((*(unsigned char *)m1) - (*(unsigned char *)m2));
		else
		{
			match--;
			m1++;
			m2++;
		}
	}
	return (0);
}
/*#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	printf("%d\n",ft_memcmp(argv[1], argv[2], atoi(argv[3])));
}*/
