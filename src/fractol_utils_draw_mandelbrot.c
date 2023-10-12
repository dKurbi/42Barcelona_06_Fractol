/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_draw_mandelbrot.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:29:27 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/12 13:53:23 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_cmplx	calc_graph(t_limits lim)
{
	t_cmplx	rtn;

	if (lim.x_0 > 0 && lim.x_1 > 0)
		rtn.real =  lim.x_1 - lim.x_0;
	else if (lim.x_0 < 0 && lim.x_1 < 0)
		rtn.real = fabs (lim.x_0 + lim.x_1);
	else
		rtn.real = fabs(lim.x_0) + fabs(lim.x_1);
	if (lim.y_0 > 0 && lim.y_1 > 0)
		rtn.img = lim.y_1 - lim.y_0;
	else if (lim.y_0 < 0 && lim.y_1 < 0)
		rtn.img = fabs (lim.y_0 + lim.y_1);
	else
		rtn.img = fabs(lim.y_0) + fabs(lim.y_1);
	return(rtn);
}

void	make_mandelbrot(t_img img, t_limits limits)
{
	t_cmplx	len;
	t_cmplx num;
	int		x;
	int		y;
	int		num_m;
	int 	color;
	
	x = 0;
	y = 0;
	len = calc_graph(limits);
	while (y < img.h)
	{
		x = 0;
		while(x < img.w)
		{
			num.real = ((len.real/img.w) * x)   + limits.x_0;
			num.img = ((len.img/img.h) * y) + limits.y_0;
			num_m = is_mandelbrot_num(num, ITIN);
			if ( num_m == 0)
			{
				put_pixel_img(img, x, y, 0x00000000);
				
			}
			else
			{
				color = gen_trgb(0, num_m * 2, 0, 255 - num_m * 2);
				put_pixel_img(img, x, y, color);
			}
			x++;
		}
		y++;
	}

}