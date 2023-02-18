/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 06:46:08 by troudot           #+#    #+#             */
/*   Updated: 2023/02/07 00:45:22 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*list;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	list = ft_lstlast(*lst);
	new->prev = list;
	list->next = new;
	new->next = 0;
}
