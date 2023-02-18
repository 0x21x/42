/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:35:57 by troudot           #+#    #+#             */
/*   Updated: 2023/02/07 03:46:48 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_big_chunk(t_lst *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (((t_element *)stack->content)->chunk > i)
			i = ((t_element *)stack->content)->chunk;
		stack = stack->next;
	}
	return (i);
}

int	big_rank(t_lst *stack)
{
	int	rank;

	rank = 0;
	while (stack)
	{
		if (((t_element *)(stack)->content)->rank > rank)
			rank = ((t_element *)(stack)->content)->rank;
		stack = stack->next;
	}
	return (rank);
}

int	low_rank(t_lst *stack)
{
	int	rank;

	rank = big_rank(stack) + 1;
	while (stack)
	{
		if (((t_element *)(stack)->content)->rank < rank
			&& ((t_element *)(stack)->content)->chunk == check_big_chunk(stack))
			rank = ((t_element *)(stack)->content)->rank;
		stack = stack->next;
	}
	return (rank);
}

/**
 * It returns the position of the biggest element in the stack
 * 
 * @param stacks a pointer to a pointer to a t_list.
 * 
 * @return The position of the max value in the stack.
 */
int	get_position_maxsize(t_lst *stacks)
{
	long long int	top;
	int				i;
	int				j;

	i = 1;
	j = 1;
	top = (stacks)->content->value;
	while (stacks)
	{
		if (top < (stacks)->content->value)
		{
			top = (stacks)->content->value;
			j = i;
		}
		stacks = (stacks)->next;
		i++;
	}
	return (j);
}

/**
 * It returns the position of the smallest element in the stack
 * 
 * @param stacks a pointer to a pointer to a t_list.
 * 
 * @return The position of the smallest element in the stack.
 */
int	get_position_minsize(t_lst *stacks)
{
	long long int	bottom;
	int				i;
	int				j;

	i = 1;
	j = 1;
	bottom = (stacks)->content->value;
	while (stacks)
	{
		if (bottom > (stacks)->content->value)
		{
			bottom = (stacks)->content->value;
			j = i;
		}
		stacks = (stacks)->next;
		i++;
	}
	return (j);
}
