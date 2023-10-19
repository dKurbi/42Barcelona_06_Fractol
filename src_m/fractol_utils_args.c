/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:38:55 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/18 14:18:01 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	check_arg(char *str, int argc, char *sx, char *sy)
{
	double	x;
	double	y;

	if (!ft_strncmp("mandelbrot", str, 10) && ft_strlen(str) == 10)
	{
		my_free(&str, NULL, NULL);
		mandelbrot();
	}
	else if (!ft_strncmp("julia", str, 5) && argc == 4 && ft_strlen (str) == 5)
	{
		my_free(&str, NULL, NULL);
		x = ft_atoi_float(sx);
		y = ft_atoi_float(sy);
		if (!(x == 0 && (ft_strlen(sx) > 1 || sx[0] != '0'))
			&& !(y == 0 && (ft_strlen(sy) > 1 || sy[0] != '0')))
			julia(x, y);
	}
	my_free(&str, NULL, NULL);
	ft_printf("Bad arguments\n");
	print_arg_instructions();
	exit (0);
}

void	print_arg_instructions(void)
{
	ft_printf("To run 'fractol', you need to specify the fractal you want to ");
	ft_printf("display as an argument. Here are the options:\n");
	ft_printf("- To print the Mandelbrot set, use the following command:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("- To print a Julia set, use the following command with initial");
	ft_printf(" for the complex number Z0:\n");
	ft_printf("  ./fractol julia <real part of Z0> <imaginary part of Z0>\n");
	ft_printf(" for example ./fractol julia −0.8 0.156 ");
	ft_printf("  You can use floating-point numbers for these values, but ");
	ft_printf("they should not exceed 12 digits in length.\n");
}
