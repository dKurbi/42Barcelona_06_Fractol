/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:31:54 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/09/29 14:05:10 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nxt;
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	nxt = (*lst)->next;
	while (nxt != NULL)
	{
		del(tmp->value);
		free(tmp);
		tmp = nxt;
		nxt = tmp->next;
	}
	del(tmp->value);
	free(tmp);
	*lst = NULL;
}
