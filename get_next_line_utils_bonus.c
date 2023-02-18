/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:40:01 by troudot           #+#    #+#             */
/*   Updated: 2022/11/29 08:40:02 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

size_t	ft_strlen(char *str, int z)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (z == 2)
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (str[i] == '\n')
			i++;
	}
	else if (z == 1)
		while (str[i])
			i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	if (!src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src, 1));
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src, 1));
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*s;

	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = 0;
	}
	if (!line || !buffer)
		return (NULL);
	s = malloc(sizeof(char) * (ft_strlen(line, 1) + ft_strlen(buffer, 1) + 1));
	if (!s)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy(s, line, ft_strlen(line, 1) + 1);
	ft_strlcpy(s + ft_strlen(line, 1), buffer, ft_strlen(buffer, 1) + 1);
	free(line);
	return (s);
}
