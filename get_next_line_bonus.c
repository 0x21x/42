/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:36:55 by troudot           #+#    #+#             */
/*   Updated: 2022/11/29 22:45:37 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//return (1) if he are \n in the line else return (0)
int	check_if_return(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = ft_strlen(str, 1);
	while (++i < j)
		if (str[i] == '\n')
			return (1);
	return (0);
}

char	*next_line(char *str)
{
	char	*new;
	int		i;
	int		j;

	j = ft_strlen(str, 2);
	if (!str[j])
	{
		free(str);
		return (NULL);
	}
	new = malloc(ft_strlen(str, 1) - j + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (str[j])
		new[i++] = str[j++];
	new[i] = 0;
	free(str);
	return (new);
}

char	*get_get_cut_line(char *str)
{
	int			i;
	char		*tmp;

	i = 0;
	if (!*str)
		return (NULL);
	tmp = malloc(sizeof(char) * ft_strlen(str, 2) + 1);
	if (!tmp)
		return (NULL);
	i = -1;
	while (str[++i] != '\n' && str[i])
		tmp[i] = str[i];
	if (str[i] == '\n')
		tmp[i++] = '\n';
	tmp[i] = '\0';
	return (tmp);
}

char	*get_the_line(int fd, char *str)
{
	int				a;
	char			*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	a = 1;
	while (a && !check_if_return(str))
	{
		a = read(fd, buffer, BUFFER_SIZE);
		if (a == -1)
		{
			if (str)
				free(str);
			free(buffer);
			return (NULL);
		}
		buffer[a] = 0;
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[MAX_FILE_DESCRIPTOR];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str[fd] = get_the_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = get_get_cut_line(str[fd]);
	str[fd] = next_line(str[fd]);
	return (line);
}
