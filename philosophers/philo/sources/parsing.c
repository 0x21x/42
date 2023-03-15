/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:39:02 by troudot           #+#    #+#             */
/*   Updated: 2023/03/15 19:59:25 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * It takes a string, and returns the integer value of that string
 * 
 * @param str This is the string that we are converting to an integer.
 * 
 * @return The value of the string converted to an integer.
 */
int	ft_atoi(const char *str)
{
	int		value;
	int		sign;

	value = 0;
	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		value *= 10;
		value += *str - '0';
		str++;
	}
	return (value * sign);
}

/**
 * It checks if the string is a number.
 * 
 * @param arr The array of strings to be checked.
 * 
 * @return The function is_digit is returning a boolean value.
 */
void	ft_is_digit(char **arr)
{
	int	i;
	int	j;

	i = -1;
	while (arr[++i])
	{
		j = -1;
		if ((arr[i][0] == 45 || arr[i][0] == 43)
			&& (arr[i][1] <= '9' && arr[i][1] >= '0'))
			return (printf("%s\n", ERROR_PARSE_ARGS), exit(1));
		while (arr[i][++j])
			if (arr[i][j] > '9' || arr[i][j] < '0')
				return (printf("%s\n", ERROR_PARSE_ARGS), exit(1));
	}
	return ;
}

/**
 * It parses the ruleuments given to the program and returns a 
 * structure containing the parsed ruleuments
 * 
 * @param rule the ruleuments passed to the program
 * 
 * @return A pointer to a t_rule struct.
 */
t_rule	*ft_parsing(int argc, char **argv)
{
	t_rule	*rule;

	ft_is_digit(argv);
	rule = (t_rule *)malloc(sizeof(t_rule));
	if (!rule)
		(printf("%s\n", ERROR_MALLOC), exit(1));
	rule->nop = ft_atoi(argv[0]);
	rule->ttd = ft_atoi(argv[1]);
	rule->tte = ft_atoi(argv[2]);
	rule->tts = ft_atoi(argv[3]);
	if (argc == 5)
		rule->me = ft_atoi(argv[4]);
	if (!rule->nop || !rule->ttd || !rule->tte || !rule->tts
		|| (argc == 5 && !rule->me))
		(printf("%s\n", ERROR_PARSE_ARGS), exit(1));
	rule->running = 1;
	return (rule);
}
