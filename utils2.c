/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 09:47:24 by yel-guad          #+#    #+#             */
/*   Updated: 2025/03/06 10:07:49 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	guide_exit(void)
{
	write(1, "┏━━━━━━━━━━━━━━━━━━━━━━┓\n", 74);
	write(1, "┃  Invalid argument !  ┃", 29);
	write(1, "\n┗━━━━━━━━━━━━━━━━━━━━━━┛\n", 75);
	write(1, "\nUsage:\n\n", 10);
	write(1, "   ./fractol mandelbrot\n\n", 26);
	write(1, "   ./fractol julia <real> <img>\n\n", 34);
	write(1, "   ./fractol burningship\n\n", 27);
	write(1, "------------------------------------------------------\n", 56);
	write(1, "Most Famous Julia Set Values:\n\n", 32);
	write(1, "Douady’s Rabbit:         ./fractol julia -0.123 +0.745\n\n", 59);
	write(1, "San Marco Dragon:        ./fractol julia -0.75 +0.0\n\n", 54);
	write(1, "Siegel Disk:             ./fractol julia 0.3 +0.5\n\n", 52);
	write(1, "Tchebychev Polynomial:   ./fractol julia 0.285 +0.01\n\n", 55);
	write(1, "Coral Structure:         ./fractol julia 0.355 +0.355\n\n", 56);
	write(1, "Burning Ship:            ./fractol julia -0.8 0.156\n\n", 54);
	write(1, "Venus' Eye:              ./fractol julia -0.4 +0.6\n\n", 53);
	write(1, "╔════════════════════════════════════════╗\n", 128);
	write(1, "║       Fract-ol is yours, enjoy!        ║\n", 48);
	write(1, "╚════════════════════════════════════════╝\n\n", 129);
	exit(0);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

double	get_dbl(char *str)
{
	double	dbl;
	int		i;
	int		t;

	t = 10;
	i = 0;
	dbl = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		dbl = dbl * 10 + str[i++] - '0';
	if (str[i++] == '.')
	{
		while (str[i] && str[i] >= '0' && str[i] <= '9')
		{
			dbl = dbl + (double)(str[i++] - '0') / t;
			t = t * 10;
		}
	}
	return (dbl);
}

double	atob(char *str)
{
	int		s;
	int		i;

	i = 0;
	s = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		if (str[i++] == '-')
			s = -1;
	if (!(str[i] && str[i] >= '0' && str[i] <= '9'))
		guide_exit();
	return (get_dbl(str + i) * s);
}
