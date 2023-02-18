/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 00:37:50 by troudot           #+#    #+#             */
/*   Updated: 2022/11/18 05:10:42 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (!dstsize)
		return (ft_strlen(src));
	j = ft_strlen(dst);
	i = -1;
	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	while (src[++i] && j + 1 < dstsize)
		dst[j++] = src[i];
	dst[j] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
