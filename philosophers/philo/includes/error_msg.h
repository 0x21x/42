/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:21:14 by troudot           #+#    #+#             */
/*   Updated: 2023/03/15 18:27:16 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# define ERROR_MALLOC		"An error occured while allocating memory."

# define ERROR_PARSE	 	"An error occured while parsing the arguments."
# define ERROR_PARSE_ARGS	"The given arguments are invalid. \
\n\e[35mUsage example:\t./philo <nop><ttd><tte><tts><me>\e[0m\n\n\
\e[36m*nop\t= The number of philosophers.\n\
*ttd\t= Time to die.\n\
*tte\t= Time to eat.\n\
*tts\t= Time to sleep.\n\
*me\t= Number of times each philosopher must eat "

# define ERROR_THREAD		"An error occured while creating a thread."
# define ERROR_MUTEX		"An error occured while creating a mutex."

#endif