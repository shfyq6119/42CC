/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:13:04 by mm-isa            #+#    #+#             */
/*   Updated: 2023/11/17 17:27:32 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*nl_chomper(char *mush, char *mash)
{
	char	*nom;
	int		nomz;
	int		nomnom;

	nom = malloc(ft_strlen(mush) + ft_strlen(mash) + 1);
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

static int	nl_memmove(char *swallow)
{
	int	nlflag;
	int	nop;
	int	yes;

	nlflag = 0;
	nop = 0;
	yes = 0;
	if (!swallow)
		return (0);
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

char	*get_next_line(int fd, char *chew)
{
	static char	bite[FOPEN_MAX][BUFFER_SIZE + 1];
	int			init;

	init = 1;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (ft_bzero(fd, bite[fd], BUFFER_SIZE + 1));
    if (!chew)
        chew = NULL;
	while (init > 0)
	{
		if (!bite[fd][0])
			init = read(fd, bite[fd], BUFFER_SIZE);
		if (init < 0)
		{
			free(chew);
			return (ft_bzero(fd, bite[fd], BUFFER_SIZE + 1));
		}
		if (init > 0)
			chew = nl_chomper(chew, bite[fd]);
		if (nl_memmove(bite[fd]))
			break ;
	}
	return (chew);
}
/*
#include <fcntl.h>
int	main(void)
{
	int fd[2];
	char	*str;
	int	i;
	

	i = 0;
	fd[0] = open("test3.txt", O_RDONLY);
	fd[1] = open("test2.txt", O_RDONLY);
	while ((str = get_next_line(fd[i])))
	{
		printf("%s", str);
		free(str);
		i = (i+1) % 2;
	}
	printf("FOPEN_MAX = %d", FOPEN_MAX);
	close(fd[0]);
	close(fd[1]);
}*/
