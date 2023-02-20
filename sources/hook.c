/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 06:27:25 by troudot           #+#    #+#             */
/*   Updated: 2023/02/20 13:32:26 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include "libft.h"

static void	ft_hook_config(int key, t_f *f)
{
	if (key == KEY_ARROW_UP)
		ft_zoom(f, 0.5);
	if (key == KEY_ARROW_DOWN)
		ft_zoom(f, 2);
}

static void	ft_hook_move(int key, t_f *f)
{
	if (key == KEY_W)
		ft_move(f, 0.2, "up");
	if (key == KEY_S)
		ft_move(f, 0.2, "down");
	if (key == KEY_D)
		ft_move(f, 0.2, "left");
	if (key == KEY_A)
		ft_move(f, 0.2, "right");
	if (key == KEY_C)
	{
		if (f->color_i == 3)
			f->color_i = 0;
		f->color_i += 1;
	}
}

static void	ft_hook_julia(int key, t_f *f)
{
	if (key == KEY_ARROW_RIGHT)
	{
		f->complex.x += 0.010;
		if (f->complex.y)
			f->complex.y += 0.010;
	}
	if (key == KEY_ARROW_LEFT)
	{
		f->complex.x -= 0.010;
		if (f->complex.y)
			f->complex.y -= 0.010;
	}
}

int	ft_mouse_pos(int button, int x, int y, t_f *f)
{
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	if (button == 5)
	{
		ft_zoom(f, 0.5);
		if (x < 0)
			ft_move(f, (double)x / WIDTH, "right");
		else if (x > 0)
			ft_move(f, (double)x * -1 / WIDTH, "left");
		if (y < 0)
			ft_move(f, (double)y / HEIGHT, "up");
		else if (y > 0)
			ft_move (f, (double)y * -1 / HEIGHT, "down");
	}
	else if (button == 4)
		ft_zoom(f, 2);
	render(f);
	return (0);
}

int	ft_hook_key(int key, void *param)
{
	t_f	*f;

	f = (t_f *) param;
	if (key == KEY_ESCAPE)
		exit(0);
	if (key == KEY_W || key == KEY_S || key == KEY_D || key == KEY_A
		|| key == KEY_C)
		ft_hook_move(key, f);
	if ((key == KEY_ARROW_LEFT || key == KEY_ARROW_RIGHT)
		&& (ft_strcmp_lower(f->set, "julia") == 0
			|| ft_strcmp_lower(f->set, "multi_julia") == 0))
		ft_hook_julia(key, f);
	if (key == KEY_ARROW_UP || key == KEY_ARROW_DOWN)
		ft_hook_config(key, f);
	render(f);
	return (0);
}
