/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 07:33:51 by mm-isa            #+#    #+#             */
/*   Updated: 2024/01/31 12:55:04 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_atoipos(char *av)
{
	int	i = 0;
	int r = 0;
	while (av[i] >= 48 && av[i] <= 57)
	{
		r = r * 10 + (av[i] - 48);
		i++;
	}
	return (r);
}

void ft_putchar(int c)
{
	write(1, &c, 1);
}

void ft_putnbrpos(int av)
{
	if (av >= 0 && av < 10)
		ft_putchar(av + 48);
	else
	{
		ft_putnbrpos(av / 10);
		ft_putchar(av % 10 + 48);
	}
}

int	main(int ac, char **av)
{
	int	i = 1;
	if (ac == 2)
	{
		int	m = ft_atoipos(av[1]); //convert non-neg arg to positive int 
		if (m >= 0)
		{
			while (i <= 9)
			{
				ft_putnbrpos(i);
				write(1, " x ", 3);
				ft_putnbrpos(m);
				write(1, " = ", 3);
				ft_putnbrpos(m * i);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
