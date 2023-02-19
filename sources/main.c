/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:22:47 by troudot           #+#    #+#             */
/*   Updated: 2023/02/19 15:48:02 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static int	ft_hook_terminate(void *param)
{
	(void) param;
	exit(0);
}

/**
 * It initializes the mlx library, creates a window, 
 * creates an image, hooks the terminate and key
 * events, renders the image, and loops the mlx library
 * 
 * @param f the fractal structure
 * 
 * @return the address of the first element of the array.
 */
void	init(t_f *f)
{
	f->mlx->mlx = mlx_init();
	if (!f->mlx)
		return (exit(2));
	f->mlx->win = mlx_new_window(f->mlx->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!f->mlx->win)
		return (exit(2));
	f->mlx->img = mlx_new_image(f->mlx->mlx, WIDTH, HEIGHT);
	if (!f->mlx->img)
		return (exit(2));
	f->mlx->data_addr = mlx_get_data_addr(f->mlx->img,
			&(f->mlx->bits_per_pixel), &(f->mlx->size_line),
			&(f->mlx->endian));
	mlx_hook(f->mlx->win, 17, 0, ft_hook_terminate, 0);
	mlx_hook(f->mlx->win, 2, 0, ft_hook_key, (void *) f);
	mlx_mouse_hook(f->mlx->win, ft_mouse_pos, (void *) f);
	f->y = -1;
	f->max_iterations = 100;
	render(f);
	mlx_loop(f->mlx->mlx);
}

/**
 * It checks the arguments passed to the program and sets the fractal
 * 
 * @param f a pointer to the structure that holds all 
 * the information about the fractal
 * @param argc the number of arguments passed to the program
 * @param argv the array of arguments passed to the program
 */
void	ft_arg(t_f *f, int argc, char **argv)
{
	(void)argc;
	if (ft_strcmp_lower(argv[0], "julia") == 0 && argc <= 3)
	{
		f->set = "julia";
		if (argv[1])
			f->complex.x = atof(argv[1]);
		else
			ft_help();
		if (argv[2])
			f->complex.y = atof(argv[2]);
	}
	else if (ft_strcmp_lower(argv[0], "mandelbrot") == 0 && argc == 1)
		f->set = "mandelbrot";
	else if (ft_strcmp_lower(argv[0], "burningship") == 0 && argc == 1)
		f->set = "burningship";
	else
		ft_help();
}

int	main(int argc, char **argv)
{
	t_f			*f;

	f = (t_f *) malloc(sizeof(t_f));
	if (!f)
		exit(2);
	f->mlx = (t_mlx *) malloc(sizeof(t_mlx));
	if (!f->mlx)
		exit(2);
	f->zoom = 1;
	f->color_i = 1;
	f->max_iterations = 10;
	if (argc > 1)
	{
		argc -= 1;
		ft_arg(f, argc, &argv[1]);
		init_complex(f);
		init(f);
	}
	else
		ft_help();
	return (0);
}
