/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 06:54:32 by troudot           #+#    #+#             */
/*   Updated: 2023/02/07 07:11:58 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "libft.h"
# include "parsing.h"
# include "op.h"

// Utils
int		get_position_maxsize(t_lst *stacks);
int		get_position_minsize(t_lst *stacks);
int		low_rank(t_lst *stack);
int		big_rank(t_lst *stack);
int		check_big_chunk(t_lst *stack);

// Sort
void	sort_3(t_lst *stacks);
void	sort_5(t_lst *stacksA, t_lst *stacksB);
void	sort_big(t_lst *stacksA, t_lst *stacksB, int chunk, int nbr_chunk);
void	ft_sorter(t_lst *stacksA, t_lst *stacksB);
void	ft_ranking(t_lst *stacks);
void	ft_chunking(t_lst **stacksA, t_lst **stacksB, int nbr_chunk);

#endif
