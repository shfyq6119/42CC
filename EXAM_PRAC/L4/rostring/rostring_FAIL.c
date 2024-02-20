/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring_FAIL.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:31:00 by mm-isa            #+#    #+#             */
/*   Updated: 2024/02/01 13:36:03 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int i = 0;
	int j = i;
	int k;
	if (ac > 1 || ac == 2)
	{
		while (av[1][i] && (av[1][i] == 32 || av[1][i] == 9))	// skip whitespaces at the beginning (if any)
			i++;
		k = i;													// assigns first character index of first occuring nonwhite
		while (av[1][i] && (av[1][i] != 32 || av[1][i] != 9))	// while ends when space/tab is encountered
			i++;												// index will end at space after first word.
		i++;
		while (av[1][j] != 0 || (av[1][j] && (av[1][j] == 32 || av[1][j] == 9) && (av[1][j+1] == 32 || av[1][i] == 9)))
		{	//********* This while loop is SUS. While whole string still exists, and current character AND upcoming are not spaces. *************//
			j = i;
			while (av[1][j] && av[1][j] != 32 && av[1][j] != 9)
			{
				write(1, &av[1][j], 1);
				if (av[1][j+1] == 32 || av[1][j+1] == 9)
					write(1, " ", 1);
				j++;
			}
			i++;
		}	//******** Keep iterating thru. Will stop when encountering space before next word.
		while (av[1][k] && av[1][k] != 32 && av[1][k] != 9)
			write(1, &av[1][k++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
