/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <mm-isa@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:03:43 by mm-isa            #+#    #+#             */
/*   Updated: 2024/07/03 19:05:42 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(const char *str, char delim)
{
	int	count;
	int	word;

	if (!str)
		return (0);
	count = 0;
	word = 0;
	while (*str)
	{
		if (*str == delim)
			word = 0;
		else if (!word)
		{
			word = 1;
			count++;
		}
		str++;
	}
	return (count);
}