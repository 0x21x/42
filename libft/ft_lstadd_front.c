/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 04:42:53 by troudot           #+#    #+#             */
/*   Updated: 2023/02/07 00:45:24 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_lst **lst, t_lst *new)
{
	new->next = *lst;
	*lst = new;
	new->prev = 0;
	if (new->next)
		new->next->prev = new;
}
