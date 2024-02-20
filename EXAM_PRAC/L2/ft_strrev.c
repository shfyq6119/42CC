/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev_fail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:07:56 by mm-isa            #+#    #+#             */
/*   Updated: 2023/12/13 18:55:13 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strrev(char *str)
{
	int	i = ft_strlen(str);
	int	j = 0;
	char	tmp[i];
	char	*res;
	while (i-- >= 0)
	{
		tmp[j] = str[i];
		j++;
	}
	tmp[j] = '\0';
	res = tmp;
	return (res);
}FAIL
*/
char	*ft_strrev(char *str)
{
	int i = -1;
	int len = 0;
	char	tmp ;

	while (str[len])
		len++;
	while (++i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
	}
	return (str);
}

#include <stdio.h>
int	main()
{
	char str[30] = " " ;
	
	char *res = ft_strrev(str);
	printf("%s\n",res);
	return (0);
}
