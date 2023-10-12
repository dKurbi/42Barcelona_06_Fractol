/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_hooks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:02:56 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/12 14:59:13 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	read_keys(int key_pressed, void *param)
{
    t_img	*img;

	img = (t_img *)param;
	if (key_pressed == ESC || !img)
		exit_program(&img->win);
	else
		return (-1);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
	return (0);
}

int read_mouse(int button, int mouse_x, int mouse_y, void *param)
{
	double 			x;
	double			y;
	t_img 			*img;
	t_limits		lim;
	

	img = (t_img *) param;
	if (button == 4)
		img->size = img->size * 0.9;
	if (button == 5)
		img->size = img->size * 1.1;
	if (!img)
		return (-1);
	if (mouse_x < 0 || mouse_y < 0 || mouse_x > img->w || mouse_y > img->h)
		return (2);
	img->center.real = (double) mouse_x * img->size/ img->w;
	img->center.img = (double) mouse_y * img->size/ img->h;
	printf ("center x = %0.3lf, y = %0.3lf\n", img->center.real, img->center.img);
	lim = set_limits(img->center.real - img->size / 2, img->center.real + img->size / 2, img->center.img - img->size / 2, img->center.img + img->size / 2);
	printf ("limits X 0 = %0.3lf, X 1 = %0.3lf, Y 0 = %0.3lf, Y 1 = %0.3lf\n", lim.x_0, lim.x_1, lim.y_0, lim.y_1);
	printf("size = %0.3lf\n", img->size);
	make_mandelbrot(*img, lim);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
	(void)button;
	return (0);
}