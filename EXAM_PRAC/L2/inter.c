/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:31:46 by mm-isa            #+#    #+#             */
/*   Updated: 2023/12/12 21:00:39 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlenchr(char *str, char chr, int idx)
{
	int	i = 0;
	while (str[i] && (i < idx || idx == -1)) // iterate down str up till current
		if (str[i++] == chr)				 // point of av[1], or entirety if av[2]
			return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int	i = 0;
	if (ac == 3)
	{
		while (av[1][i])					// iterate as long as av[1][i] exists (in the order that they appear 
		{												// in av[1]), regardless of av[2] length,
			if (!ft_strlenchr(av[1], av[1][i], i) &&	// we are only interested in av[1], if the same char 
				ft_strlenchr(av[2], av[1][i], -1))		// repeats within the itself up till that point (i)
				write(1, &av[1][i], 1);					// AND only if it also exists within av[2] as well
			i++;										// so to speak, INTERpolating av[2] subject to av[1].
		}
	}
	write(1, "\n", 1);
	return (0);
}
/* the key difference between INTER and UNION is, UNION is interested in ALL the characters in both strings,
// disregarding duplicates. while INTER is interested ONLY in the FIRST string, if it also appears in the SECOND.
