/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:03:31 by troudot           #+#    #+#             */
/*   Updated: 2023/02/17 20:45:45 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	double	value;
	double	sign;

	value = 0.;
	sign = 1.;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1.;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		value *= 10;
		value += *str - '0';
		str++;
	}
	return (value * sign);
}
