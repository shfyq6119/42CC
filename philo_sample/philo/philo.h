/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:17:16 by cooi              #+#    #+#             */
/*   Updated: 2023/11/30 17:48:17 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

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
	pthread_mutex_t	flock;
}	t_fork;

typedef struct s_sim {
	int				status;
	int				philocount;
	t_philo			philo[200];
	t_fork			fork[200];
	pthread_t		threads[200];
	pthread_mutex_t	lock;
}	t_sim;

int		arg_error(int i);
int		ft_isdigit(int c);
int		ft_atoi(const char *nb);
int		getsleeptime(t_philo p);
int		check_args(int argc, char **argv);
int		releaseforks(t_philo *p, int left, int right);
int		getforks(t_philo *p, struct timeval time, int getorrelease);
int		takeforks(t_philo *p, struct timeval time, int left, int right);
void	*simu(void *philo);
void	make_sim(t_sim	*sim, int argc, char **argv);
void	*eatandsleep(t_philo *p, struct timeval time);
void	make_philos(t_sim *sim, int argc, char **argv);
void	*deadornot(t_philo *philo, struct timeval time);
void	print_status(t_philo p, struct timeval time, int pid, char *status);
t_fork	make_fork(void);

#endif