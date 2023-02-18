/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:14:21 by troudot           #+#    #+#             */
/*   Updated: 2023/01/22 20:14:23 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexa(unsigned long nbr, const char format, int *size)
{
	char			*hexa;
	unsigned long	nbr_modulo;
	static int		n;

	n = 0;
	if (format == 'X')
		hexa = "0123456789ABCDEF";
	else if (format == 'x' || format == 'p')
		hexa = "0123456789abcdef";
	if (nbr < 16 && !n)
	{
		nbr_modulo = nbr % 16;
		ft_putchar(hexa[nbr], size);
		if (*size == -1)
			n = -1;
		return ;
	}
	else
		ft_putnbr_hexa(nbr / 16, format, size);
	if (!n)
		ft_putnbr_hexa(nbr % 16, format, size);
}
