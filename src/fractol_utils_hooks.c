/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_hooks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:02:56 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/18 15:33:10 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	read_keys(int key_pressed, void *param)
{
	t_img	*image;

	image = (t_img *)param;
	if (key_pressed == ESC || !image)
		exit_program(&image->win);
	else if (key_pressed == I)
		zoom_in (image, image->h / 2, image->w / 2);
	else if (key_pressed == O)
		zoom_out (image, image->h / 2, image->w / 2);
	else if (key_pressed == ENTER)
		image->move = -image->move;
	else if (key_pressed == C)
		image->set_color = ((image->set_color) + 1) % 256;
	else if (key_pressed == X)
		center_fractal(image);
	else if (key_pressed == RIGHT || key_pressed == LEFT
		|| key_pressed == UP || key_pressed == DOWN)
		move_fractal(image, key_pressed);
	print_fractal(image);
	return (0);
}

int	read_mouse(int button, int mouse_x, int mouse_y, void *param)
{
	t_img			*image;

	image = (t_img *) param;
	if (button == 2)
		image->move = -image->move;
	if (button == 4)
		zoom_out(image, mouse_x, mouse_y);
	if (button == 5)
		zoom_in(image, mouse_x, mouse_y);
	if (!image)
		return (-1);
	if (mouse_x < 0 || mouse_y < 0 || mouse_x > image->w || mouse_y > image->h)
		return (2);
	print_fractal(image);
	(void)button;
	return (0);
}
