/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:37:21 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/08/30 17:30:51 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	rtn;
	int	i;

	if (!str)
	{
		i = write (1, "(null)", 6);
		return (i);
	}
	else
	{
		rtn = 0;
		while (str[rtn])
		{
			i = ft_putchar(str[rtn++]);
			if (i == -1)
				return (-1);
		}
	}
	return (rtn);
}
