/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:38:39 by troudot           #+#    #+#             */
/*   Updated: 2022/12/10 09:42:21 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	m;
	int		len;

	m = (long) n;
	len = ft_len(m);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (m < 0)
		m = m * -1;
	str += len;
	*str = '\0';
	if (m == 0)
		*--str = '0';
	while (m > 0)
	{
		*--str = m % 10 + '0';
		m /= 10;
	}
	if (n < 0)
		*--str = '-';
	return (str);
}
