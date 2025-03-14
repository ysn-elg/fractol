/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 07:52:46 by yel-guad          #+#    #+#             */
/*   Updated: 2025/03/13 17:11:35 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_fract *my)
{
	my->d.real = 0;
	my->d.img = 0;
	my->mlx = mlx_init();
	my->win = mlx_new_window(my->mlx, 900, 900, "mandelbrot set");
	my->img = mlx_new_image(my->mlx, 900, 900);
	my->addr = mlx_get_data_addr(my->img, &my->bpp, &my->sl, &my->end);
	my->color = 0;
	my->red = 80;
	my->green = 60;
	my->blue = -520;
	my->pxl_m = 4.0 / 900.0;
	my->t.x_start = -2;
	my->t.y_start = 2;
	my->df_l = 4;
	my->zoom = 0;
	my->old_z = 0;
	my->iter = 2;
}

int	draw_mandelbrot(t_fract *my, int x, int y)
{
	t_cmplx	zp;
	t_cmplx	zn;
	double	f;
	int		i;

	zp.real = my->c.real;
	zp.img = my->c.img;
	i = 0;
	while (i < my->iter)
	{
		f = zp.real * zp.real + zp.img * zp.img;
		if (f > 4)
			return (my_pixel_put(my, x, y, get_color(i, my->iter, my)), 1);
		zn.real = zp.real * zp.real - zp.img * zp.img + my->c.real;
		zn.img = 2 * zp.real * zp.img + my->c.img;
		zp = zn;
		i++;
	}
	my_pixel_put(my, x, y, 0xFFFFFF);
	return (0);
}

void	map_mandelbrot(t_fract *my)
{
	int		x;
	int		y;

	x = 0;
	while (x < 900)
	{
		y = 0;
		while (y < 900)
		{
			my->c.real = my->t.x_start + x * my->pxl_m;
			my->c.img = my->t.y_start - y * my->pxl_m;
			draw_mandelbrot(my, x, y);
			y++;
		}
		x++;
	}
}

int	key_hook_mandelbrot(int keycode, t_fract *my)
{
	if (keycode == 65307)
		exit_hook(my);
	if (keycode == 114)
		my->red = (my->red + 20);
	else if (keycode == 103)
		my->green = (my->green + 20);
	else if (keycode == 98)
		my->blue = (my->blue + 20);
	else if (keycode == 65361)
		my->t.x_start -= (my->df_l - my->zoom) / 40;
	else if (keycode == 65363)
		my->t.x_start += (my->df_l - my->zoom) / 40;
	else if (keycode == 65362)
		my->t.y_start += (my->df_l - my->zoom) / 40;
	else if (keycode == 65364)
		my->t.y_start -= (my->df_l - my->zoom) / 40;
	else if (keycode == 65451)
		my->iter += 25;
	else if (keycode == 65453 && my->iter > 25)
		my->iter -= 25;
	map_mandelbrot(my);
	mlx_put_image_to_window(my->mlx, my->win, my->img, 0, 0);
	return (0);
}

int	mouse_hook_mandelbrot(int keycode, int a, int b, t_fract *my)
{
	my->old_z = my->zoom;
	if (keycode == 4)
		my->zoom += (my->df_l - my->zoom) * (1.0 / 3.0);
	else if (keycode == 5)
		my->zoom = -(my->df_l - my->zoom) * 3.0 / 2.0 + my->df_l;
	else
		return (1);
	my->t.x_start = (double)a * (my->zoom - my->old_z) / 900.0 + my->t.x_start;
	my->t.y_start = -(double)b * (my->zoom - my->old_z) / 900.0 + my->t.y_start;
	my->pxl_m = (my->df_l - my->zoom) / 900.0;
	map_mandelbrot(my);
	mlx_put_image_to_window(my->mlx, my->win, my->img, 0, 0);
	return (0);
}
