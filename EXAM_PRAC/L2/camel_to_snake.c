/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 07:14:34 by mm-isa            #+#    #+#             */
/*   Updated: 2023/12/16 07:31:24 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ulcase(int c)
{
	if (c > 96 && c < 123)
		return (1);
	if (c > 64 && c < 91)
		return (2);
	return (0);
}

int	main(int ac, char **av)
{
	int	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (ulcase(av[1][i]) == 2 && ulcase(av[1][i - 1]) == 1)
				write(1, "_", 1);
			if (ulcase(av[1][i]) == 2)
				av[1][i] += 32;
			if (ulcase(av[1][i]) == 1)
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}	
