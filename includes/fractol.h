/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 04:44:52 by troudot           #+#    #+#             */
/*   Updated: 2023/02/21 02:27:39 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "../MLX42/mlx.h"
# include <stdbool.h>

# ifndef WIDTH
#  define WIDTH 600
# endif

# ifndef HEIGHT
#  define HEIGHT 600
# endif

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_mlx;

typedef struct s_number
{
	double		x;
	double		y;
}	t_number;

typedef struct s_f
{
	t_mlx		*mlx;
	int			max_iterations;
	int			color_i;
	double		x;
	double		y;
	char		*set;
	t_number	complex;
	double		max_i;
	double		min_i;
	double		min_r;
	double		max_r;
}	t_f;

int		mandelbrot(t_f *f);
int		julia(t_f *f);
int		burningship(t_f *f);

void	render(t_f *f);
int		ft_hook_key(int key, void *param);
int		ft_mouse_pos(int button, int x, int y, t_f *f);
int		ft_mouse_scroll(int button, int x, int y, void *param);
void	ft_help(void);
void	init_complex(t_f *f);
void	ft_move(t_f *f, double move, char *dir);
void	ft_zoom(t_f *f, double zoom);

#endif