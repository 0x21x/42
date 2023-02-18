/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:38:35 by troudot           #+#    #+#             */
/*   Updated: 2023/02/17 20:37:39 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_f *f)
{
	t_number	number;
	double		temp;
	int			i;
	int			max_i;

	i = -1;
	number.x = ((-2.0 + f->x * (2.0 - (-2.0)) / WIDTH) - f->move_x / 10)
		/ f->zoom;
	max_i = -2.0 + (2.0 - (-2.0)) * HEIGHT / WIDTH;
	number.y = ((max_i + f->y * (-2.0 - max_i) / HEIGHT) - f->move_y / 10)
		/ f->zoom;
	while (++i < f->max_iterations)
	{
		if (((number.y * number.y) + (number.x * number.x)) > 4)
			break ;
		temp = 2.0 * number.x * number.y + f->complex.y;
		number.x = ((number.x * number.x) - (number.y * number.y))
			+ f->complex.x;
		number.y = temp;
	}
	return (i);
}
