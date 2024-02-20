/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:44:16 by mm-isa            #+#    #+#             */
/*   Updated: 2024/01/07 18:56:45 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int ac, char **av)
{
	int i = 0;
	int	start;
	int end;
	if (ac == 2)
	{
		while (av[1][i])
			i++;							//all the way to the end.
		while (i >= 0)							//from back to front i until =0, because of this, there is no outer loop decrement
		{								//all decrements to base condition occur within the inner loops.
			while (av[1][i] == 0 || av[1][i] = 32 || av[1][i] == 9)
				i--;						//any spaces at the end or null, backtrack till last nonspace.
			end = i;						//designated end-of-word index.
			while (av[1][i] != 32 && av[1][i] != 9 && av[1][i]) //if nonspace characters therefore they are "words" exist, backtrack.
				i--;						//will result in i = -1 eventually. but will always find next occuring space/non-text
			start = i + 1;					// add one for flag to designate start after non-space non-NULL.
			int	flag = start;				// will designated first letter index of every word as flag.
			while (start <= end)				// write start to end index.
			{
				write (1, &av[1][start], 1);
				start++;
			}
			if (flag)						//will result in 0 if start of string is done.
				write(1 , " ", 1);				//writes spaces ONLY if the start index is not the first word.
		}
	}
	write(1, "\n", 1);
}
