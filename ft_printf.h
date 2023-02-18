/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:14:10 by troudot           #+#    #+#             */
/*   Updated: 2023/01/22 20:14:14 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
void	ft_putstr(char *s, int *size);
void	ft_putchar(int c, int *size);
void	ft_putnbr(long long n, int *size);
void	ft_putnbr_hexa(unsigned long nbr, const char format, int *size);
void	ft_putunbr(unsigned int n, int *size);
void	check_arg(va_list param, const char *format, int *size);

#endif