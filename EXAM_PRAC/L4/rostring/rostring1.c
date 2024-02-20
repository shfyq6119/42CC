/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 05:28:42 by mm-isa            #+#    #+#             */
/*   Updated: 2024/01/22 07:30:00 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main()
{
	char *str = "     AkjhZ zLKIJz ,    23y";
	int i = 0;
	int	start;
	int	end;
	int flag = 0;

	if (str[i])
	{
		while (str[i] == 32 || str[i] == 9)
			i++;
		start = i;
		while (str[i] != 0 && str[i] != 32 && str[i] != 9)
			i++;
		end = i;
		while ((str[i]== 32 && str[i+1] == 32)
			|| (str[i] == 9 && str[i+1] == 9))
			i++;
		while (str[i])
		{
			while ((str[i] == 32 || str[i] == 9))
				i++;
			if (str[i - 1] == 32 || str[i - 1] == 9)
				flag = 1;
			write(1, &str[i], 1);
			i++;
		}
		if (flag && (str[i-1] != 32 || str[i-1] != 9))
			write(1, " ", 1);
		while (str[i] == 0 && start < end)
			write(1, &str[start++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
