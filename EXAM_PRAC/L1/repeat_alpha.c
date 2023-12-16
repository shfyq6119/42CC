/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:45:16 by mm-isa            #+#    #+#             */
/*   Updated: 2023/11/29 14:27:14 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	repeat_alpha(char *str)
{
	int	i;
	int	j;
	int	chr;

	i = 0;
	j = 0;
	chr = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] > 64 && str[i] < 91)
			chr = str[i] - 64;
		if (str[i] > 96 && str[i] < 123)
			chr = str[i] - 96;
		if ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123))
		{
			while (j++ < chr)
				write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int arc, char **arv)
{
	if (arc == 2)
	{
		if (arv[1])
			repeat_alpha(arv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
