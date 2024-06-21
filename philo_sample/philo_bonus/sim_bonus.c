/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:11:03 by cooi              #+#    #+#             */
/*   Updated: 2023/11/30 21:32:51 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_status(t_philo p, struct timeval time, int pid, char *status)
{
	long	ctime;

	sem_wait(p.sim->lock);
	ctime = (time.tv_sec * 1000) + (time.tv_usec / 1000) - p.start;
	printf("%li %i %s\n", ctime, pid, status);
	sem_post(p.sim->lock);
}

void	*checkdeath(void *philo)
{
	t_philo			*p;
	struct timeval	time;
	long			ctime;

	p = (t_philo *)philo;
	while (1)
	{
		gettimeofday(&time, NULL);
		ctime = (time.tv_sec * 1000) + (time.tv_usec / 1000) - p->start;
		if (ctime - p->lastmeal > p->die)
		{
			print_status(*p, time, p->id, "died");
			while (p->philocount-- > 0)
				sem_post(p->sim->status);
			exit (1);
		}
	}
	return (NULL);
}

int	getsleeptime(t_philo p)
{
	if (p.philocount % 2 != 0)
		return (p.eat / 2 * 1000);
	else if ((p.die - p.eat - p.sleep) > 0)
		return ((p.die - p.eat - p.sleep) * 500);
	else
		return ((p.eat + 1) * 1000);
}

void	eatandsleep(t_philo *p, struct timeval time)
{
	sem_wait(p->sim->fork);
	sem_wait(p->sim->fork);
	gettimeofday(&time, NULL);
	print_status(*p, time, p->id, "has taken a fork");
	print_status(*p, time, p->id, "has taken a fork");
	print_status(*p, time, p->id, "is eating");
	p->lastmeal = (time.tv_sec * 1000) + (time.tv_usec / 1000) - p->start;
	usleep(p->eat * 1000);
	sem_post(p->sim->fork);
	sem_post(p->sim->fork);
	gettimeofday(&time, NULL);
	p->eatcount += 1;
	if (p->mineat != 0 && p->eatcount == p->mineat)
		sem_post(p->sim->status);
	print_status(*p, time, p->id, "is sleeping");
	usleep(p->sleep * 1000);
}

void	simu(t_philo *p)
{
	struct timeval	time;
	pthread_t		tid;
	int				thinking;

	if (pthread_create(&tid, NULL, checkdeath, p) != 0)
		exit (1);
	thinking = p->id % 2;
	gettimeofday(&time, NULL);
	while (1)
	{
		if (thinking == 1)
		{
			eatandsleep(p, time);
			gettimeofday(&time, NULL);
			thinking = 0;
		}
		else if (thinking == 0)
		{
			print_status(*p, time, p->id, "is thinking");
			thinking = 1;
			usleep(getsleeptime(*p));
		}
	}
}
