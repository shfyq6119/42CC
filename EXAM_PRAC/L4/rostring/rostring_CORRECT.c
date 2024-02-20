/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring_CORRECT.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:37:00 by mm-isa            #+#    #+#             */
/*   Updated: 2024/02/01 12:30:26 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*example string: "Abc" | "Abc    " | "     Abc, defg , h" | "Abc de   fghijk"*/
/* Core scenario: write characters with single spaces, ignoring extra spaces  */
/* 		  from std_input. After which, write in first word encountered*/
/* Key actions: Write character, ++; Write space, ++; Write first word, stop. */
/* Core method: While not spacetab, write. if spacetab, fill in space manually*/
/* 		If space, iterate. So how to create conditions to write?      */
/*		If current character is first character of word i.e. not white*/
/*		AND prev char was space OR tab, enter writing sequence	      */
/* 		i. While string still exists, iterating forwards,             */
/*		ii. Check: IF current character is not white AND prev char is */
/*		iii. As long as next white is not encountered, write  i.e.    */
/*		  (ii.) IF(av[1][i] != 32 || av[1][i] != 9) && i-1 == 32 || 9 */
/*		iv.While (av[1][i] != 32 && av[1][i] != 9) write lor	      */
/* 		v. upon encountering space, exit loop BUT, since prev char is */
/*		   NOT space, condition to exit (ii.) not fulfilled:          */
/*		vi. write space, exit scope of IF, iterate over any conseq    */
/*		    spaces, only to trigger write actions when IF == TRUE     */
/*		vii. after reaching end, start writing again back to beginning*/
/******************FUUUUUUUUUUUUUUUUUUUUUUUUUUUUCCCCCKKKKKKK*******************/
#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;
	int		k;

	if (argc > 1)
	{
		i = 0;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')				// skips ahead of all whitespaces (if any) preparing to start work
			i++;								//will be a non-white character.
		k = i;									// assigns first word index (after accounting for whitespaces if any)
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
			i++;								// skips first word
		while (argv[1][i])
		{
			if (argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t') 	//start writing only when current character is NOT white AND before IS white
				&& (argv[1][i - 1] == ' ' || argv[1][i - 1] == '\t')) 		//this encounters the first instance of a letter preceded by whites
			{
				while (argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t')) // will stop when encountering whitespace.
					write(1, &argv[1][i++], 1);				// this will only write nonwhites
				write(1, " ", 1);					//fill in space manually, exits until it encounter next true IF condition
			}
			i++;	//implicit else skipping over spaces.
		}
		while (argv[1][k] && (argv[1][k] != ' ' && argv[1][k] != '\t'))		// write only first word before whitespace
			write(1, &argv[1][k++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
