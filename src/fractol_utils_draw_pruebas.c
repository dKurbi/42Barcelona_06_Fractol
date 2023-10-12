/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_draw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:33:55 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/10 17:32:54 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void print_line(t_line line, t_img img)
{
	unsigned short int	x;
	unsigned short int	y;
	int len;
	int sign;
		
	sign = 1;
	if (abs(line.x_s - line.x_e) >= abs(line.y_s - line.y_e))
	{
		len = line.x_e - line.x_s;
		if (len == 0)
			return;
		x = line.x_s - 1;
		if (len < 0)
		{
			x = line.x_e - 1;
			len = -len;
			y = line.y_e;
			line.y_e = line.y_s;
			line.y_s = y;
			sign = -1;
		}
		while (++x <= len )
		{
			y = line.y_s + (sign * (line.y_s - line.y_e) * x / (line.x_s - line.x_e));
			put_pixel_img(img, x, y, line.color);
		}
	}	else if (abs(line.x_s - line.x_e) < abs(line.y_s - line.y_e))
	{
		len = line.y_e - line.y_s;
		y = line.y_s - 1;
		if (len < 0)
		{
			y = line.y_e  - 1;
			len = -len;
			x = line.x_e;
			line.x_e = line.x_s;
			line.x_s = x;
			sign = -1;
		}
		while (++y <= len )
		{
			x = line.x_s + (sign * (line.x_s - line.x_e) * y / (line.y_s - line.y_e));
			put_pixel_img(img, x, y, line.color);
			x++;
		}
	}
	
	
}
t_line create_line(unsigned short x_s,unsigned short int y_s, unsigned short int x_e, unsigned short int y_e, int color)
{
	t_line	line;

	line.x_s = x_s;
	line.x_e = x_e;
	line.y_s = y_s;
	line.y_e = y_e;

	line.color = color;
	return (line);
}