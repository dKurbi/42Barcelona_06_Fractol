/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_maths_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:26:02 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/18 14:27:57 by dkurcbar         ###   ########.fr       */
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

double	check_module(t_cmplx num)
{
	return ((num.real * num.real) + (num.img * num.img));
}
