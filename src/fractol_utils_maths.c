/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_maths.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:44:57 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/18 14:27:27 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_cmplx	calc_graph(t_limits lim)
{
	t_cmplx	rtn;

	if (lim.x_0 > 0 && lim.x_1 > 0)
		rtn.real = lim.x_1 - lim.x_0;
	else if (lim.x_0 < 0 && lim.x_1 < 0)
		rtn.real = fabs (lim.x_0 - lim.x_1);
	else
		rtn.real = fabs(lim.x_0) + fabs(lim.x_1);
	if (lim.y_0 > 0 && lim.y_1 > 0)
		rtn.img = lim.y_1 - lim.y_0;
	else if (lim.y_0 < 0 && lim.y_1 < 0)
		rtn.img = fabs (lim.y_0 - lim.y_1);
	else
		rtn.img = fabs(lim.y_0) + fabs(lim.y_1);
	return (rtn);
}

t_cmplx	calc_posicion_on_map(t_img image, int x, int y)
{
	t_cmplx	rtn;
	t_cmplx	len;

	len = calc_graph(image.lim);
	rtn.real = ((len.real / image.w) * x) + image.lim.x_0;
	rtn.img = ((len.img / image.h) * y) + image.lim.y_0;
	return (rtn);
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
		if (check_module(num) > 4)
			return (i);
	}
	return (0);
}

int	is_julia_num(t_cmplx plano, t_cmplx julia, int n)
{
	int			i;

	i = 0;
	while (++i <= n)
	{
		plano = add_c(square_c(plano), julia);
		if (check_module(plano) > 4)
			return (i);
	}
	return (0);
}
