/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 03:39:39 by mm-isa            #+#    #+#             */
/*   Updated: 2023/07/12 05:02:09 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	izit_cakeslicer(char cakeslice, char *cakeslicer)
{
	int	i;

	i = 0;
	while (cakeslicer[i])
	{
		if (cakeslice == cakeslicer[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_cakes(char *cakes, char *cakeslicer)
{
	int	ice;
	int	count;

	count = 0;
	ice = 0;
	while (cakes[ice])
	{
		while (cakes[ice] && izit_cakeslicer(cakes[ice], cakeslicer))
			ice++;
		if (cakes[ice])
			count++;
		while (cakes[ice] && !izit_cakeslicer(cakes[ice], cakeslicer))
			ice++;
	}
	return (count);
}

static int	ft_cakeload_slice(char *cake, char *cakeslicer)
{
	int	yup;

	yup = 0;
	while (cake[yup] && !izit_cakeslicer(cake[yup], cakeslicer))
		yup++;
	return (yup);
}

static char	*ft_cakeloader(char *cakes, char *cakeslicer)
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

char	**ft_split(char *str, char *charset)
{
	char	**cakes;
	int		ice;

	ice = 0;
	cakes = (char **)malloc(sizeof(char *) * (count_cakes(str, charset) + 1));
	if (!cakes)
		return (NULL);
	while (*str != '\0')
	{
		while (*str != '\0' && izit_cakeslicer(*str, charset))
			str++;
		if (*str != '\0')
		{
			cakes[ice] = ft_cakeloader(str, charset);
			ice++;
		}
		while (*str && !izit_cakeslicer(*str, charset))
			str++;
	}
	cakes[ice] = 0;
	return (cakes);
}
