/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:32:52 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/18 16:22:06 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	zoom_in(t_img *image, int x, int y)
{
	t_cmplx	zoom;
	t_cmplx	len;

	y = image->h - y;
	len = calc_graph(image->lim);
	image->size = image->size * 0.8;
	zoom.real = ((len.real / image->w) * x) + image->lim.x_0;
	zoom.img = ((len.img / image->h) * y) + image->lim.y_0;
	image->lim.x_0 = zoom.real - ((zoom.real - image->lim.x_0) * 0.8);
	image->lim.x_1 = zoom.real + ((image->lim.x_1 - zoom.real) * 0.8);
	image->lim.y_0 = zoom.img - ((zoom.img - image->lim.y_0) * 0.8);
	image->lim.y_1 = zoom.img + ((image->lim.y_1 - zoom.img) * 0.8);
	len = calc_graph(image->lim);
	ft_printf("Zoom in                                                     \r");
}

void	zoom_out(t_img *image, int x, int y)
{
	t_cmplx	zoom;
	t_cmplx	len;

	y = image->h - y;
	len = calc_graph(image->lim);
	image->size = image->size * 1.2;
	zoom.real = ((len.real / image->w) * x) + image->lim.x_0;
	zoom.img = ((len.img / image->h) * y) + image->lim.y_0;
	image->lim.x_0 = zoom.real - ((zoom.real - image->lim.x_0) / 0.8);
	image->lim.x_1 = zoom.real + ((image->lim.x_1 - zoom.real) / 0.8);
	image->lim.y_0 = zoom.img - ((zoom.img - image->lim.y_0) / 0.8);
	image->lim.y_1 = zoom.img + ((image->lim.y_1 - zoom.img) / 0.8);
	len = calc_graph(image->lim);
	ft_printf("Zoom out                                                    \r");
}

void	move_fractal(t_img *image, int key_pressed)
{
	double	ratio;

	ratio = image->size * 0.1;
	if (key_pressed == UP)
	{
		image->lim.y_0 = image->lim.y_0 + ratio;
		image->lim.y_1 = image->lim.y_1 + ratio;
	}
	else if (key_pressed == DOWN)
	{
		image->lim.y_0 = image->lim.y_0 - ratio;
		image->lim.y_1 = image->lim.y_1 - ratio;
	}
	else if (key_pressed == LEFT)
	{
		image->lim.x_0 = image->lim.x_0 + ratio;
		image->lim.x_1 = image->lim.x_1 + ratio;
	}
	else if (key_pressed == RIGHT)
	{
		image->lim.x_0 = image->lim.x_0 - ratio;
		image->lim.x_1 = image->lim.x_1 - ratio;
	}
}
