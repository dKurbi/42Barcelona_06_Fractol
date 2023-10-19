/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_julia.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:21:53 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/19 10:56:02 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	julia(double x, double y)
{
	t_win		window;
	t_img		image;

	julia_instructions();
	window = new_window(750, 750, "Julia");
	if (!window.mlx_ptr || !window.win_ptr)
		exit (EXIT_FAILURE);
	image = new_image(750, 750, window, 1);
	image.fractol = 1;
	image.lim = set_limits(-2, 2, -2, 2);
	image.ju_num = (t_cmplx){x, y};
	make_julia(image);
	mlx_put_image_to_window (image.win.mlx_ptr, image.win.win_ptr,
		image.img_ptr, 0, 0);
	mlx_hook(window.win_ptr, 17, 1L << 0, exit_program, &window);
	mlx_hook(window.win_ptr, 6, 1L << 6, re_make_julia, &image);
	mlx_mouse_hook(window.win_ptr, read_mouse, &image);
	mlx_key_hook (window.win_ptr, read_keys, &image);
	mlx_loop (window.mlx_ptr);
}

void	make_julia(t_img image)
{
	t_cmplx		len;
	t_cmplx		num;
	t_cmplxint	xy;
	int			num_m;
	int			color;

	xy.img = -1;
	len = calc_graph(image.lim);
	while (++xy.img < image.h)
	{
		xy.real = -1;
		while (++xy.real < image.w)
		{
			num = calc_posicion_on_map(image, xy.real, image.h - xy.img);
			num_m = is_julia_num(num, image.ju_num, ITER);
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

int	re_make_julia(int mouse_x, int mouse_y, void *param)
{
	t_img			*image;

	image = (t_img *) param;
	if (mouse_x > 0 && mouse_y > 0 && mouse_x < image->w && mouse_y < image->h)
	{
		if (image->move == -1)
		{
			image->ju_num = calc_posicion_on_map(*image, mouse_x, mouse_y);
			make_julia(*image);
			mlx_put_image_to_window(image->win.mlx_ptr, image->win.win_ptr,
				image->img_ptr, 0, 0);
		}
	}
	return (0);
}
