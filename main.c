/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 08:36:30 by yel-guad          #+#    #+#             */
/*   Updated: 2025/03/06 09:55:01 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandelbrot_set(void)
{
	t_fract	my;

	init_mandelbrot(&my);
	map_mandelbrot(&my);
	mlx_mouse_hook(my.win, mouse_hook_mandelbrot, &my);
	mlx_hook(my.win, 17, 0, exit_hook, &my);
	mlx_hook(my.win, 2, 1L << 0, key_hook_mandelbrot, &my);
	mlx_put_image_to_window(my.mlx, my.win, my.img, 0, 0);
	mlx_loop(my.mlx);
}

static void	julia_set(char *real, char *img)
{
	t_fract	my;

	my.d.real = atob(real);
	my.d.img = atob(img);
	init_julia(&my);
	map_julia(&my);
	mlx_mouse_hook(my.win, mouse_hook_julia, &my);
	mlx_hook(my.win, 2, 1L << 0, key_hook_julia, &my);
	mlx_hook(my.win, 17, 0, exit_hook, &my);
	mlx_put_image_to_window(my.mlx, my.win, my.img, 0, 0);
	mlx_loop(my.mlx);
}

static void	burningship_set(void)
{
	t_fract	my;

	init_burningship(&my);
	map_burningship(&my);
	mlx_mouse_hook(my.win, mouse_hook_burningship, &my);
	mlx_hook(my.win, 2, 1L << 0, key_hook_burningship, &my);
	mlx_hook(my.win, 17, 0, exit_hook, &my);
	mlx_put_image_to_window(my.mlx, my.win, my.img, 0, 0);
	mlx_loop(my.mlx);
}

int	main(int ac, char **av)
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
		mandelbrot_set();
	else if (ac == 2 && !ft_strncmp(av[1], "burningship", 12))
		burningship_set();
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 6))
		julia_set(av[2], av[3]);
	guide_exit();
	return (0);
}
