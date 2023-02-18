/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:28:13 by troudot           #+#    #+#             */
/*   Updated: 2023/02/07 03:44:54 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It assigns a rank to each element of the stack, based on its value
 * 
 * @param stacks the list of elements to rank
 */
void	ft_ranking(t_lst *stacks)
{
	int		rank;
	t_lst	*tmp_stacks;
	t_lst	*tmp;

	rank = 1;
	tmp_stacks = stacks;
	while (stacks)
	{
		tmp = tmp_stacks;
		while (tmp)
		{
			if (tmp->content->value < stacks->content->value)
				rank++;
			tmp = tmp->next;
		}
		stacks->content->rank = rank;
		stacks = stacks->next;
		rank = 1;
	}
}
