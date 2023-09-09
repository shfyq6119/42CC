/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:04:51 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/08 21:13:22 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isdigit(int c)
{
	if (c >= 0 && c <= 9)
		return (1);
	return (0);
}
#include <stdio.h>
#include <ctype.h>
int	main(int argc, char **argv)
{
	printf("%d\n", ft_isdigit('k'));
	printf("%d\n", isdigit(*argv[1]));
}
