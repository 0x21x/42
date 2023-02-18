/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 03:44:53 by troudot           #+#    #+#             */
/*   Updated: 2023/02/18 08:02:25 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It checks if there are any duplicates in the list
 * 
 * @param list The list to check for duplicates.
 * 
 * @return a boolean value.
 */
bool	ft_check_duplicate(t_lst *list)
{
	long long int	tmp;
	t_lst			*temp;

	while (list)
	{
		tmp = list->content->value;
		list = list->next;
		temp = list;
		while (temp)
		{
			if (tmp == temp->content->value)
				return (false);
			temp = temp->next;
		}
	}
	return (true);
}

/**
 * It checks if the list of numbers is within the range of an int
 * 
 * @param list a pointer to the first element of the list
 * 
 * @return The function is_int is returning a boolean value.
 */
bool	ft_is_int(t_lst *list)
{
	long long int	tmp;

	while (list)
	{
		*&tmp = list->content->value;
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (false);
		list = list->next;
	}
	return (true);
}

/**
 * It checks if the string is a number.
 * 
 * @param arr The array of strings to be checked.
 * 
 * @return The function is_digit is returning a boolean value.
 */
bool	ft_is_digit(char **arr)
{
	int	i;
	int	j;

	i = -1;
	while (arr[++i])
	{
		j = -1;
		if ((arr[i][0] == 45 || arr[i][0] == 43)
			&& (arr[i][1] <= '9' && arr[i][1] >= '0'))
			j++;
		while (arr[i][++j])
			if (arr[i][j] > '9' || arr[i][j] < '0')
				return (false);
	}
	return (true);
}

bool	ft_error(t_lst *list, char **arr)
{
	if (!ft_is_int(list))
		return (false);
	if (!ft_check_duplicate(list))
		return (false);
	if (!ft_is_digit(arr))
		return (false);
	return (true);
}

/**
 * It parses the arguments and creates a linked list
 * 
 * @param argc the number of arguments passed to the program
 * @param argv the array of arguments passed to the program
 * @param list a pointer to a pointer to a t_lst.
 * 
 * @return the number of elements in the list.
 */
void	ft_parsing(int argc, char **argv, t_lst **list)
{
	char			**arr;
	t_element		*element;
	int				i;

	i = -1;
	if (argc == 1)
		exit(0);
	if (argc < 2)
		(ft_putstr_fd("\x1B[38;5;1mError\x1B[0m\n", 2), exit(2));
	if (argc == 2)
		arr = ft_split(argv[1], ' ');
	else
		arr = &argv[1];
	if (!arr[i + 1])
		(ft_putstr_fd("\x1B[38;5;1mError\x1B[0m\n", 2), exit(2));
	while (arr[++i])
	{
		element = malloc(sizeof(t_element));
		element->value = ft_atoi(arr[i]);
		ft_lstadd_back(list, ft_lstnew(element));
	}
	if (!ft_error(*list, arr))
		(ft_putstr_fd("\x1B[38;5;1mError\x1B[0m\n", 2), exit(2));
	return ;
}
