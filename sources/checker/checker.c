/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 03:38:35 by troudot           #+#    #+#             */
/*   Updated: 2023/02/18 08:01:29 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "op.h"

int	ft_slen(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

void	check_sort(t_lst *lista)
{
	int		rank;

	while (lista->next)
	{
		rank = lista->content->rank + 1;
		if (lista->next->content->rank != rank)
			(ft_putstr_fd("\x1B[38;5;1mKO\x1B[0m\n", 2), exit(2));
		lista = lista->next;
	}
	(ft_putstr_fd("\x1B[32;5;1mOK\x1B[0m\n", 1), exit(0));
}

void	ft_compare(const char *s, t_lst **a, t_lst **b)
{
	if (!ft_strncmp(s, "rra\n", ft_slen(s)))
		return (rra(a, false));
	else if (!ft_strncmp(s, "rrb\n", ft_slen(s)))
		return (rrb(b, false));
	else if (!ft_strncmp(s, "rrr\n", ft_slen(s)))
		return (rrr(a, b, false));
	else if (!ft_strncmp(s, "sa\n", ft_slen(s)))
		return (sa(a, false));
	else if (!ft_strncmp(s, "sb\n", ft_slen(s)))
		return (sb(b, false));
	else if (!ft_strncmp(s, "ss\n", ft_slen(s)))
		return (ss(a, b, false));
	else if (!ft_strncmp(s, "ra\n", ft_slen(s)))
		return (ra(a, false));
	else if (!ft_strncmp(s, "rb\n", ft_slen(s)))
		return (rb(b, false));
	else if (!ft_strncmp(s, "rr\n", ft_slen(s)))
		return (rr(a, b, false));
	else if (!ft_strncmp(s, "pa\n", ft_slen(s)))
		return (pa(a, b, false));
	else if (!ft_strncmp(s, "pb\n", ft_slen(s)))
		return (pb(a, b, false));
	else if (!ft_strncmp(s, "\n", 1))
		check_sort(*a);
	(ft_putstr_fd("\x1B[38;5;1mError\x1B[0m\n", 1), exit(2));
}

int	main(int argc, char **argv)
{
	t_lst	*lista;
	t_lst	*listb;
	char	*arr;

	lista = 0;
	listb = 0;
	ft_parsing(argc, argv, &lista);
	ft_ranking(lista);
	arr = get_next_line(0);
	while (arr)
	{
		(ft_compare(arr, &lista, &listb));
		arr = get_next_line(0);
	}
	check_sort(lista);
	return (0);
}
