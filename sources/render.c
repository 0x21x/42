/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 04:44:05 by troudot           #+#    #+#             */
/*   Updated: 2023/02/22 01:39:21 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static void	ft_menu(t_f *f)
{
	int	y;

	y = 0;
	mlx_string_put(f->mlx->mlx, f->mlx->win, 15, y += 10,
		0xFFFFFF, "Zoom          : SCROLL");
	mlx_string_put(f->mlx->mlx, f->mlx->win, 15, y += 20,
		0xFFFFFF, "Move          : WASD");
	mlx_string_put(f->mlx->mlx, f->mlx->win, 15, y += 20,
		0xFFFFFF, "Color         : C");
	if (ft_strcmp_lower(f->set, "julia") == 0)
		mlx_string_put(f->mlx->mlx, f->mlx->win, 15, y += 20,
			0xFFFFFF, "Change        : LEFT/RIGHT");
}

int	ft_color(int i, t_f *f)
{
	if (i == f->max_iterations || i == 0)
		return (0x000000);
	else if (i >= 1 && i < f->max_iterations && f->color_i == 1)
		return (0xF00000 * 11 * 0.01 * i * 10);
	else if (i >= 1 && i < f->max_iterations && f->color_i == 2)
		return (0x0080FF * 7 * 0.01 * i);
	else if (i >= 1 && i < f->max_iterations && f->color_i == 3)
		return (0x00000F * i);
	return (0x000000);
}

void	ft_draw_pixel(t_f *f, int x, int y, int color)
{
	int			i;

	i = (x * f->mlx->bits_per_pixel / 8)
		+ (y * f->mlx->size_line);
	f->mlx->data_addr[i] = color;
	f->mlx->data_addr[++i] = color >> 8;
	f->mlx->data_addr[++i] = color >> 16;
}

void	render(t_f *f)
{
	ft_bzero(f->mlx->data_addr, WIDTH * HEIGHT * (f->mlx->bits_per_pixel / 8));
	f->y = -1;
	while (++f->y < HEIGHT)
	{
		f->x = -1;
		while (++f->x < WIDTH)
		{
			if (ft_strcmp_lower(f->set, "mandelbrot") == 0)
				ft_draw_pixel(f, f->x, f->y, ft_color(mandelbrot(f), f));
			else if (ft_strcmp_lower(f->set, "julia") == 0)
				ft_draw_pixel(f, f->x, f->y, ft_color(julia(f), f));
			else if (ft_strcmp_lower(f->set, "burningship") == 0)
				ft_draw_pixel(f, f->x, f->y, ft_color(burningship(f), f));
		}
	}
	mlx_put_image_to_window(f->mlx->mlx, f->mlx->win, f->mlx->img, 0, 0);
	ft_menu(f);
}
