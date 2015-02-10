/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 18:05:49 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/10 16:58:07 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_scale_c(double d, double freq, double phase)
{
	return ((int)(127.5 * (1 - cos(freq * 2 * M_PI* (d + phase)))));
}


int	color_scale(double d, t_arg *arg)
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


int	ft_color(double x, int max, t_pts *pts, t_arg *arg)
{
	if (x < 0 || x >= max)
		return (0);
	if (arg->pretty == 1)
		x = (double)x + 1.0 - log(log(sqrt(pts->z_r * pts->z_r + pts->z_i * pts->z_i))) / log(2);
	x = ((int)x % 20) + (x - (int)x);
	x /= 20;
	return (color_scale(x, arg));
}
