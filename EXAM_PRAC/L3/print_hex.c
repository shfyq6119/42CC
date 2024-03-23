/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:50:44 by mm-isa            #+#    #+#             */
/*   Updated: 2024/01/02 15:19:03 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_atoipos(char *str) //simplified ATOI for positive ints only
{
	int	r = 0;
	int	i = 0;
	while (str[i])
	{
		r = r * 10 + (str[i] - 48);	// raise one order of magnitude at every turn; to add to ones place. first loop r results in 0 anyway.
		i++;							// each loop *= 10 with every index toward the end of string. 4 digits
	}									// 10^4 = 1,000. to write first digit: n =  0 * 10 + digit. next round, 
	return (r);							// n * 10 + one digit converted into dec int.
}

void	print_hex(int n)				//arrayidx=|16|17|18|19|20|21|22|23|24|25|26|27|28|29|30|31|
{										//arrayidx=| 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|13|14|15|
	char	hex[] = "0123456789abcdef"; // hex[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, f}
	if (n >= 16) //condition to start recursion (i.e. base case) i.e. execute next proceeding line(s) until >= 16
		print_hex(n / 16);			//front to back hex placing = n = 80; 80 / 64  /  48  / 32  / 16 / 1
	write(1, &hex[n % 16], 1);		//modding 16 gives the number in the next lower place; each copy of recursion writes only one character from one mod
}									//e.g. 255 == ff; !255 / 16 = 15, *255 % 16 = 15 = f;
									//!15(.975) / 16 = 0.998, *15(.975) % 16 = 15 = f; 
									//!!this will be the last recursive copy since n = 15 i.e. <= 16!!
									// no new print_hex will be created. therefore only two writes will be done.
									// 255 % 16 = f, 15 % 16 = f.

int	main(int ac, char **av) // do NOT expect negs
{
	if (ac == 2)
		print_hex(ft_atoipos(av[1])); // give a number to your printhexer (make your own damn ATOI)
	write(1, "\n", 1);
	return (0);
}
