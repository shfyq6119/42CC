/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:30:29 by mm-isa            #+#    #+#             */
/*   Updated: 2023/10/07 12:12:44 by mm-isa           ###   ########.fr       */
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
