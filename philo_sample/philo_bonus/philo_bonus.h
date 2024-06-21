/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:17:16 by cooi              #+#    #+#             */
/*   Updated: 2023/11/30 20:12:34 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_sim	t_sim;

typedef struct s_philo {
	int				id;
	int				mineat;
	int				eatcount;
	int				philocount;
	long			sleep;
	long			eat;
	long			die;
	long			lastmeal;
	long			start;
	t_sim			*sim;
}	t_philo;

typedef struct s_fork {
	int				avail;
}	t_fork;

typedef struct s_sim {
	int				philocount;
	int				mineat;
	int				pids[200];
	t_philo			philo[200];
	sem_t			*status;
	sem_t			*lock;
	sem_t			*fork;
}	t_sim;

void	make_philos(t_sim *sim, int argc, char **argv);
void	make_sim(t_sim	*sim, int argc, char **argv);
int		ft_atoi(const char *nb);
int		ft_isdigit(int c);
int		arg_error(int i);
int		check_args(int argc, char **argv);
void	simu(t_philo *p);
void	eatandsleep(t_philo *p, struct timeval time);
int		getsleeptime(t_philo p);
void	*checkdeath(void *philo);
void	print_status(t_philo p, struct timeval time, int pid, char *status);

#endif