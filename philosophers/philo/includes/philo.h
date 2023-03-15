/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:11:34 by troudot           #+#    #+#             */
/*   Updated: 2023/03/15 18:25:40 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include "error_msg.h"

/**
 * @param nop The number of philosophers.
 * @param ttd Time to die.
 * @param tte Time to eat.
 * @param tts Time to sleep.
 * @param me Max eat.
 */
typedef struct s_rule
{
	size_t		nop;
	size_t		ttd;
	size_t		tte;
	size_t		tts;
	size_t		me;
	size_t		running;
}	t_rule;

typedef struct s_philos
{
	size_t				id;
	pthread_mutex_t		lock;
	pthread_t			thread;
	size_t				ate;
	size_t				time_left;
	size_t				start_time;
}	t_philos;

typedef struct s_fork
{
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_philo
{
	t_rule			*rule;
	t_philos		*philos;
	t_fork			*fork;
	pthread_mutex_t	lock;
}	t_philo;

typedef struct s_arg
{
	t_philo		*philo;
	size_t		uid;
	t_philos	*self;
	t_fork		**forks;
}	t_arg;

# define TEXT_FORK			"has taken a fork"
# define TEXT_EAT			"is eating"
# define TEXT_SLEEP			"is sleeping"
# define TEXT_THINK			"is thinking"
# define TEXT_DIE			"died"

t_fork		**ft_fork_get(t_philo *philo, size_t i);
t_fork		*ft_init_fork(t_philo *philo);

t_rule		*ft_parsing(int argc, char **argv);

t_philos	*ft_philos_generate(t_philo *philo);
void		*ft_philos_loop(void *param);
void		ft_philos_print(t_philo *philo, char *s, size_t id);

int			ft_thead(t_philo *philo);
size_t		ft_time(void);
void		ft_sleep(t_philo *philo, size_t delay);
#endif
