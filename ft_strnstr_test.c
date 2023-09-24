/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:35:43 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/19 06:10:39 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_memcmp(const void *m1, const void *m2, size_t match)
{
	while (match)
	{
		if ((*(unsigned char *)m1) != (*(unsigned char *)m2))
			return ((*(unsigned char *)m1) - (*(unsigned char *)m2));
		else
		{
			match--;
			m1++;
			m2++;
		}
	}
	return (0);
}
char	*ft_strnstr(const char *big, const char *smol, size_t schlong)
{
	size_t	schmol;

	schmol = ft_strlen(smol);
	if (!*big)
		return (0);
	if (!*smol)
		return ((char *)big);
	while (*big && schlong-- >= ft_strlen(smol))
	{
		if (!ft_memcmp(big, smol, schmol) && *big == *smol)
			return ((char *)big);
		big++;
	}
	return (0);
}

#include <stdlib.h>
#include <stdio.h>
int main()

{
		char *str = "This is the needle in the haystack";
	    char *substr1 = "This is the needle test which is needless";
	    char *substr2 = "Need less needle in the haystack";
	    char *substr3 = "trollolol needle";
	    char *substr4 = "needle in yo mama's ass";
	    
	    printf("%s\n", ft_strnstr(str, substr1, 25));
		printf("%s\n", ft_strnstr(str, substr2, 100));
	    printf("%s\n", ft_strnstr(str, substr3, 54));
	    printf("%s\n", ft_strnstr(str, substr4, 22));
	    printf("%s\n", ft_strnstr(str, "haystack", 34));
}
