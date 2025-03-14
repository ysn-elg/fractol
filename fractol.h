/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 08:42:17 by yel-guad          #+#    #+#             */
/*   Updated: 2025/03/06 09:55:07 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct graph
{
	double	x_start;
	double	x_end;
	double	y_start;
	double	y_end;
}	t_graph;

typedef struct s_cmplx
{
	double	real;
	double	img;
}	t_cmplx;

typedef struct s_fract
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		sl;
	int		end;
	double	zoom;
	double	old_z;
	double	pxl_m;
	double	df_l;
	int		color;
	int		red;
	int		green;
	int		blue;
	int		iter;
	t_cmplx	c;
	t_cmplx	d;
	t_graph	t;
}	t_fract;

// Mandelbrot Set 
void	init_mandelbrot(t_fract *my);
int		draw_mandelbrot(t_fract *my, int x, int y);
void	map_mandelbrot(t_fract *my);
int		mouse_hook_mandelbrot(int keycode, int a, int b, t_fract *my);
int		key_hook_mandelbrot(int keycode, t_fract *my);

//Julia Set
void	init_julia(t_fract *my);
int		draw_julia(t_fract *my, int x, int y);
void	map_julia(t_fract *my);
int		mouse_hook_julia(int keycode, int a, int b, t_fract *my);
int		key_hook_julia(int keycode, t_fract *my);

// burningship Set 
void	init_burningship(t_fract *my);
int		draw_burningship(t_fract *my, int x, int y);
void	map_burningship(t_fract *my);
int		mouse_hook_burningship(int keycode, int a, int b, t_fract *my);
int		key_hook_burningship(int keycode, t_fract *my);

// Utils
int		exit_hook(t_fract *my);
int		get_color(int i, int max_iter, t_fract *my);
void	my_pixel_put(t_fract *my, int x, int y, int color);
int		ft_strncmp(const char *s1, const char *s2, int n);
double	atob(char *str);
void	init_julia(t_fract *my);
void	guide_exit(void);

#endif
