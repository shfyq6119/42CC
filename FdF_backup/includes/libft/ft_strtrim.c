/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:58:39 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 19:01:46 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *trash)
{
	size_t	bin;

	if (!str || !trash)
		return (NULL);
	while (*str && ft_strchr(trash, *str))
		str++;
	bin = ft_strlen(str);
	while (bin && ft_strchr(trash, *(str + bin)))
		bin--;
	return (ft_substr(str, 0, bin + 1));
}
