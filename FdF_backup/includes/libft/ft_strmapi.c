/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:22:14 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 19:01:33 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *give, char (*fn)(unsigned int, char))
{
	char			*feed;
	unsigned int	me;

	feed = malloc(sizeof(char) * ft_strlen(give) + 1);
	if (!feed)
		return (NULL);
	me = -1;
	while (give[++me])
		feed[me] = fn(me, give[me]);
	feed[me] = '\0';
	return (feed);
}
