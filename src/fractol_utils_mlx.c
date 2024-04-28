/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_mlx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:04:24 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/04/28 18:57:01 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_win	new_window(int w, int h, char *str)
{
	void	*mlx_ptr;
	t_win	ret;
	
	mlx_ptr = mlx_init();
	ret.height = h;
	ret.width = w;
	ret.win_ptr = mlx_new_window(mlx_ptr, w, h, str);
	ret.mlx_ptr = mlx_ptr;
	return (ret);
}

int	exit_program(t_win *window)
{
	if (window)
		mlx_destroy_window (window->mlx_ptr, window->win_ptr);
	exit(EXIT_SUCCESS);
}

void	put_pixel_img(t_img lim, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < lim.w && y < lim.h)
	{
		dst = lim.addr + (y * lim.line_len + x * (lim.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

t_img	new_image(int w, int h, t_win window, char type)
{
	t_img	image;

	image.fractol = type;
	center_fractal(&image);
	image.move = 1;
	image.size = 4;
	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	image.set_color = 5;
	return (image);
}
