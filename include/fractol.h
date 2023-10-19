/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:01:55 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/10/19 11:03:56 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define ESC 53   
# define C 8   
# define X 7   
# define I 34
# define O 31
# define ENTER 36 
# define UP 126 
# define DOWN 125 
# define RIGHT 124 
# define LEFT 123 
# ifndef ITER
#  define ITER 200
# endif
# include "../mlx/mlx.h"
# include "../libft/libft.h"
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

typedef struct s_cmplxint
{
	int	real;
	int	img;
}	t_cmplxint;

typedef struct s_limits
{
	double	x_0;
	double	x_1;
	double	y_0;
	double	y_1;
}	t_limits;

typedef struct s_img
{
	t_win			win;
	t_limits		lim;
	t_cmplx			ju_num;
	double			size;
	void			*img_ptr;
	char			*addr;
	int				h;
	int				w;
	int				bpp;
	int				endian;
	int				line_len;
	char			fractol;
	char			move;
	unsigned char	set_color;		
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
void		put_pixel_img(t_img image, int x, int y, int color);
t_img		new_image(int w, int h, t_win window, char type);
int			gen_trgb(int opacity, int red, int green, int blue);
int			get_opacity(int trgb);
int			get_red(int trgb);
int			get_green(int trgb);
int			get_blue(int trgb);
void		print_line(t_line line, t_img img);

// Complex operations functions

t_cmplx		square_c(t_cmplx num);
t_cmplx		add_c(t_cmplx num1, t_cmplx num2);
double		check_module(t_cmplx num);
int			is_mandelbrot_num(t_cmplx c, int n);
int			is_julia_num(t_cmplx c, t_cmplx j, int n);
t_cmplx		calc_graph(t_limits lim);
t_cmplx		calc_posicion_on_map(t_img image, int x, int y);

// Make Fractal
void		make_mandelbrot(t_img img);
void		make_julia(t_img image);
t_limits	set_limits(double x_0, double x_1, double y_0, double y_1);
void		mandelbrot(void);
void		julia(double x, double y);
int			re_make_julia(int mouse_x, int mouse_y, void *param);
void		print_fractal(t_img *image);
void		center_fractal(t_img *image);

//colors
int			gen_trgb(int opacity, int red, int green, int blue);
int			get_color(int num_m, char set_color);

// Hooks
int			read_keys(int key_pressed, void *param);
int			read_mouse(int button, int mouse_x, int mouse_y, void *param);

// Moves
void		zoom_in(t_img *image, int x, int y);
void		zoom_out(t_img *image, int x, int y);
void		move_fractal(t_img *image, int key_pressed);

// Check Arguments
void		check_arg(char *str, int argc, char *sx, char *sy);
void		print_arg_instructions(void);

// Print Instructions
void		mandelbrot_instructions(void);
void		julia_instructions(void);

// Bonus Burningship 
void		burningship(void);
void		make_burningship(t_img image);
int			is_burningship_num(t_cmplx c, int n);
void		mandelbrot_instructions(void);
void		burningship_instructions(void);

#endif