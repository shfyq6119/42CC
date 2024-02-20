/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 08:14:11 by mm-isa            #+#    #+#             */
/*   Updated: 2024/01/30 21:47:30 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
//space == 32 tab == 9 nl == 10

char	*ft_strncpy(char *dest, char *src, int len)
{		//ptr params expect addr, so indexes must be &str[index1]
	int i = -1;
	while(++i < len && src[i])
		dest[i] = src[i];
	dest[i] = 0;			//each index of strings should be null-terminated
	return (dest);
}

char	**ft_split(char *str)
{
	int		i = 0;
	int		j = i;
	int		k = 0;
	int		wc = 0;
	char	**split;
	if (!str || !split)
		return (NULL);
	while (str[i]) 								//wordcount function
	{
		while (str[i] && (str[i] == 32 || str[i] == 10 || str[i] == 9)) 
			i++; 								//if space, tab, ignore, keep moving index.
		if (str[i])								// what occurs after loop is necessarily word
			wc++; 								//if str[i] exists, start counting from first letter indexwise
		while (str[i] && (str[i] != 32 && str[i] != 10 && str[i] != 9))
			i++; 								// keep moving index until next space or tab.
	}											// repeat loop, wc will count number of first characters = words.
	split = malloc(sizeof(char *) * (wc + 1));	//malloc no. of words plus NULL term.
	i = 0;										//restart from beginning for;
	while (str[i]) 								//outer loop; iterative strncpy function ignoring spaces
	{
		while (str[i] && (str[i] == 32 || str[i] == 10 || str[i] == 9)) 
			i++; 							// same logic as above;
		j = i; 								//give j index i as start index for next step to find end of word;
		while (str[i] && (str[i] != 32 && str[i] != 10 && str[i] != 9))
			i++; 							// count characters until next space, tab.
		if (i > j) 							// there should be a difference btwn i-end index and j-start index;
		{
			split[k] = malloc(i - j + 1); 	// index-wise malloc k = 0++ with end-start idx + null index;
			ft_strncpy(split[k++], &str[j], i - j); // str N copy dest, source, length from j to i (i.e. i - j).
		}
	}
	split[k] = NULL; 						//null index terminate with NULL instead of 0.
	return (split);
}
