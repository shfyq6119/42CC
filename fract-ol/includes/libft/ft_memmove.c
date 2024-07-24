/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 05:42:09 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/19 05:42:13 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *desu, const void *sos, size_t nahh)
{
	char		*desudesu;
	const char	*sauce;
	size_t		nambah;

	desudesu = desu;
	sauce = sos;
	nambah = -1;
	if (sauce == desudesu)
		return (desudesu);
	if (!sauce && !desudesu)
		return (NULL);
	if (sauce > desudesu)
	{
		while (++nambah < nahh)
			desudesu[nambah] = sauce[nambah];
	}
	while (++nambah < nahh)
		desudesu[nahh - nambah - 1] = sauce[nahh - nambah - 1];
	return (desudesu);
}
