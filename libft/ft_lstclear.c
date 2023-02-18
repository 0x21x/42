/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:34:05 by troudot           #+#    #+#             */
/*   Updated: 2023/02/07 00:45:31 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_lst **lst, void (*del)(void*))
{
	t_lst	*list;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		list = (*lst)->next;
		ft_lstdelone(*lst, *del);
		*lst = list;
	}
}
