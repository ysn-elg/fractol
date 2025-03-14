/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 06:34:53 by yel-guad          #+#    #+#             */
/*   Updated: 2025/03/06 08:10:19 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_fract *my, int x, int y, int color)
{
	char	*dst;

	if (x >= 900 || x < 0 || y < 0 || y >= 900)
		return ;
	dst = my->addr + (y * my->sl) + (x * (my->bpp / 8));
	*(unsigned int *)dst = color;
}

int	exit_hook(t_fract *my)
{
	mlx_destroy_image(my->mlx, my->img);
	mlx_destroy_window(my->mlx, my->win);
	mlx_destroy_display(my->mlx);
	free(my->mlx);
	exit(0);
	return (0);
}

int	get_color(int i, int max_iter, t_fract *my)
{
	double	t;
	double	r;
	double	g;
	double	b;

	t = (double)i / max_iter;
	r = (sin(0.16 * i + my->red) * 127 + 128) * (1 - t);
	g = (sin(0.16 * i + 2 + my->green) * 127 + 128) * (1 - t);
	b = (sin(0.16 * i + 4 + my->blue) * 127 + 128) * (1 - t);
	return ((int)r << 16 | (int)g << 8 | (int)b);
}
