/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:08:41 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/11 15:06:04 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	choosefract(t_arg arg, t_pts pts, double x, double y)
{
	double i;

	i = 0;
	if (arg.fract == 1)
		i = mandelbrot(&arg, &pts, x, y);
	if (arg.fract == 2)
		i = burning_ship(&arg, &pts, x, y);
	if (arg.fract == 9)
		i = special1(&arg, &pts, x, y);
	return (i);
}