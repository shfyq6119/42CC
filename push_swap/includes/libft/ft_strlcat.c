/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:00:25 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/13 17:59:06 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *desu, const char *src, size_t slimit)
{
	size_t	schlong;
	size_t	desudesu;

	desudesu = ft_strlen(desu);
	schlong = slimit - desudesu;
	if (ft_strlen(desu) >= slimit || slimit == 0)
		return (ft_strlen(src) + slimit);
	while (*src && schlong > 1)
	{
		desu[desudesu] = *src;
		src++;
		desudesu++;
		schlong--;
	}
	desu[desudesu] = '\0';
	return (ft_strlen(src) + desudesu);
}
