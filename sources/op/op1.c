/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 06:53:14 by troudot           #+#    #+#             */
/*   Updated: 2023/02/07 09:38:48 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It rotates the stack A to the top.
 * 
 * @param stacksA a pointer to the head of the linked list
 * @param as_print if true, the function will print the operation name.
 * 
 * @return the address of the first node in the list.
 */
void	ra(t_lst **stacksA, bool as_print)
{
	t_lst	*temp;

	if (!*stacksA || ft_lstsize(*stacksA) < 2)
		return ;
	temp = *stacksA;
	*stacksA = (*stacksA)->next;
	temp->next->prev = 0;
	ft_lstadd_back(stacksA, temp);
	if (as_print == true)
		ft_putstr_fd("ra\n", 1);
}

/**
 * It rotates the stack B to the top.
 * 
 * @param stacksB a pointer to the head of the linked list
 * @param as_print if true, the function will print the operation name.
 * 
 * @return the address of the first node in the list.
 */
void	rb(t_lst **stacksB, bool as_print)
{
	t_lst	*temp;

	if (!*stacksB || ft_lstsize(*stacksB) < 2)
		return ;
	temp = *stacksB;
	if ((*stacksB)->next)
		*stacksB = (*stacksB)->next;
	if ((temp)->next)
		temp->next->prev = 0;
	ft_lstadd_back(stacksB, temp);
	if (as_print == true)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_lst **stacksA, t_lst **stacksB, bool as_print)
{
	ra(stacksA, false);
	rb(stacksB, false);
	if (as_print == true)
		ft_putstr_fd("rr\n", 1);
}
