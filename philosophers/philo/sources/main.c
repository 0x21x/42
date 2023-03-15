/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:12:52 by troudot           #+#    #+#             */
/*   Updated: 2023/03/15 20:01:02 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		(printf("%s\n", ERROR_PARSE_ARGS), exit(1));
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		(printf("%s\n", ERROR_MALLOC), exit(1));
	philo->rule = ft_parsing(argc - 1, &argv[1]);
	ft_thead(philo);
	return (0);
}
