/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:26:07 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/18 14:19:06 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	gen_trgb(int opacity, int red, int green, int blue)
{
	opacity = opacity % 256;
	red = red % 256;
	green = green % 256;
	blue = blue % 256;
	return (opacity << 24 | red << 16 | green << 8 | blue);
}

int	get_color(int num_m, char set_color)
{
	int				color;
	unsigned char	num_colors;

	num_colors = 6;
	color = 0;
	if (set_color % num_colors == 0)
		color = gen_trgb(0, 50 + sqrt(num_m) * 11, 50, 50 + num_m * 4);
	else if (set_color % num_colors == 1)
		color = gen_trgb(0, 50, 50 + sqrt(num_m) * 11, 50 + num_m * 4);
	else if (set_color % num_colors == 2)
		color = gen_trgb(0, 50, 50 + num_m * 4, 50 + sqrt(num_m) * 11);
	else if (set_color % num_colors == 3)
		color = gen_trgb(0, 50, 50, 50 + num_m * 11);
	else if (set_color % num_colors == 4)
		color = gen_trgb(0, 50, num_m * 11, 50 + num_m * 11);
	else if (set_color % num_colors == 5)
		color = gen_trgb(0, num_m, num_m * 11, 50 + num_m * 11);
	return (color);
}
