/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:18:14 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/03 15:51:07 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*nxt;
	void	*aux;

	newlist = NULL;
	nxt = newlist;
	while (lst)
	{
		aux = f(lst->value);
		nxt = ft_lstnew(aux);
		if (!nxt)
		{
			ft_lstclear(&newlist, del);
			free(aux);
			return (NULL);
		}
		ft_lstadd_back(&newlist, nxt);
		lst = lst->next;
	}
	return (newlist);
}
