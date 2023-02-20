/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:07:36 by troudot           #+#    #+#             */
/*   Updated: 2023/02/20 13:34:58 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burningship(t_f *f)
{
	t_number	number;
	double		temp;
	int			i;

	i = -1;
	number.x = (f->min_r + f->x * (f->max_r - (f->min_r)) / WIDTH);
	number.y = (f->max_i + f->y * (f->min_i - f->max_i) / HEIGHT);
	f->complex.x = number.x;
	f->complex.y = number.y;
	while (++i < f->max_iterations)
	{
		if ((number.y * number.y + number.x * number.x) > 4)
			break ;
		number.x = fabs(number.x);
		number.y = fabs(number.y);
		temp = 2.0 * number.x * number.y + f->complex.y;
		number.x = number.x * number.x - number.y * number.y + f->complex.x;
		number.y = temp;
	}
	return (i);
}
