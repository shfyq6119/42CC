/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:38:53 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 19:00:09 by mm-isa           ###   ########.fr       */
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
