/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 02:51:03 by mm-isa            #+#    #+#             */
/*   Updated: 2024/01/02 16:51:38 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_nbrlen(long nb)
{
	int	i = 0;
	if (nb <= 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr) //an extended putnbr (iterative) with malloc to return string array stored in memory.
{
	int		numlen = ft_nbrlen(nbr);
	char	*ascii = malloc(sizeof(char) * numlen + 1);
	long	nb = nbr;
	if (!ascii)
		return (NULL);
	ascii[numlen] = 0;
	while (numlen--) // important not to overwrite the null index so decrement upon entry.
	{
		if (nb < 0)
			nb = -nb;
		if (nb < 10)
			ascii[numlen] = nb + 48;
		else
		{
			ascii[numlen] = nb % 10 + 48; //most direct way to determine numbers as characters is to find;
			nb /= 10;  					  // ones, tens, hundreds, thousands, etc ... 
										  // therefore mod remainder is always used + 48 ('0')
		}
	}
	if (nbr < 0)
		ascii[0] = 45; // final mod will always fill up 0th index so replace with '-' AFTER everything.
	return (ascii);
}
/*
#include <stdio.h>
#include <unistd.h>

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int	main()
{
	char *res = ft_itoa(0);
	ft_print_result(res);
	write(1, "\n", 1);
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-1234));
	char *res3 = ft_itoa(-2147483648);
	ft_print_result(res3);
	write(1, "\n", 1);
	printf("%s\n", ft_itoa(-2147483648));
	ft_print_result(ft_itoa(-2147483648));
	write(1, "\n", 1);
	char *res1 = ft_itoa(2147483647);
	ft_print_result(res1);
	write(1, "\n", 1);
	char *res2 = ft_itoa(2147483647);
	printf("%s\n", res2);
	printf("%s\n", ft_itoa(2147483647));
	free (res);
	free (res1);
	free (res2);
	free (res3);
}*/
