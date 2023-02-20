/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:31:11 by troudot           #+#    #+#             */
/*   Updated: 2023/02/20 12:56:32 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	init_complex(t_f *f)
{
	if (!ft_strcmp_lower(f->set, "mandelbrot")
		|| !ft_strcmp_lower(f->set, "burningship"))
	{
		f->min_r = -4.0;
		f->max_r = 4.0;
		f->min_i = -4.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else if (!ft_strcmp_lower(f->set, "julia"))
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
}

void	ft_move(t_f *f, double move, char *dir)
{
	double	middle_r;
	double	middle_i;

	middle_r = f->max_r - f->min_r;
	middle_i = f->max_i - f->min_i;
	if (!ft_strcmp_lower(dir, "right"))
	{
		f->min_r += middle_r * move;
		f->max_r += middle_r * move;
	}
	else if (!ft_strcmp_lower(dir, "left"))
	{
		f->min_r -= middle_r * move;
		f->max_r -= middle_r * move;
	}
	else if (!ft_strcmp_lower(dir, "up"))
	{
		f->min_i -= middle_i * move;
		f->max_i -= middle_i * move;
	}
	else if (!ft_strcmp_lower(dir, "down"))
	{
		f->min_i += middle_i * move;
		f->max_i += middle_i * move;
	}
}

void	ft_zoom(t_f *f, double zoom)
{
	double	middle_r;
	double	middle_i;

	middle_r = f->min_r - f->max_r;
	middle_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (middle_r - zoom * middle_r) / 2;
	f->min_r = f->max_r + zoom * middle_r;
	f->min_i = f->min_i + (middle_i - zoom * middle_i) / 2;
	f->max_i = f->min_i + zoom * middle_i;
}
