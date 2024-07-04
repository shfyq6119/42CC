/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:30:29 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 19:00:56 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_n(char *s)
{
	int	len;

	len = 0;
	if (!s || *s == '\0')
		return (ft_putstr_n("(null)"));
	while (s[len])
		len += ft_putchar_n(s[len]);
	return (len);
}
