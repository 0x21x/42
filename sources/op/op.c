/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 06:53:14 by troudot           #+#    #+#             */
/*   Updated: 2023/02/07 09:38:27 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It swaps the first two elements of the list
 * 
 * @param stacksA a pointer to a pointer to the first element of the list
 * 
 * @return the address of the first node in the list.
 */
void	sa(t_lst **stacksA, bool as_print)
{
	t_element	*tmp;

	if (!ft_lstsize(*stacksA) || ft_lstsize(*stacksA) == 1)
		return ;
	tmp = ((*stacksA)->content);
	(*stacksA)->content = (*stacksA)->next->content;
	*stacksA = (*stacksA)->next;
	((*stacksA)->content) = tmp;
	*stacksA = (*stacksA)->prev;
	if (as_print == true)
		ft_putstr_fd("sa\n", 1);
}

/**
 * It swaps the first two elements of a linked list
 * 
 * @param stacksB a pointer to a pointer to the first node of the linked list
 * 
 * @return the address of the first node in the list.
 */
void	sb(t_lst **stacksB, bool as_print)
{
	t_element	*tmp;

	if (!*stacksB || ft_lstsize(*stacksB) == 1)
		return ;
	tmp = ((*stacksB)->content);
	(*stacksB)->content = (*stacksB)->next->content;
	*stacksB = (*stacksB)->next;
	((*stacksB)->content) = tmp;
	*stacksB = (*stacksB)->prev;
	if (as_print == true)
		ft_putstr_fd("sb\n", 1);
}

/**
 * Swap the first two elements of stack A and stack B.
 * 
 * @param stacksA a pointer to a pointer to a t_lst.
 * @param stacksB a pointer to a pointer to a t_lst.
 */
void	ss(t_lst **stacksA, t_lst **stacksB)
{
	sa(stacksA, false);
	sb(stacksB, false);
	ft_putstr_fd("ss\n", 1);
}

/**
 * It takes the first element of stack A and puts it at the beginning of stack B.
 * 
 * @param stacksA a pointer to a pointer to the first node of the stack A
 * @param stacksB a pointer to the head of the linked list of stack B
 */
void	pb(t_lst **stacksA, t_lst **stacksB, bool as_print)
{
	t_lst	*temp;

	if (!*stacksA)
		return ;
	temp = *stacksA;
	*stacksA = (*stacksA)->next;
	if (*stacksA)
		(*stacksA)->prev = 0;
	ft_lstadd_front(stacksB, temp);
	if (as_print == true)
		ft_putstr_fd("pb\n", 1);
}

/**
 * It takes the first element of stack B and puts it at the beginning of stack A.
 * 
 * @param stacksA The address of the head of the stack A.
 * @param stacksB The stack that we are taking the first element from.
 */
void	pa(t_lst **stacksA, t_lst **stacksB, bool as_print)
{
	t_lst	*temp;

	if (!*stacksB)
		return ;
	temp = *stacksB;
	*stacksB = (*stacksB)->next;
	if (*stacksB)
		(*stacksB)->prev = 0;
	ft_lstadd_front(stacksA, temp);
	if (!*stacksB)
		*stacksB = 0;
	if (as_print == true)
		ft_putstr_fd("pa\n", 1);
}
