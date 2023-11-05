/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:13:04 by mm-isa            #+#    #+#             */
/*   Updated: 2023/11/04 20:53:03 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*nl_chomper(char *mush, char *mash)
{
	char	nom;
	int		nomz;
	int		nomnom;

	nom = malloc(ft_schlongth(mush) + ft_schlongth(mash) + 1);
	nomz = -1;
	nomnom = -1;
	while (mush && mush[++nomnom])
		nom[nomnom] = mush[nomnom];
	while (!ft_strchr(bite, '\n') && mash[++nomz])
			nom[nomnom++] = mash[nomz];
	nom[nomnom] = 0;
	free(mush);
	return (nom);
}

int	nl_scanner(char *swallow)
{
	int	nlflag;
	int nop;
	int yes;

	nlquery = 0;
	nop = 0;
	yes = 0;
	
}

char	*get_next_line(int fd)
{
	static char	*bite[BUFFER_SIZE];
	char		*chew;
	int			init;

	chew = "";
	init = 0;
	if (!fd || fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (init > 0)	
	{
		if (!bite[0])
			init = read(fd, bite, BUFFER_SIZE);
		if (init > 0)
			chew = nl_chomper(chew, bite);
		if (nl_scanner(bite))
			break;
	}
	return (chew);
}
