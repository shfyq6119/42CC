/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:18:09 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/08 19:40:16 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (2);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int 	main(int argc, char **argv)
{
	printf("%d\n", ft_isalpha(*argv[1]));
	printf("%d", isalpha(*argv[1]));
}
*/
