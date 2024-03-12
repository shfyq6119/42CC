/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:34:35 by mm-isa            #+#    #+#             */
/*   Updated: 2024/02/20 21:23:23 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0; //the fucking indexer
	int	flag = 0; //call this firstwordflag or whatever, it's just a flag
	if (ac == 2)
	{
		while (av[1][i])
/*master loop set to terminate all actions within upon NULL*/
		{
			while (av[1][i] && (av[1][i] == 32 || av[1][i] == 9))
				i++; //exclude all whites
			if (flag && (av[1][i] && (av[1][i-1] == 32 || av[1][i-1] == 9)))
/*this condition checks if space should be written: character is not null and before is a whitespace*/
			{
				write(1, " ", 1); //hardcoded singlespace
				flag = 0; //flag DOWN after every space written.
			}
/*this loop writes only non-null whitespace and flags after every final nonwhite*/
			while (av[1][i] && (av[1][i] != 32 && av[1][i] != 9))
			{
				write(1, &av[1][i++], 1); // write all nonwhites
				flag = 1;  // flag up after every nonwhite, will necessarily exit with flag up
			}
		}
	}
	write(1, "\n", 1); // implied ELSE
	return (0);
}
