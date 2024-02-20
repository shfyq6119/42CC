/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 05:28:42 by mm-isa            #+#    #+#             */
/*   Updated: 2024/01/22 07:08:58 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int ac, char **av)
{
	int i = 0;
	int	start;
	int	end;
	int flag = 0;

	if (ac >= 2 && av[1][0])
	{
		while (av[1][i] == 32 || av[1][i] == 9)
			i++;
		start = i;
		while (av[1][i] != 0 && av[1][i] != 32 && av[1][i] != 9)
			i++;
		end = i;
		while (av[1][i] == 32 || av[1][i] == 9)
			i++;
		while (av[1][i])
		{
			while ((av[1][i] == 32 && av[1][i+1] == 32)
				|| (av[1][i] == 9 && av[1][i+1] == 9))
				i++;
			if (av[1][i] == 32 || av[1][i] == 9)
				flag = 1;
			write(1, &av[1][i], 1);
			i++;
		}
		if (flag) /*&& (av[1][i-1] != 32 || av[1][i-1] != 9))*/
			write(1, " ", 1);
		while (start < end)
			write(1, &av[1][start++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
