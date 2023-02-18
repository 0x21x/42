/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:14:48 by troudot           #+#    #+#             */
/*   Updated: 2023/02/07 06:51:17 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_lst *A, t_lst *B)
{
	int	i;
	int	i2;

	i = 0;
	i2 = ft_lstsize(A) - 3;
	while (i < i2)
	{
		if (i2 == 2 && (A->content->rank == 2 || A->content->rank == 1) && ++i)
		{
			pb(&A, &B, true);
			continue ;
		}
		else if (i2 == 1 && A->content->rank == 1 && ++i)
		{
			pb(&A, &B, true);
			continue ;
		}
		ra(&A, true);
	}
	sort_3(A);
	if (ft_lstsize(B) == 2 && (B->content->rank < B->next->content->rank))
		sb(&B, true);
	while (i--)
		pa(&A, &B, true);
}

void	sort_3(t_lst *stacks)
{
	int	top;
	int	bottom;

	top = get_position_maxsize(stacks);
	bottom = get_position_minsize(stacks);
	if (top == 3 && bottom == 1)
		return ;
	else if ((top == 2 && bottom == 1) || (top == 3 && bottom == 2)
		|| (top == 1 && bottom == 3))
	{
		sa(&stacks, true);
		sort_3(stacks);
	}
	else if (top == 1 && bottom == 2)
		ra(&stacks, true);
	else if (top == 2 && bottom == 3)
		rra(&stacks, true);
	return ;
}
