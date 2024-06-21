/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:19:35 by cooi              #+#    #+#             */
/*   Updated: 2023/11/30 17:51:01 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->philocount)
	{
		pthread_join(sim->threads[i], NULL);
		i++;
	}
}

void	start(t_sim *sim)
{
	int				code;
	int				p;
	struct timeval	time;

	p = 0;
	code = 0;
	if (gettimeofday(&time, NULL) != 0)
		return ;
	while (p < sim->philocount && code == 0)
	{
		sim->philo[p].start = (time.tv_sec * 1000) + (time.tv_usec / 1000);
		code = pthread_create(&sim->threads[p], NULL, simu, &sim->philo[p]);
		p++;
	}
	if (code != 0)
	{
		while (p >= 0)
			pthread_detach(sim->threads[p]);
		return ;
	}
	join_threads(sim);
}

int	main(int argc, char **argv)
{
	t_sim	sim;

	if (check_args(argc, argv) != 0)
		return (1);
	make_sim(&sim, argc, argv);
	start(&sim);
	pthread_mutex_destroy(&sim.lock);
	while (sim.philocount--)
		pthread_mutex_destroy(&sim.fork[sim.philocount].flock);
	return (0);
}
