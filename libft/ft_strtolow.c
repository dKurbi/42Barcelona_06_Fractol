/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:14:00 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/18 14:17:09 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolow(char *str)
{
	char	*rtn;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	rtn = ft_calloc(len + 1, sizeof(char));
	while (len--)
		rtn[len] = ft_tolower(str[len]);
	return (rtn);
}
