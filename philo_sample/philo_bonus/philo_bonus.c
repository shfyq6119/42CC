/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:19:35 by cooi              #+#    #+#             */
/*   Updated: 2023/11/30 20:11:32 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start(t_sim *sim)
{
	int				i;
	struct timeval	time;

	i = 0;
	if (gettimeofday(&time, NULL) != 0)
		exit(1);
	while (i < sim->philocount)
	{
		sim->pids[i] = fork();
		sim->philo[i].start = (time.tv_sec * 1000) + (time.tv_usec / 1000);
		if (sim->pids[i] == -1)
		{
			while (--i >= 0)
				kill(sim->pids[i], SIGTERM);
			exit(!(!(printf("Failed to fork!\n"))));
		}
		if (sim->pids[i] == 0)
		{
			simu(&sim->philo[i]);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_sim	sim;
	int		i;

	if (check_args(argc, argv) != 0)
		return (1);
	make_sim(&sim, argc, argv);
	start(&sim);
	i = 0;
	if (sim.mineat == 0)
		sem_wait(sim.status);
	else
		while (i++ < sim.philocount)
			sem_wait(sim.status);
	while (sim.philocount-- > 0)
		kill(sim.pids[sim.philocount], SIGTERM);
	sem_unlink("/lock");
	sem_unlink("/status");
	sem_unlink("/fork");
	return (0);
}
