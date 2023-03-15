/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 06:10:14 by troudot           #+#    #+#             */
/*   Updated: 2023/03/15 19:59:59 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * It sleeps for a given amount of time
 * 
 * @param philo a pointer to the philosopher
 * @param delay the time to sleep in milliseconds
 */
void	ft_sleep(t_philo *philo, size_t delay)
{
	delay += ft_time();
	while (philo->rule->running && delay > ft_time())
		usleep(100);
}

/**
 * It returns the current time in milliseconds
 * 
 * @return The time in milliseconds.
 */
size_t	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

/**
 * It checks if any of the philosophers have died or eaten enough
 * 
 * @param philo a pointer to the t_philo structure
 */
static void	ft_thread_handler(t_philo *philo)
{
	size_t	i;
	size_t	ate;

	while (philo->rule->running)
	{
		i = 0;
		ate = philo->rule->me != 0;
		while (philo->rule->running && i < philo->rule->nop)
		{
			pthread_mutex_lock(&philo->philos[i].lock);
			if (philo->philos[i].time_left < ft_time())
			{
				ft_philos_print(philo, TEXT_DIE, i);
				philo->rule->running = 0;
			}
			if (ate && philo->philos[i].ate < philo->rule->me)
				ate = 0;
			pthread_mutex_unlock(&philo->philos[i].lock);
			i++;
		}
		if (ate)
			philo->rule->running = 0;
	}
}

/**
 * It creates an array of arguments for each thread
 * 
 * @param philo the main structure containing all 
 * the information about the simulation
 * 
 * @return An array of t_arg structs.
 */
static t_arg	*ft_thread_arg(t_philo *philo)
{
	t_arg	*arg;
	size_t	i;

	i = 0;
	arg = malloc(sizeof(t_arg) * philo->rule->nop);
	if (!arg)
		(printf("%s\n", ERROR_MALLOC), exit(1));
	while (i < philo->rule->nop)
	{
		arg[i].philo = philo;
		arg[i].uid = i;
		arg[i].self = &philo->philos[i];
		arg[i].forks = ft_fork_get(philo, i);
		i++;
	}
	return (arg);
}

/**
 * It creates the threads,
 * and then waits for them to finish
 * 
 * @param philo the main structure that contains all 
 * the information about the philosophers
 */
int	ft_thead(t_philo *philo)
{
	t_arg	*arg;
	size_t	i;

	philo->philos = ft_philos_generate(philo);
	philo->fork = ft_init_fork(philo);
	philo->philos->start_time = ft_time();
	arg = ft_thread_arg(philo);
	if (!philo->rule || !philo->fork || !arg)
		return (0);
	i = 0;
	while (i < philo->rule->nop)
	{
		if (pthread_create(&philo->philos[i].thread,
				0, &ft_philos_loop, (void *) &arg[i]) != 0)
			(printf("%s\n", ERROR_THREAD), exit(1));
		i++;
	}
	ft_thread_handler(philo);
	i = 0;
	while (i < philo->rule->nop)
	{
		pthread_join(philo->philos[i].thread, 0);
		i++;
	}
	return (1);
}
