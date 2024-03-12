/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:04:00 by mm-isa            #+#    #+#             */
/*   Updated: 2024/01/23 19:12:51 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int n;
	if (a == 0 || b == 0)
		return (0);
	if (a > b); // condition check for the bigger stick.
		n = a;
	else		// check which stick is bigger, assign master.
		n = b;
	while (1) /* obligatory loop */
	{
		if (n % a == 0 && n % b == 0) // both MODS must return 0 for a while integer
			return (n); // this type of construct must be terminated within itself with either brk or ret.
		n * 2; // simple multiplication algorithm
	}
}
