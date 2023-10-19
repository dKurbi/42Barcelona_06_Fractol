/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_others.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:23:42 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/18 16:41:44 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	print_fractal(t_img *image)
{
	if (image->fractol == 0)
		make_mandelbrot(*image);
	else
		make_julia(*image);
	mlx_put_image_to_window(image->win.mlx_ptr, image->win.win_ptr,
		image->img_ptr, 0, 0);
}

void	center_fractal(t_img *image)
{
	if (image->fractol == 0)
	{
		image->lim.x_0 = -2.5;
		image->lim.x_1 = 1.5;
	}
	else if (image->fractol == 1)
	{
		image->lim.x_0 = -2;
		image->lim.x_1 = 2;
	}
	image->lim.y_0 = -2;
	image->lim.y_1 = 2;
}

void	mandelbrot_instructions(void)
{
	ft_printf("************************************************************\n");
	ft_printf("*            WELCOME TO FRACTOL by dkurcbar                *\n");
	ft_printf("************************************************************\n");
	ft_printf("* MANDELBROT INSTRUCTIONS:                                 *\n");
	ft_printf("* Press 'I' or 'O' to Zoom In or Zoom Out                  *\n");
	ft_printf("* You can also Zoom using the mouse scroll                 *\n");
	ft_printf("*                                                          *\n");
	ft_printf("* Use the arrow keys to move the fractal                   *\n");
	ft_printf("* Press 'X' to recenter the fractal                        *\n");
	ft_printf("* Press 'C' to change the color set                        *\n");
	ft_printf("* Press 'ESC' to exit the program                          *\n");
	ft_printf("************************************************************\n");
}

void	julia_instructions(void)
{
	ft_printf("************************************************************\n");
	ft_printf("*               WELCOME TO FRACTOL by dkurcbar             *\n");
	ft_printf("************************************************************\n");
	ft_printf("* JULIA INSTRUCTIONS:                                      *\n");
	ft_printf("* Press 'I' or 'O' to Zoom In or Zoom Out                  *\n");
	ft_printf("* You can also Zoom using the mouse scroll                 *\n");
	ft_printf("*                                                          *\n");
	ft_printf("* Use the arrow keys to move the fractal                   *\n");
	ft_printf("* Press 'X' to recenter the fractal                        *\n");
	ft_printf("* Press 'C' to change the color set                        *\n");
	ft_printf("* Press 'ESC' to exit the program                          *\n");
	ft_printf("*                                                          *\n");
	ft_printf("* Press 'ENTER' or the left mouse button                   *\n");
	ft_printf("* To select a Julia set, based on the mouse position       *\n");
	ft_printf("************************************************************\n");
}
