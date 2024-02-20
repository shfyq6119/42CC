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
		while (f >= ++i)		// enters with i = 2
		{
			if (f % i == 0)		//if 2 is a prime factor, next line writes it, else increment by 1 = 3, 4, 5...so on
			{
				printf("%d", i);	//print out the prime factor where f mod i leaves no remainders.
				if (f == i)
					break ;
				printf("*");		//after printing first prime factor print "*" e.g. i1*i2*i3 etc...
				f /= i;			//bring down the integer's value by an order of (multiple of) i.
				i = 1; 			//you must start back from 1 to find next prime factor, it may well be the same.
			}				//same, or not. print display, not list, in terms of prime
		}					//factorISATION, not common factors as in unique and without duplicates.
	}
	printf("\n");
	return (0);
}
