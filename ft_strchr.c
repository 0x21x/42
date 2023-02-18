/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:43:18 by troudot           #+#    #+#             */
/*   Updated: 2022/11/16 23:46:47 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;

	str = ((unsigned char *)s) - 1;
	while (*++str != ((unsigned char)c))
		if (*str == 0)
			return (0);
	return ((char *)str);
}
