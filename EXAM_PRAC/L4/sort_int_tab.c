/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:02:30 by mm-isa            #+#    #+#             */
/*   Updated: 2023/12/16 17:12:09 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	int				tmp;
	while (i < size - 1) // size 6, last index = 5. therefore - 1.
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i]; 			// compare forwards
			tab[i] = tab[i + 1];	// standard swap operation
			tab[i + 1] = tmp;		// do not forget,
			i = 0;					// after each shift reset from the beginning!!;
		}							//increment to next index. everytime a swapsort
		i++;						//shift one, next loop increment restarts from 0;
	}	// i = 0;	 |i = 0; i+1;|i = 0; i+2;|i = 0; i+3;| long loop but it works;
}		// 5,4,3,2,1 | 4,5,3,2,1 | 4,3,5,2,1 | 4,3,2,5,1 | it will loop till max size - 1 index;
									//then once the largest reaches the end,
									//restart the whole set from i = 0; shifting incrementally.
