/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:38:53 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/13 23:26:11 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *desu, const void *sos, size_t load)
{
	char		*desudesu;
	const char	*soscode;

	desudesu = desu;
	soscode = sos;
	while (load-- && (desu || sos))
		*desudesu++ = *soscode++;
	return (desu);
}
