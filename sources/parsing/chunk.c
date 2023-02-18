/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:45:32 by troudot           #+#    #+#             */
/*   Updated: 2023/02/07 07:09:57 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_set_chunk(t_element *elem, int chunk)
{
	elem->chunk = chunk;
	return ;
}

/**
 * It checks if the list contains any elements with a rank between low and max
 * 
 * @param stack the list to check
 * @param low the lowest rank of the chunk
 * @param max the highest rank in the list
 * 
 * @return A boolean value.
 */
bool	ft_l(t_lst *stack, int low, int max)
{
	while (stack)
	{
		if (stack->content->rank >= low && stack->content->rank <= max)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	ft_chunk(t_lst **stackA, t_lst **stackB, int low, int size)
{
	int			j;

	j = 1;
	while (*stackA)
	{
		while (!ft_l(*stackA, low, (size * (j + 1))))
		{
			if (!*stackA)
				return ;
			if ((*stackA)->content->rank >= low
				&& (*stackA)->content->rank <= size * j)
			{
				(ft_set_chunk((*stackA)->content, j), pb(stackA, stackB, true));
			}
			else if ((*stackA)->content->rank > size * j
				&& (*stackA)->content->rank <= size * (j + 1))
				((ft_set_chunk((*stackA)->content, j),
						pb(stackA, stackB, true)), rb(stackB, true));
			else
				ra(stackA, true);
		}
		low = size * (j + 1);
		j += 2;
	}
}

void	ft_chunking(t_lst **stacksA, t_lst **stacksB, int nbr_chunk)
{
	int	low;
	int	size_chunk;

	low = 0;
	size_chunk = ft_lstsize(*stacksA) / nbr_chunk;
	ft_chunk(stacksA, stacksB, low, size_chunk);
	return ;
}
