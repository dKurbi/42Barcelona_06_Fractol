/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:44:51 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/12 15:04:03 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


int	main(void)
{
	t_win		window;
	t_img		image;
	t_limits	lim;

	window = new_window(500, 500, "Fractol");
	if (!window.mlx_ptr || !window.win_ptr)
		return (1);
	image = new_img(500, 500, window);
	lim = set_limits (-2, 2, -2, 2);
	make_mandelbrot(image, lim);
	mlx_put_image_to_window (image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 0, 0);
	mlx_hook(window.win_ptr, 17, 1L<<0, exit_program, &window);
	mlx_mouse_hook(window.win_ptr, read_mouse, &image);
	mlx_key_hook (window.win_ptr, read_keys, &image);
	mlx_loop(window.mlx_ptr); 

}

