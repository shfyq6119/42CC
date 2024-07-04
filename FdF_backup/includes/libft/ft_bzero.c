/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:28:34 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 23:27:10 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_bzero(int fd, void *buf, size_t bufsize)
{
    unsigned char    *buffer;

    buffer = buf;
    if (fd >= 0 && fd <= FOPEN_MAX)
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
