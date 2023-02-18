/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:30:46 by troudot           #+#    #+#             */
/*   Updated: 2023/02/07 09:39:05 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes the last element of the list and puts it at the front of the list
 * 
 * @param stacksA The stack to rotate
 * @param as_print if true, the function will print the operation name.
 * 
 * @return the last node of the list.
 */
void	rra(t_lst **stacksA, bool as_print)
{
	t_lst	*temp;

	if (!*stacksA || ft_lstsize(*stacksA) == 1)
		return ;
	temp = ft_lstlast(*stacksA);
	if ((*stacksA)->next)
		temp->prev->next = 0;
	ft_lstadd_front(stacksA, temp);
	if (as_print == true)
		ft_putstr_fd("rra\n", 1);
}

/**
 * It takes the last node of the list and makes it the first node of the list
 * 
 * @param stacksB The address of the head of the linked list.
 * @param as_print if true, the function will print the operation name.
 * 
 * @return the last node of the list.
 */
void	rrb(t_lst **stacksB, bool as_print)
{
	t_lst	*temp;

	if (!*stacksB || ft_lstsize(*stacksB) == 1)
		return ;
	temp = ft_lstlast(*stacksB);
	if ((temp)->prev)
		temp->prev->next = 0;
	ft_lstadd_front(stacksB, temp);
	if (as_print == true)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_lst **stacksA, t_lst **stacksB, bool as_print)
{
	rra(stacksA, false);
	rrb(stacksB, false);
	if (as_print == true)
		ft_putstr_fd("rrr\n", 1);
}
