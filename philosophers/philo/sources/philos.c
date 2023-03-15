/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 02:44:36 by troudot           #+#    #+#             */
/*   Updated: 2023/03/15 20:02:14 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * It prints the time, the id of the philosopher, and the string passed to it
 * 
 * @param philo the current philosopher
 * @param s the string to print
 * @param id the id of the philosopher
 */
void	ft_philos_print(t_philo *philo, char *s, size_t id)
{
	pthread_mutex_lock(&philo->lock);
	if (philo->rule->running)
		printf("[%zu] %zu %s\n", ft_time() - philo->philos->start_time,
			id + 1, s);
	if (s[0] != 'd')
		pthread_mutex_unlock(&philo->lock);
}

/**
 * It creates a table of philosophers, 
 * each with a unique id, a time to die, a number of times they've
 * eaten, and a mutex lock
 * 
 * @param philo the main structure that contains all 
 * the information about the program
 * 
 * @return A pointer to a t_philos struct.
 */
t_philos	*ft_philos_generate(t_philo *philo)
{
	t_philos	*philos;
	size_t		i;

	philos = (t_philos *) malloc(philo->rule->nop * sizeof(t_philos));
	if (!philos)
		(printf("%s\n", ERROR_MUTEX), exit(1));
	i = 0;
	while (i < philo->rule->nop)
	{
		philos[i].id = i;
		philos[i].time_left = ft_time() + philo->rule->ttd;
		philos[i].ate = 0;
		if (pthread_mutex_init(&philos[i].lock, 0) != 0)
			(printf("%s\n", ERROR_MUTEX), exit(1));
		i++;
	}
	return (philos);
}

/**
 * It locks the first fork,
 * prints that it's taken, then locks the second fork, prints that it's taken,
 * locks the philosopher's own mutex, prints that it's eating, sets the time left
 * to the current time plus the time to eat, unlocks the philosopher's own mutex,
 * sleeps for the time to eat, locks the philosopher's own mutex, increments the
 * number of times it's eaten, unlocks the philosopher's own mutex, unlocks the
 * first fork, and unlocks the second fork
 * 
 * @param arg the argument passed to the thread
 * 
 * @return a pointer to a function that takes a pointer to a 
 * t_arg struct and returns nothing.
 */
static void	ft_philos_eat(t_arg *arg)
{
	pthread_mutex_lock(&arg->forks[0]->lock);
	ft_philos_print(arg->philo, TEXT_FORK, arg->uid);
	if (!arg->forks[1])
	{
		ft_sleep(arg->philo, arg->philo->rule->ttd * 2);
		return ;
	}
	pthread_mutex_lock(&arg->forks[1]->lock);
	ft_philos_print(arg->philo, TEXT_FORK, arg->uid);
	pthread_mutex_lock(&arg->self->lock);
	ft_philos_print(arg->philo, TEXT_EAT, arg->uid);
	arg->self->time_left = ft_time() + arg->philo->rule->ttd;
	pthread_mutex_unlock(&arg->self->lock);
	ft_sleep(arg->philo, arg->philo->rule->tte);
	pthread_mutex_lock(&arg->self->lock);
	arg->self->ate++;
	pthread_mutex_unlock(&arg->self->lock);
	pthread_mutex_unlock(&arg->forks[0]->lock);
	pthread_mutex_unlock(&arg->forks[1]->lock);
}

/**
 * It's a loop that makes the philosopher eat, sleep, and think
 * 
 * @param param the parameter passed to the thread
 * 
 * @return a void pointer.
 */
void	*ft_philos_loop(void *param)
{
	t_arg	*arg;

	arg = (t_arg *) param;
	if (arg->uid % 2)
		ft_sleep(arg->philo, arg->philo->rule->tte);
	while (arg->philo->rule->running)
	{
		ft_philos_eat(arg);
		if (!arg->philo->rule->running)
			return (0);
		ft_philos_print(arg->philo, TEXT_SLEEP, arg->uid);
		ft_sleep(arg->philo, arg->philo->rule->tts);
		if (!arg->philo->rule->running)
			return (0);
		ft_philos_print(arg->philo, TEXT_THINK, arg->uid);
	}
	return (0);
}
