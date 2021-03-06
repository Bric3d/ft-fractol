/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 18:05:49 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/15 13:44:59 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	color_scale_c(double d, double freq, double phase)
{
	return ((int)(127.5 * (1 - cos(freq * 2 * M_PI * (d + phase)))));
}

static int	color_scale(double d, t_arg *arg)
{
	int res;

	if (d < 0 || d > 1)
		return (0);
	res = 0;
	res += color_scale_c(d, arg->freq, arg->r);
	res = res << 8;
	res += color_scale_c(d, arg->freq, arg->g);
	res = res << 8;
	res += color_scale_c(d, arg->freq, arg->b);
	return (res);
}

static int	colorcarpet(double x)
{
	if (x == 1)
		return (0x000000);
	else
		return (0xFFFFFF);
}

int			ft_color(double x, int max, t_arg arg)
{
	max = max - 1;
	if (arg.fract == 5)
		return (colorcarpet(x));
	if (x >= max)
		return (0);
	if (x <= 0)
		x = 0.1;
	x = ((int)x % 20) + (x - (int)x);
	x /= 20;
	return (color_scale(x, &arg));
}
