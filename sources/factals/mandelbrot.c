/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 03:10:04 by troudot           #+#    #+#             */
/*   Updated: 2023/02/19 15:06:52 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_f *f)
{
	t_number	number;
	double		temp;
	int			i;

	i = -1;
	number.x = (f->min_r + f->x * (f->max_r - (f->min_r)) / WIDTH) / f->zoom;
	number.y = (f->max_i + f->y * (f->min_i - f->max_i) / HEIGHT) / f->zoom;
	f->complex.x = number.x;
	f->complex.y = number.y;
	while (++i < f->max_iterations)
	{
		if ((pow(number.y, 2.00) + pow(number.x, 2.00)) > 4)
			break ;
		temp = 2.0 * number.x * number.y + f->complex.y;
		number.x = (pow(number.x, 2.00) - pow(number.y, 2.00)) + f->complex.x;
		number.y = temp;
	}
	return (i);
}
