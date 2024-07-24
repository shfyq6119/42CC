/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:04:28 by mm-isa            #+#    #+#             */
/*   Updated: 2024/06/16 15:51:59 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *m1, const void *m2, size_t match)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = m1;
	p2 = m2;
	if ((!m1 && m2) || (!m2 && m1))
		return (-1);
	if (!m1 && !m2)
		return (0);
	while (match)
	{
		if (*p2 != *p1)
			return (*p1 - *p2);
		match--;
		p1++;
		p2++;
	}
	return (0);
}
/*#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	printf("%d\n",ft_memcmp(argv[1], argv[2], atoi(argv[3])));
}*/
