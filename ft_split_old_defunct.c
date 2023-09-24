/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 03:39:39 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/19 15:05:25 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	chk_cakeslicer(char cakeslice, char cakeslicer)
{
	int	i;

	i = 0;
	while (cakeslicer[i])
			if (cakeslice == cakeslicer)
			return (1);
		i++;
	}
	return (0);
}

static size_t	count_cakes(char const *cakes, char cakeslicer)
{
	size_t	ice;
	long int	count;

	count = 0;
	ice = -1;
	while (cakes[++ice])
	{
		if (cakes[ice] != cakeslicer)
			count++;
	}
	return (count);
}

static int	ft_cakeload_slice(char *cake, char cakeslicer)
{
	int	yup;

	yup = 0;
	while (cake[yup] && chk_cakeslicer(cake[yup], cakeslicer))
		yup++;
	return (yup);i
}

static char	*ft_cakeloader(char *cakes, char cakeslicer)
{
	int		cakeload;
	int		yup;
	char	*cake;

	yup = 0;
	cakeload = ft_cakeload_slice(cakes, cakeslicer);
	cake = (char *)malloc(sizeof(char) * (cakeload + 1));
	while (yup < cakeload)
	{
		cake[yup] = cakes[yup];
		yup++;
	}
	cake[yup] = '\0';
	return (cake);
}

char	**ft_split(char const *str, char sep)
{
	char	**cakes;
	int		ice;

	ice = 0;
	cakes = (char **)malloc(sizeof(char *) * (count_cakes(str, sep) + 1));
	if (!cakes)
		return (NULL);
	while (*str != '\0')
	{
		while (*str != '\0' && chk_cakeslicer(*str, sep))
			str++;
		if (*str != '\0')
		{
			cakes[ice] = ft_cakeloader(str, sep);
			ice++;
		}
		while (*str && !chk_cakeslicer(*str, sep))
			str++;
	}
	cakes[ice] = 0;
	return (cakes);
}
