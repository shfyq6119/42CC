/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:42:49 by mm-isa            #+#    #+#             */
/*   Updated: 2023/12/21 13:55:05 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	j = 0;
	if (ac == 3)
	{
		while(av[2][j])
			if (av[2][j++] == av[1][i])
				i++;
		if (!av[1][i])
		{
			i = 0;
			while (av[1][i])
				write(1, &av[1][i++], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}