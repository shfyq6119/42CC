/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:28:34 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/13 23:57:55 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *schitt, size_t is_nasty)
{
	unsigned char	*schiette;

	schiette = schitt;
	while (is_nasty)
	{
		*schiette = 0;
		is_nasty--;
		schiette++;
	}
}
