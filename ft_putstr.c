/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:14:30 by troudot           #+#    #+#             */
/*   Updated: 2023/01/22 20:14:31 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *size)
{
	int	i;

	i = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
		{
			*size = -1;
			return ;
		}
		*size += 6;
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], size);
		if (*size == -1)
			return ;
		i++;
	}
}
