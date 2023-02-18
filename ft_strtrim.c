/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 07:03:13 by troudot           #+#    #+#             */
/*   Updated: 2022/11/27 10:25:21 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	char_in_charset(char c, char const *set)
// {
// 	int	i;

// 	i = -1;
// 	while (set[++i])
// 		if (set[i] == c)
// 			return (1);
// 	return (0);
// }

// static int	ft_cnt_start(char const *s1, char const *set)
// {
// 	size_t	i;
// 	size_t	j;

// 	j = 0;
// 	i = 0;
// 	while (i >= 0 && j <= (ft_strlen(set) - 1))
// 	{
// 		if (s1[i] == set[j])
// 		{
// 			j = 0;
// 			i++;
// 			continue ;
// 		}
// 		j++;
// 	}
// 	return (i);
// }

// static int	ft_cnt_finish(char const *s1, char const *set)
// {
// 	size_t	i;
// 	size_t	j;

// 	j = 0;
// 	i = ft_strlen(s1) - 1;
// 	while (i >= 0 && j <= (ft_strlen(set - 1)))
// 	{
// 		if (s1[i] == set[j])
// 		{
// 			j = 0;
// 			i--;
// 			continue ;
// 		}
// 		j++;
// 	}
// 	return (i);
// }

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	int		i;
// 	int		size;
// 	char	*str;

// 	i = 0;
// 	size = 0;
// 	if (!s1)
// 		return (0);
// 	if (!set)
// 		return (ft_strdup(s1));
// 	while (char_in_charset(s1[i], set))
// 		i++;
// 	size = (ft_cnt_finish(s1, set) - ft_cnt_start(s1, set));
// 	str = (char *)malloc((size) * sizeof(char) + 1);
// 	if (!str)
// 		return (0);
// 	ft_strlcpy(str, s1 + i, size);
// 	return (str);
// }

static int	ft_checktrim(char c, char const *set)
{
	int		i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

static int	ft_get_size(char const *s1, char const *set)
{
	int		i;
	int		size;

	size = ft_strlen(s1);
	i = 0;
	while (ft_checktrim(s1[size - i - 1], set))
		i++;
	return (size - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = 0;
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	while (ft_checktrim(s1[i], set))
		i++;
	if (i == (int)ft_strlen(s1))
		return (ft_strdup(""));
	size = ft_get_size(s1 + i, set) + 1;
	str = (char *)malloc((size) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s1 + i, size);
	return (str);
}
