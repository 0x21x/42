/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:30:03 by troudot           #+#    #+#             */
/*   Updated: 2023/02/17 20:45:36 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = 0;
	if (!s)
		return ;
	while (s[len])
		ft_putchar_fd(s[len++], fd);
}
