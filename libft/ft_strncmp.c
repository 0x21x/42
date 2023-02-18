/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 01:02:54 by troudot           #+#    #+#             */
/*   Updated: 2023/02/08 05:49:03 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while ((s1[i] || s2[i]) && (s1[i] == s2[i]) && n--)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
