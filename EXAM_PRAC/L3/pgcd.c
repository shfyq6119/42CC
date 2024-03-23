/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:57:50 by mm-isa            #+#    #+#             */
/*   Updated: 2024/01/31 14:03:31 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
/* **************************** cheatcodes allowed kekw ********************* */
int	main(int ac, char **av)
{
	int n1; 
	int n2;
	if (ac == 3)
	{
		n1 = atoi(av[1]); //assign left half
		n2 = atoi(av[2]); // assign right half
		if (n1 > 0 && 2 > 0) // negative check
		{
			while (n1 != n2) // reductive subtraction (destructive)
			{
				if (n1 > n2) // both conditions will eventually execute before exit
					n1 -= n2;
				else  		 // pgcd on simplest algo is a destructive subtraction till both ints are equal
					n2 -= n1;
			}
			printf("%d", n1) // just choose either pair, both are equal by the end of reductive loop;
		}
	}
	printf("\n");
	return (0);
}

