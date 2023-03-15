/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 07:47:01 by troudot           #+#    #+#             */
/*   Updated: 2023/03/15 20:00:24 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	*ft_init_fork(t_philo *philo)
{
	t_fork		*fork;
	size_t		i;

	fork = malloc(sizeof(t_fork) * philo->rule->nop);
	if (!fork)
		(printf("%s\n", ERROR_MALLOC), exit(1));
	i = -1;
	while (++i < philo->rule->nop)
	{
		if (pthread_mutex_init(&fork[i].lock, 0))
			(printf("%s\n", ERROR_MUTEX), exit(1));
	}
	return (fork);
}

t_fork	**ft_fork_get(t_philo *philo, size_t i)
{
	t_fork	**fork;

	fork = (t_fork **) malloc(2 * sizeof(t_fork *));
	if (!fork)
		(printf("%s\n", ERROR_MALLOC), exit(1));
	fork[0] = &philo->fork[i];
	fork[1] = 0;
	if (i > 0)
		fork[1] = &philo->fork[i - 1];
	else if (philo->rule->nop > 1)
		fork[1] = &philo->fork[philo->rule->nop - 1];
	return (fork);
}
