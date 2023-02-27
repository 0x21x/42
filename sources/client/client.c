/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:49:42 by troudot           #+#    #+#             */
/*   Updated: 2023/02/27 03:26:29 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	value;
	int	sign;

	value = 0;
	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		++str;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10 + *str - '0';
		++str;
	}
	return (value * sign);
}

void	ft_send_char(int pid, unsigned char c)
{
	int	bit;

	bit = 0;
	if (!pid || !c)
		exit(0);
	while (bit <= 8)
	{
		if (c & 1 << bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(85);
		++bit;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	i = -1;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (!pid)
			exit(0);
		while (argv[2][++i])
			ft_send_char(pid, argv[2][i]);
	}
	return (0);
}
