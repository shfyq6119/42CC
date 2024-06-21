/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:21:28 by cooi              #+#    #+#             */
/*   Updated: 2023/11/30 17:51:58 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	make_fork(void)
{
	t_fork			fork;
	pthread_mutex_t	flock;

	fork.avail = 1;
	pthread_mutex_init(&flock, NULL);
	fork.flock = flock;
	return (fork);
}

void	make_philos(t_sim *sim, int argc, char **argv)
{
	int				i;

	i = 0;
	while (i < sim->philocount)
	{
		sim->philo[i].id = i + 1;
		sim->philo[i].lastmeal = 0;
		sim->philo[i].eatcount = 0;
		sim->philo[i].sim = sim;
		sim->philo[i].philocount = ft_atoi(argv[1]);
		sim->philo[i].die = ft_atoi(argv[2]);
		sim->philo[i].eat = ft_atoi(argv[3]);
		sim->philo[i].sleep = ft_atoi(argv[4]);
		if (argc == 6)
			sim->philo[i].mineat = ft_atoi(argv[5]);
		else
			sim->philo[i].mineat = 0;
		sim->fork[i] = make_fork();
		i++;
	}
}

void	make_sim(t_sim	*sim, int argc, char **argv)
{
	pthread_mutex_t	lock;

	pthread_mutex_init(&lock, NULL);
	sim->lock = lock;
	if (argc == 6)
		sim->status = ft_atoi(argv[1]);
	else
		sim->status = 1;
	sim->philocount = ft_atoi(argv[1]);
	make_philos(sim, argc, argv);
}
