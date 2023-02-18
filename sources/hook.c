/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 06:27:25 by troudot           #+#    #+#             */
/*   Updated: 2023/02/18 04:57:09 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include "libft.h"

static void	ft_hook_config(int key, t_f *f)
{
	if (key == KEY_R)
	{
		f->zoom = 1;
		f->color_i = 1;
		f->complex.x = f->save.x;
		f->complex.y = f->save.y;
		f->move_y = 0;
		f->move_x = 0;
	}
}

static void	ft_hook_move(int key, t_f *f)
{
	if (key == KEY_W)
		f->move_y -= 10;
	if (key == KEY_S)
		f->move_y += 10;
	if (key == KEY_D)
		f->move_x -= 10;
	if (key == KEY_A)
		f->move_x += 10;
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
	(void)x;
	(void)y;
	if (button == 5)
		f->zoom *= 1.5;
	else if (button == 4 && f->zoom / 1.5 >= 1)
		f->zoom /= 1.5;
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
	if (key == KEY_P || key == KEY_R || key == KEY_T || key == KEY_O)
		ft_hook_config(key, f);
	render(f);
	return (0);
}
