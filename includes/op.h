/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 03:30:44 by troudot           #+#    #+#             */
/*   Updated: 2023/02/07 05:56:13 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include "libft.h"
# include "push_swap.h"

// Operator
void	sa(t_lst **stacksA, bool as_print);
void	sb(t_lst **stacksB, bool as_print);
void	ss(t_lst **stacksA, t_lst **stacksB, bool as_print);
void	pb(t_lst **stacksA, t_lst **stacksB, bool as_print);
void	pa(t_lst **stacksA, t_lst **stacksB, bool as_print);
void	ra(t_lst **stacksA, bool as_print);
void	rb(t_lst **stacksB, bool as_print);
void	rr(t_lst **stacksA, t_lst **stacksB, bool as_print);
void	rra(t_lst **stacksA, bool as_print);
void	rrb(t_lst **stacksB, bool as_print);
void	rrr(t_lst **stacksA, t_lst **stacksB, bool as_print);

#endif