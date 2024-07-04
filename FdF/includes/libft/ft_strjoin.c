/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:01:08 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 19:01:16 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *prefix, char const *suffix)
{
	size_t	schlong;
	char	*desu;

	schlong = ft_strlen(prefix) + ft_strlen(suffix) + 1;
	desu = ft_calloc(schlong, sizeof(char));
	if (!desu)
		return (ft_calloc(1, 1));
	if (prefix)
	{
		ft_memcpy(desu, prefix, ft_strlen(prefix));
		schlong = ft_strlen(desu);
	}
	if (suffix)
		ft_memcpy(desu + schlong, suffix, ft_strlen(suffix));
	schlong = ft_strlen(desu);
	*(desu + schlong) = '\0';
	return (desu);
}
/*
int	main(void)
{
	char *pre = "1234";
	char *suf = "Hello";
	
	printf("%s\n", ft_strjoin(pre, suf));
	return (0);
}*/
