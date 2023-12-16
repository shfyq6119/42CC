/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:13:46 by mm-isa            #+#    #+#             */
/*   Updated: 2023/12/06 00:44:45 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int* tab, unsigned int len)
{
	unsigned int	i;
	int				r;

	i = 0;
	r = tab[i];
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (r < tab[i])
			r = tab[i];
		i++;
	}
	return (r);
}