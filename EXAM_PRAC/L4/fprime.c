/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:31:42 by mm-isa            #+#    #+#             */
/*   Updated: 2023/12/06 01:45:26 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i;
	int f;
	
	i = 1;
	if (ac == 2)
	{
		f = atoi(av[1]);
		if (f == 1)
			printf ("%d", f);
		while (f >= ++i)
		{
			if (f % i == 0)
			{
				printf("%d", i);
				if (f == i)
					break ;
				printf("*");
				f /= i;
				i = 1;
			}
		}
	}
	printf("\n");
	return (0);
}
