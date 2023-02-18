/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:29:50 by troudot           #+#    #+#             */
/*   Updated: 2023/02/17 21:36:42 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int			ft_strcmp_lower(const char *s1, const char *s2);
double		ft_atof(const char *str);
void		ft_bzero(void *s, size_t n);
void		ft_putstr_fd(char *s, int fd);

#endif
