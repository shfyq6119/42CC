/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 06:01:39 by mm-isa            #+#    #+#             */
/*   Updated: 2023/12/12 20:57:56 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlenchr(char *str, char chr, int idx)
{
	int	i = 0;
	while(i < idx)
	{
		if (str[i] == chr)
			return (1);
		i++;
	}
	return (0);
}
int	main(int ac, char **av)
{
	int	i = 0;
	int	j = 0;
	int	k = 0;

	if (ac == 3)
	{
		while (av[1][i])
			i++;
		while (av[2][j])
		{
			av[1][i] = av[2][j]; // literally, UNION, interpolating av[2] into av[1] directly, removing dupes,
			i++;				 // at the end of av[1], just include av[2]], and
			j++;
		}
		i--;
		while (i >= k)			// starting from 0(k) all over again, write whatever is available without dupes
		{						// by checking up till that point if the character already exists,
			if (!(ft_strlenchr(av[1], av[1][k], k)))	// if the character is repeated, skip write, next index++
				write(1, &av[1][k], 1);					// write, as long as the no. of char has not exceeded len
			k++;
		}
	}
	write (1, "\n", 1);			// newline regardless.
}
/* the key difference between INTER and UNION is, UNION is interested in ALL the characters in both strings,
// disregarding duplicates. while INTER is interested ONLY in the FIRST string, if it also appears in the SECOND.
