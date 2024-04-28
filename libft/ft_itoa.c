/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:25:43 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/04/28 18:05:10 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*exceptions(int n)
{
	char	*rtn;

	if (n == 0)
	{
		rtn = ft_strdup("0");
	}
	if (n < 0)
	{
		rtn = ft_strdup("-2147483648");
	}
	return (rtn);
}

static char	*mall_str(int n, int *num_d)
{
	char	*rtn;

	if (n < 0)
	{
		*num_d = 1;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		(*num_d)++;
	}
	rtn = (char *) ft_calloc (*num_d + 1, sizeof(char));
	return (rtn);
}

static char	*write_num(char *rtn, int n, int num_d)
{
	num_d--;
	if (n < 0)
	{
		rtn[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		rtn[num_d--] = n % 10 + '0';
		n = n / 10;
	}
	return (rtn);
}

char	*ft_itoa(int n)
{
	char	*rtn;
	int		num_d;

	if ((n == 0) || (n <= -2147483648))
		return (exceptions(n));
	num_d = 0;
	rtn = mall_str(n, &num_d);
	if (rtn == NULL)
		return (NULL);
	rtn = write_num(rtn, n, num_d);
	return (rtn);
}
