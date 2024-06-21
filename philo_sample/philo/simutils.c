/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:39:05 by cooi              #+#    #+#             */
/*   Updated: 2023/11/30 21:03:20 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*deadornot(t_philo *philo, struct timeval time)
{
	long	ctime;

	ctime = (time.tv_sec * 1000) + (time.tv_usec / 1000) - philo->start;
	if (ctime != 0)
	{
		pthread_mutex_lock(&philo->sim->lock);
		if (philo->sim->status == 0)
		{
			pthread_mutex_unlock(&philo->sim->lock);
			return (NULL);
		}
		else if (ctime - philo->lastmeal >= philo->die)
		{
			philo->sim->status = 0;
			pthread_mutex_unlock(&philo->sim->lock);
			print_status(*philo, time, philo->id, "died");
			return (NULL);
		}
		pthread_mutex_unlock(&philo->sim->lock);
	}
	return ((void *)"ok");
}

int	takeforks(t_philo *p, struct timeval time, int left, int right)
{
	pthread_mutex_lock(&p->sim->fork[left].flock);
	pthread_mutex_lock(&p->sim->fork[right].flock);
	if (p->sim->fork[left].avail == 0)
	{
		pthread_mutex_unlock(&p->sim->fork[left].flock);
		pthread_mutex_unlock(&p->sim->fork[right].flock);
		return (0);
	}
	if (p->sim->fork[right].avail == 0)
	{
		pthread_mutex_unlock(&p->sim->fork[left].flock);
		pthread_mutex_unlock(&p->sim->fork[right].flock);
		return (0);
	}
	p->sim->fork[left].avail = 0;
	p->sim->fork[right].avail = 0;
	pthread_mutex_unlock(&p->sim->fork[left].flock);
	pthread_mutex_unlock(&p->sim->fork[right].flock);
	print_status(*p, time, p->id, "has taken a fork");
	print_status(*p, time, p->id, "has taken a fork");
	return (1);
}

int	releaseforks(t_philo *p, int left, int right)
{
	pthread_mutex_lock(&p->sim->fork[left].flock);
	pthread_mutex_lock(&p->sim->fork[right].flock);
	p->sim->fork[left].avail = 1;
	p->sim->fork[right].avail = 1;
	pthread_mutex_unlock(&p->sim->fork[left].flock);
	pthread_mutex_unlock(&p->sim->fork[right].flock);
	return (1);
}

void	print_status(t_philo p, struct timeval time, int pid, char *status)
{
	long	ctime;

	pthread_mutex_lock(&p.sim->lock);
	ctime = (time.tv_sec * 1000) + (time.tv_usec / 1000) - p.start;
	printf("%li %i %s\n", ctime, pid, status);
	pthread_mutex_unlock(&p.sim->lock);
}
