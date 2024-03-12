/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 00:02:53 by mm-isa            #+#    #+#             */
/*   Updated: 2024/01/02 15:44:25 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int	is_alpha(int c)
{
	if (c > 64 && c < 91)
		return (2);
	if (c > 96 && c < 123)
		return (1);
	return (0);
}

int	main(int ac, char **av)					//however many arguments, str_capitalize
{
	int	i = 1;								//therefore start from av[i = 1]
	int j = 0;								//start index of each arg string
	if (ac > 1)
	{
		while (i < ac)
		{
			j = 0;
			while (av[i][j])
			{
				if (is_alpha(av[i][j]) == 2) //if upper,
					av[i][j] += 32;			// to lower
				if (is_alpha(av[i][j]) == 1 && (av[i][j+1] == 32 || av[i][j+1] == 9 || av[i][j+1] == 0))
//if upper AND next index is white or null (EOS), execute shift
					av[i][j] -= 32;			// to_upper
				write(1, &av[i][j++], 1);	// then write, EVERYTHING, regardless of white repeats and dupes etc.
			}
			write(1, "\n", 1);				// write newline at end of each arg.
			i++;							// NEXT!
		}									// inner loop tracks forward looking or obvious words
	}										// outer loop tracks through each arg forwards.
	else
		write(1, "\n", 1);					//empty newline ONLY if nothing to write
	return (0);								//end at last arg without any new empty newlines.
}
