/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:57:59 by mm-isa            #+#    #+#             */
/*   Updated: 2024/01/23 19:00:52 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(int n)
{
	write(1, &n, 1);
}

void	ft_putnbrpos(int n)
{
	if (n >= 10)
		ft_putnbrpos(n / 10);
	ft_putchar(n % 10 + 48);
}

int	main(int ac, char **av)
{
	(void)av;
	ft_putnbrpos(ac -1);
	write(1, "\n", 1);
	return (0);
}

