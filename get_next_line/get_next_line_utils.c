/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
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

char	*ft_bzero(int fd, void *buf, size_t bufsize)
{
	unsigned char	*buffer;

	buffer = buf;
	if (fd >= 0 && fd <= 1024)
	{
		while (bufsize)
		{
			*buffer = 0;
			bufsize--;
			buffer++;
		}
		return (NULL);
	}
	return (NULL);
}
