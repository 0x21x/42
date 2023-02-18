/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 04:38:27 by troudot           #+#    #+#             */
/*   Updated: 2022/12/15 02:04:41 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_char_in_charset(char c, char charset)
{
	return (c == charset);
}

static int	ft_count_word(char *str, char charset)
{
	size_t	c;

	c = 0;
	while (*str)
	{
		while (*str && is_char_in_charset(*str, charset))
			str++;
		if (*str)
			c++;
		while (*str && !is_char_in_charset(*str, charset))
			str++;
	}
	return (c);
}

static char	*ft_split_word(char *str, char charset)
{
	size_t		len;
	size_t		i2;
	size_t		i;
	char		*word;

	i = 0;
	i2 = 0;
	while (str[i2] && !is_char_in_charset(str[i2], charset))
		i2++;
	len = i2;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static int	ft_strisnul(char **strs, char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str && is_char_in_charset(*str, c))
			str++;
		if (*str)
		{
			strs[i++] = ft_split_word(str, c);
			if (!strs[i - 1])
			{
				--i;
				while (--i >= 0)
					free(strs[i]);
				free(strs);
				return (0);
			}
		}
		while (*str && !is_char_in_charset(*str, c))
			str++;
	}
	strs[i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (0);
	strs = malloc(sizeof(char *) * (ft_count_word((char *)s, c) + 1));
	if (!strs)
		return (0);
	if (!ft_strisnul(strs, (char *)s, c))
		return (0);
	return (strs);
}
