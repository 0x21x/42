/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp_lower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:31:40 by troudot           #+#    #+#             */
/*   Updated: 2023/02/17 20:45:58 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	ft_strcmp_lower(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((to_lower(s1[i]) || to_lower(s2[i]))
		&& (to_lower(s1[i]) == to_lower(s2[i])))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
