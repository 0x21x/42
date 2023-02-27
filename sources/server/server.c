/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:26:36 by troudot           #+#    #+#             */
/*   Updated: 2023/02/27 03:49:32 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	putnbr(int nbr)
{
	char	*base;

	base = "0123456789";
	if (nbr > 9)
		putnbr(nbr / 10);
	write(1, &base[nbr % 10], 1);
}

void	ft_receive_char(int sig, siginfo_t *siginfo, void *context)
{
	static char	c;
	static int	bit;

	(void)context;
	(void)siginfo;
	if (sig == SIGUSR1)
		c += 1 << bit;
	if (bit >= 8)
	{
		write(1, &c, 1);
		c = 0;
		bit = 0;
		return ;
	}
	++bit;
}

int	main(void)
{
	struct sigaction	sa;

	putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_receive_char;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (true)
		pause();
	return (0);
}
