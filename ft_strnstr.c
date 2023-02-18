/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 01:00:00 by troudot           #+#    #+#             */
/*   Updated: 2022/11/17 03:48:53 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!haystack && !len)
		return (0);
	if (!*needle)
		return ((char *) haystack);
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[++i])
	{
		while (haystack[i + j] == needle[j]
			&& haystack[i + j] && i + j < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		j = 0;
	}
	return (NULL);
}
