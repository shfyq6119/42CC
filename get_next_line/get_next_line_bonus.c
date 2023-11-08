/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:13:04 by mm-isa            #+#    #+#             */
/*   Updated: 2023/11/08 05:10:21 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static char	*nl_chomper(char *mush, char *mash)
{
	char	*nom;
	int		nomz;
	int		nomnom;

	nom = malloc(ft_schlongth(mush) + ft_schlongth(mash) + 1);
	nomz = -1;
	nomnom = 0;
	if (!nom)
		return (NULL);
	while (mush && mush[nomnom])
	{
		nom[nomnom] = mush[nomnom];
		nomnom++;
	}
	while (mash[++nomz])
	{
		nom[nomnom++] = mash[nomz];
		if (mash[nomz] == 10)
			break ;
	}
	nom[nomnom] = 0;
	free(mush);
	return (nom);
}

static int	nl_scanner(char *swallow)
{
	int	nlflag;
	int	nop;
	int	yes;

	nlflag = 0;
	nop = 0;
	yes = 0;
	while (swallow[nop])
	{
		if (nlflag)
			swallow[yes++] = swallow[nop];
		else if (swallow[nop] == 10)
			nlflag = 1;
		swallow[nop++] = 0;
	}
	return (nlflag);
}

char	*get_next_line(int fd)
{
	static char	bite[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*chew;
	int			init;

	chew = NULL;
	init = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, bite, 0) < 0)
	{
		if (fd >= 0 && fd <= FOPEN_MAX)
			ft_bzero(bite[fd], BUFFER_SIZE);
		return (NULL);
	}
	while (init > 0)
	{
		if (!bite[fd][0])
			init = read(fd, bite[fd], BUFFER_SIZE);
		if (init > 0)
		{
			chew = nl_chomper(chew, bite[fd]);
			if (nl_scanner(bite[fd]))
				break ;
		}
	}
	return (chew);
}
/*
#include <fcntl.h>
int	main(void)
{
	int fd = open("test2.txt", O_RDONLY);
	int i = 0;
	char	*str;
	while (i < 12)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	return(0);
}*/
