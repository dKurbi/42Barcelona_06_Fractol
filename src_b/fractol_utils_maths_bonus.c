/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_maths_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:47:02 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/19 11:07:25 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	is_burningship_num(t_cmplx c, int n)
{
	int			i;
	t_cmplx		num;

	i = 0;
	num.img = 0;
	num.real = 0;
	while (++i <= n)
	{
		num = (t_cmplx){ft_abs_d(num.real), ft_abs_d(num.img)};
		num = add_c(square_c(num), c);
		if (check_module(num) > 4)
			return (i);
	}
	return (0);
}
