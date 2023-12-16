/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 06:03:01 by mm-isa            #+#    #+#             */
/*   Updated: 2023/12/09 14:15:16 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_atoi_pos(char *str)
{
	int	i = 0;
	while (*str)
		i = i * 10 + *str++ - 48; //abbreviated atoi for only positive numbers without any signs or spaces
	return (i);
}

int is_prime(int n)
{
	int i = 2;
	if (n <= 1)
		return (0);
	while (i * i <= n) //square root approximation method
	{
		if (n % i == 0) //if n can be divided by i which is not equal to n, it is not prime.
			return (0);
		i++;
	}
	return (1);//returns TRUE if function ends successfully without triggering if remainder==TRUE
}

void ft_putnbrpos(int n)
{
	char	d;
	if (n > 9) // lowest sum of sequential prime numbers is 10: 2+3+5
		ft_putnbrpos(n / 10); //recursive div
	d = n % 10 + 48; // recursive, mod only yields result at last digit
	write(1, &d, 1); // recursive write
}

int main(int ac, char **av)
{
	int i = 0; // default value 0 for negative numbers
	int n;
	
	if (ac == 2)
	{
		n = ft_atoi_pos(av[1]);
		while (n > 0) // guarantees input only for positive number, else**
		{
			if (is_prime(n)) // check from largest to smallest prime number
				i += n; // add if pass prime check
			n--; // decrement per loop for next prime check
		}
		ft_putnbrpos(i); // write recursively, defaults to i = "0" if number is -ve.
	}
	write(1, "\n", 1);
	return (0); // 
}
