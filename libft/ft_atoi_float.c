/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:34:35 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/18 14:24:45 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	initnum(const char *str, int *sign, double *number, int *posdot)
{
	int	i;

	*number = 0;
	i = 0;
	*sign = 1;
	*posdot = 0;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '-')
	{
		i++;
		*sign = -1;
	}
	else if (str[i] == '+')
		i++;
	return (i);
}

static int	is_too_long(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			len++;
		i++;
	}
	if (str && len < 14)
		return (0);
	return (1);
}

static int	postdotmanage(int *posdot)
{
	if (*posdot > 0)
		return (1);
	else
		*posdot = 1;
	return (0);
}

static long	pow(int a, int p)
{
	long	rtn;

	rtn = 1;
	if (p == 0)
		return (1);
	while (--p)
		rtn = rtn * a;
	return (rtn);
}

double	ft_atoi_float(const char *str)
{
	int		i;
	double	n;
	int		sign;
	int		posdot;

	i = initnum(str, &sign, &n, &posdot);
	if (is_too_long((char *) str))
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			n = (n * 10) + (str[i] - '0');
			if (posdot > 0)
				posdot++;
		}
		else if ((str[i] == '.' || str[i] == ',') && ft_isdigit(str[i + 1]))
			if (postdotmanage(&posdot))
				return (0);
		i++;
	}
	return (sign * (n / (pow(10, posdot))));
}
