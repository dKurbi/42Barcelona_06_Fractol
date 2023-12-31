/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:44:51 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/18 14:13:32 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	char	*str;

	if (argc < 2)
	{
		print_arg_instructions();
		return (0);
	}
	str = ft_strtolow(argv[1]);
	if (!str)
		return (1);
	check_arg(str, argc, argv[2], argv[3]);
}
