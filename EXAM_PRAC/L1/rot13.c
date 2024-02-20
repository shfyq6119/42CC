/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 07:07:31 by mm-isa            #+#    #+#             */
/*   Updated: 2023/12/16 07:12:53 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int	main(int ac, char **av)
{
	int	i = 0;
	if (ac ==2)
	{
		while (av[1][i])
		{
			if (av[1][i] > 64 && av[1][i] < 91)
				av[1][i] = (av[1][i] - 65 + 13) % 26 + 65;	//find alphabet, create distance from first letter, mod 26.
			else if (av[1][i] > 96 && av[1][i] < 123)		// 26 letters in alphabet. so mod 26 to get position in alphabet + 13
				av[1][i] = (av[1][i] - 97 + 13) % 26 + 97;	// then, add upon first char position.
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

