/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:26:07 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/10 15:30:17 by dkurcbar         ###   ########.fr       */
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

int	get_opacity(int trgb)
{
	return ((trgb >> 24) & 0XFF);
}

int	get_red(int trgb)
{
	return ((trgb >> 16) & 0XFF);
}

int	get_green(int trgb)
{
	return ((trgb >> 8) & 0XFF);
}

int	get_blue(int trgb)
{
	return (trgb & 0xFF);
}