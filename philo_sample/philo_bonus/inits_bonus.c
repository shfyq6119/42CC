/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:21:28 by cooi              #+#    #+#             */
/*   Updated: 2023/11/30 19:30:46 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		i++;
	}
}

void	make_sim(t_sim	*sim, int argc, char **argv)
{
	int	i;

	i = 0;
	sim->philocount = ft_atoi(argv[1]);
	while (i < 200)
	{
		sim->pids[i] = -1;
		i++;
	}
	sem_unlink("/lock");
	sem_unlink("/fork");
	sem_unlink("/status");
	if (argc == 6)
		sim->mineat = ft_atoi(argv[5]);
	else
		sim->mineat = 0;
	sim->lock = sem_open("/lock", O_CREAT, 0644, 1);
	sim->status = sem_open("/status", O_CREAT, 0644, 0);
	sim->fork = sem_open("/fork", O_CREAT, 0644, sim->philocount);
	make_philos(sim, argc, argv);
}
