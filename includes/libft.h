/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 07:03:28 by troudot           #+#    #+#             */
/*   Updated: 2023/02/18 07:46:00 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FILE_DESCRIPTOR
#  define MAX_FILE_DESCRIPTOR 4096
# endif

typedef struct s_element
{
	long long int	value;
	int				rank;
	int				chunk;
}	t_element;

typedef struct s_list
{
	t_element			*content;
	struct s_list		*next;
	struct s_list		*prev;
}	t_lst;

// Libft
void			ft_lstadd_back(t_lst **lst, t_lst *new);
long long int	ft_atoi(const char *str);
t_lst			*ft_lstnew(void *content);
t_lst			*ft_lstlast(t_lst *lst);
char			**ft_split(char const *s, char c);
int				ft_lstsize(t_lst *lst);
void			ft_lstadd_front(t_lst **lst, t_lst *new);
void			ft_lstclear(t_lst **lst, void (*del)(void*));
void			ft_lstdelone(t_lst *lst, void (*del)(void*));
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
int				ft_strncmp(const char *s1, const char *s2, int n);

// GNL
char			*get_next_line(int fd);
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlen(char *str, int z);

#endif
