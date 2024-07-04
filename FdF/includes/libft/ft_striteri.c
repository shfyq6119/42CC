/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:01:10 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 19:01:12 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*fn)(unsigned int, char*))
{
	unsigned int	i;

	i = ft_strlen(str);
	while (i--)
		fn(i, &str[i]);
}
