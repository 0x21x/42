/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 01:34:53 by troudot           #+#    #+#             */
/*   Updated: 2023/02/07 07:12:08 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	check_first(t_lst *stack)
{
	int	pos;
	int	big;

	big = big_rank(stack);
	pos = 0;
	while (stack)
	{
		if (((t_element *)(stack)->content)->rank == big)
			return (pos);
		stack = (stack)->next;
		pos++;
	}
	return (pos);
}

void	eco(int t, t_lst **stacksA, t_lst **stacksB, int size)
{
	if (t < (size / 2))
	{
		if ((*stacksB)->content->rank == big_rank(*stacksB) - 1)
			pa(stacksA, stacksB, true);
		else
			rb(stacksB, true);
	}
	else
	{
		if ((*stacksB)->content->rank == big_rank(*stacksB) - 1)
			pa(stacksA, stacksB, true);
		rrb(stacksB, true);
	}
}

void	sort_big(t_lst *stacksA, t_lst *stacksB, int chunk, int nbr_chunk)
{
	int	t;

	ft_chunking(&stacksA, &stacksB, nbr_chunk);
	while (stacksB)
	{
		chunk = check_big_chunk(stacksB);
		while (check_big_chunk(stacksB) == chunk)
		{
			t = check_first(stacksB);
			if (t < (ft_lstsize(stacksB)) / 2)
				while (t--)
					eco(t, &stacksA, &stacksB, ft_lstsize(stacksB));
			else
				while (++t < (ft_lstsize(stacksB) + 1))
					eco(t, &stacksA, &stacksB, ft_lstsize(stacksB));
			if (stacksA && stacksB->content->rank == big_rank(stacksB)
				&& stacksA->content->rank == big_rank(stacksB) - 1)
				(pa(&stacksA, &stacksB, true), sa(&stacksA, true));
			else if (stacksB->content->rank == big_rank(stacksB))
				pa(&stacksA, &stacksB, true);
		}
	}
}

int	ft_nbr_chunk(int size)
{
	if (size > 5 && size <= 10)
		return (2);
	else if (size > 10 && size < 30)
		return (3);
	else if (size > 30 && size <= 70)
		return (5);
	else if (size > 70 && size <= 99)
		return (7);
	else if (size > 99 && size < 150)
		return (8);
	else if (size > 150 && size < 200)
		return (10);
	else if (size > 200 && size < 300)
		return (13);
	else if (size > 300 && size < 400)
		return (15);
	else if (size > 400 && size <= 500)
		return (17);
	else if (size > 500 && size < 600)
		return (19);
	else if (size >= 600 && size < 800)
		return (21);
	else if (size >= 800 && size < 1500)
		return (22);
	return (25);
}

void	ft_sorter(t_lst *stacksA, t_lst *stacksB)
{
	int	lst_size;
	int	chunk;
	int	nbr_chunk;

	nbr_chunk = ft_nbr_chunk(ft_lstsize(stacksA));
	chunk = 0;
	lst_size = ft_lstsize(stacksA);
	if (lst_size < 2)
		return ;
	else if (lst_size > 1 && lst_size < 4)
		sort_3(stacksA);
	else if (lst_size > 3 && lst_size <= 5)
		sort_5(stacksA, stacksB);
	else if (lst_size > 5 && lst_size < 10000)
		(sort_big(stacksA, stacksB, chunk, nbr_chunk));
}
