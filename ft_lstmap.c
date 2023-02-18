/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:42:58 by troudot           #+#    #+#             */
/*   Updated: 2022/11/18 05:10:15 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Paramètres :
// lst: L'adresse du pointeur vers un élément.

// f: L'adresse de la fonction à appliquer.

// del: L'adresse de la fonction permettant desupprimer le contenu d'un élément.

// Valeur de retour : La nouvelle liste. NULL si l'allocation échoue

// Fonctions externes autorisées : malloc, free

// Description : Itère sur la liste 'lst' et applique la fonction
// 'f'au contenu de chaque élément. Crée une nouvelle
// liste résultant des applications successives de
// 'f'. La fonction 'del' est là pour détruire le
// contenu d'un élément si nécessaire.

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	void	*content;
	t_list	*n;

	if (!lst || !f || !del)
		return (0);
	list = 0;
	while (lst)
	{
		content = f(lst->content);
		n = ft_lstnew(content);
		if (!n)
		{
			ft_lstclear(&list, del);
			del(content);
		}
		ft_lstadd_back(&list, n);
		lst = lst->next;
	}
	return (list);
}
