/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_mandelbrot.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:29:27 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/04/28 18:56:50 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	mandelbrot(void)
{
	t_win		window;
	t_img		image;

	mandelbrot_instructions();
	window = new_window(750, 750, "Fractol");
	if (!window.mlx_ptr || !window.win_ptr)
		exit(EXIT_FAILURE);
	image = new_image(750, 750, window, 0);
	image.fractol = 0;
	make_mandelbrot(image);
	mlx_put_image_to_window (image.win.mlx_ptr, image.win.win_ptr,
		image.img_ptr, 0, 0);
	mlx_hook(window.win_ptr, 17, 1L << 0, exit_program, &window);
	mlx_mouse_hook(window.win_ptr, read_mouse, &image);
	mlx_key_hook (window.win_ptr, read_keys, &image);
	mlx_loop (window.mlx_ptr);
}

void	make_mandelbrot(t_img image)
{
	//t_cmplx		len;
	t_cmplx		num;
	t_cmplxint	xy;
	int			num_m;
	int			color;

	xy.img = -1;
	//len = calc_graph(image.lim);
	while (++xy.img < image.h)
	{
		xy.real = -1;
		while (++xy.real < image.w)
		{
			num = calc_posicion_on_map(image, xy.real, xy.img);
			num_m = is_mandelbrot_num(num, ITER);
			if (num_m == 0)
				put_pixel_img(image, xy.real, xy.img, 0x00000000);
			else
			{
				color = get_color(num_m, image.set_color);
				put_pixel_img(image, xy.real, xy.img, color);
			}
		}
	}
}
