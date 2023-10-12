/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_maths.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:44:57 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/12 13:26:14 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_cmplx	square_c(t_cmplx num)
{
	t_cmplx	rtn;

	rtn.real = (num.real * num.real) - (num.img * num.img);
	rtn.img = 2 * num.real * num.img;
	return (rtn);
}

t_cmplx	add_c(t_cmplx num1, t_cmplx num2)
{
	t_cmplx	rtn;

	rtn.real = num1.real + num2.real;
	rtn.img = num1.img + num2.img;
	return (rtn);
}

double	module(t_cmplx num)
{
	return (sqrt((num.real * num.real) + (num.img * num.img)));
}

int	is_mandelbrot_num(t_cmplx c, int n)
{
	int			i;
	t_cmplx		num;

	i = 0;
	num.img = 0;
	num.real = 0;
	while (++i <= n)
	{
		num = add_c(square_c(num), c);
		if (module(num) > 2)
			return (i);
	}
	return (0);
}