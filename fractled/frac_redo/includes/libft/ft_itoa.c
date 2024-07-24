/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:33:56 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/22 15:07:16 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_schlongth(long digit)
{
	int	i;

	i = 0;
	if (digit <= 0)
	{
		digit *= -1;
		i++;
	}
	while (digit > 0)
	{
		digit /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int c)
{
	char	*ascii;
	int		schlong;
	long	number;

	number = c;
	schlong = ft_schlongth(number);
	ascii = malloc(sizeof(char) * schlong + 1);
	if (!ascii)
		return (NULL);
	ascii[schlong] = '\0';
	while (schlong--)
	{
		if (number < 0)
			number *= -1;
		if (number < 10)
			ascii[schlong] = number + 48;
		else
		{
			ascii[schlong] = number % 10 + 48;
			number /= 10;
		}
	}
	if (c < 0)
		ascii[0] = 45;
	return (ascii);
}
/*
#include <stdio.h>

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
	ft_print_result(ft_itoa(-2147483648));
	write(1, "\n", 1);
	char *res1 = ft_itoa(2147483647);
	ft_print_result(res1);
	write(1, "\n", 1);
	char *res2 = ft_itoa(2147483647);
	printf("%s\n", res2);
	printf("%s\n", ft_itoa(2147483647));
}*/
