/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:40:41 by troudot           #+#    #+#             */
/*   Updated: 2023/02/07 00:45:39 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstnew(void *content)
{
	t_lst	*list;

	list = (t_lst *) malloc(sizeof(t_lst));
	if (!list)
		return (0);
	list->content = content;
	list->prev = 0;
	list->next = 0;
	return (list);
}
