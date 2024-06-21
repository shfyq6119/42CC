/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:37:45 by cooi              #+#    #+#             */
/*   Updated: 2023/11/30 21:39:43 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*simu(void *philo)
{
	struct timeval	time;
	t_philo			p;
	int				thinking;

	p = *((t_philo *)philo);
	gettimeofday(&time, NULL);
	thinking = p.id % 2;
	while (deadornot(&p, time))
	{
		if (thinking == 1 && getforks(&p, time, 1) == 1)
		{
			gettimeofday(&time, NULL);
			if (!eatandsleep(&p, time))
				return (NULL);
			thinking = 0;
		}
		else if (thinking == 0)
		{
			print_status(p, time, p.id, "is thinking");
			thinking = 1;
		}
		usleep(1000);
		gettimeofday(&time, NULL);
	}
	return (NULL);
}

int	getforks(t_philo *p, struct timeval time, int getorrelease)
{
	int	left;
	int	right;

	if (p->id == p->philocount)
		left = 0;
	else
		left = p->id;
	right = p->id - 1;
	if (p->philocount == 1)
		return (0);
	if (getorrelease == 1)
		return (takeforks(p, time, left, right));
	else
		return (releaseforks(p, left, right));
}

void	*eatandsleep(t_philo *p, struct timeval time)
{
	if (deadornot(p, time) == NULL)
		return (NULL);
	print_status(*p, time, p->id, "is eating");
	p->lastmeal = (time.tv_sec * 1000) + (time.tv_usec / 1000) - p->start;
	usleep(p->eat * 1000);
	getforks(p, time, 0);
	gettimeofday(&time, NULL);
	if (deadornot(p, time) == NULL)
		return (NULL);
	if (p->mineat != 0)
	{
		p->eatcount += 1;
		if (p->eatcount == p->mineat)
		{
			pthread_mutex_lock(&p->sim->lock);
			p->sim->status -= 1;
			pthread_mutex_unlock(&p->sim->lock);
		}
	}
	print_status(*p, time, p->id, "is sleeping");
	usleep(p->sleep * 1000);
	return ((void *)"ok");
}
