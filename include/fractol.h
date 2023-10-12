/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:01:55 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/12 14:51:09 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define ESC 53   // key escape
# define ENTER 36 // key "enter"
# ifndef ITIN
#  define ITIN 127
# endif
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_win;

typedef struct s_cmplx
{
	double	real;
	double	img;
}	t_cmplx;

typedef struct s_limits
{
	double	x_0;
	double	x_1;
	double	y_0;
	double	y_1;
}	t_limits;

typedef struct s_img
{
	t_win	win;
	t_cmplx center;
	double	size;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_line
{
	unsigned short int	x_s;
	unsigned short int	y_s;	
	unsigned short int	x_e;
	unsigned short int	y_e;
	int					color;
}	t_line;


t_win		new_window(int w, int h, char *str);
int			exit_program(t_win *window);
void		put_pixel_img(t_img img, int x, int y, int color);
t_img		new_img(int w, int h, t_win window);
int			gen_trgb(int opacity, int red, int green, int blue);
int			get_opacity(int trgb);
int			get_red(int trgb);
int			get_green(int trgb);
int			get_blue(int trgb);
void		print_line(t_line line, t_img img);
t_line 		create_line(unsigned short x_s, unsigned short int x_e, unsigned short int y_s, unsigned short int y_e, int color);

// Complex operations functions

t_cmplx		square_c(t_cmplx num);
t_cmplx		add_c(t_cmplx num1, t_cmplx num2);
double		module(t_cmplx num);
int			is_mandelbrot_num(t_cmplx c, int n);
t_cmplx		calc_graph(t_limits lim);

// Make Fractal

void		make_mandelbrot(t_img img, t_limits limits);
t_limits	set_limits(double x_0, double x_1, double y_0, double y_1);

//colors
int			gen_trgb(int opacity, int red, int green, int blue);

// Hooks
int			read_keys(int key_pressed, void *param);
int 	read_mouse(int button, int mouse_x, int mouse_y, void *param);

#endif