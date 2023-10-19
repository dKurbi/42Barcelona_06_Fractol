/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_setters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:12:12 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/18 14:28:27 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_limits	set_limits(double x_0, double x_1, double y_0, double y_1)
{
	t_limits	rtn;

	rtn.x_0 = x_0;
	rtn.x_1 = x_1;
	rtn.y_0 = y_0;
	rtn.y_1 = y_1;
	return (rtn);
}
