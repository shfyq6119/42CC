/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:23:15 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/09 13:31:54 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (0);
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
        if (argc != 1)
                printf("%s\n", (ft_strchr(argv[1], 99)));
        return (0);
}*/
