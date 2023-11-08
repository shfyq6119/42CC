/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:03:58 by mm-isa            #+#    #+#             */
/*   Updated: 2023/11/08 02:26:11 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_schlongth(char *schlong)
{
	int	i;

	i = 0;
	while (schlong && schlong[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int chr)
{
	while (*str && *str != (char)chr)
		str++;
	if (*str == (char)chr)
		return (str);
	return (0);
}

void	ft_bzero(void *buf, size_t bufsize)
{
	unsigned char	*buffer;

	buffer = buf;
	while (bufsize)
	{
		*buffer = 0;
		bufsize--;
		buffer++;
	}
}
