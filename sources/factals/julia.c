/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:38:35 by troudot           #+#    #+#             */
/*   Updated: 2023/02/19 15:03:45 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_f *f)
{
	t_number	number;
	double		temp;
	int			i;

	i = -1;
	number.x = (f->min_r + f->x * (f->max_r - (f->min_r)) / WIDTH) / f->zoom;
	number.y = (f->max_i + f->y * (f->min_i - f->max_i) / HEIGHT) / f->zoom;
	while (++i < f->max_iterations)
	{
		if (pow(number.y, 2.0) + pow(number.x, 2.0) > 4)
			break ;
		temp = 2.0 * number.x * number.y + f->complex.y;
		number.x = (pow(number.x, 2.0) - pow(number.y, 2.0)) + f->complex.x;
		number.y = temp;
	}
	return (i);
}
