/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 05:14:17 by troudot           #+#    #+#             */
/*   Updated: 2023/02/08 05:12:41 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"

bool	already_sorted(t_lst *stacka)
{
	int	rank;

	while (stacka->next)
	{
		rank = stacka->content->rank + 1;
		if (stacka->next->content->rank != rank)
			return (false);
		stacka = stacka->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_lst	*a;
	t_lst	*b;

	a = 0;
	b = 0;
	ft_parsing(argc, argv, &a);
	ft_ranking(a);
	if (already_sorted(a) == false)
		ft_sorter(a, b);
	return (0);
}
