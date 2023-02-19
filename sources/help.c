/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:20:27 by troudot           #+#    #+#             */
/*   Updated: 2023/02/19 15:29:26 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	ft_help(void)
{
	ft_putstr_fd("+===============  Available Fractals  ===============+\n\n", 1);
	ft_putstr_fd("Which fractal would you like to view?\n", 1);
	ft_putstr_fd("\tMandelbrot\n", 1);
	ft_putstr_fd("\tJulia\n", 1);
	ft_putstr_fd("\tBurning Ship\n", 1);
	ft_putstr_fd("\n\e[36mUsage example:\t./fract-ol <type>\n", 1);
	ft_putstr_fd("\nFor Julia, you may specify starting values for the\n", 1);
	ft_putstr_fd("initial fractal shape. Values must be between\n", 1);
	ft_putstr_fd("-2.0 and 2.0 and must contain a decimal point.\n", 1);
	ft_putstr_fd("\n\e[36mUsage example:\t", 1);
	ft_putstr_fd("./fract-ol Julia\n\t\t./fract-ol Julia 0.285 0.01\e[0m\n", 1);
	exit(1);
}
