/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:11:08 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/15 13:53:39 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	mandelbrot(t_arg *arg, t_pts *pts, double x, double y)
{
	double	tmp;
	double	i;

	pts->c_r = (x - (double)arg->sizex / 2) / (0.5 * arg->z
	* (double)arg->sizex) + arg->posx;
	pts->c_i = (y - (double)arg->sizex / 2) / (0.5 * arg->z
	* (double)arg->sizex) + arg->posy;
	while ((pts->z_r * pts->z_r + pts->z_i * pts->z_i) < (double)arg->n
		&& pts->i < arg->i)
	{
		tmp = pts->z_r;
		pts->z_r = pts->z_r * pts->z_r - pts->z_i * pts->z_i + pts->c_r;
		pts->z_i = 2 * pts->z_i * tmp + pts->c_i;
		pts->i = pts->i + 1;
	}
	if (arg->pretty == 1)
		i = (double)pts->i + 1.0
		- log(log(sqrt(pts->z_r * pts->z_r + pts->z_i * pts->z_i))) / log(2);
	else
		i = pts->i;
	return (i);
}

double	burning_ship(t_arg *arg, t_pts *pts, double x, double y)
{
	double	tmp1;
	double	tmp2;
	double	i;

	pts->c_r = (x - (double)arg->sizex / 2) / (0.5 * arg->z
	* (double)arg->sizex) + arg->posx;
	pts->c_i = (y - (double)arg->sizex / 2) / (0.5 * arg->z
	* (double)arg->sizex) + arg->posy;
	while (pts->i < arg->i)
	{
		tmp1 = pts->z_r * pts->z_r - pts->z_i * pts->z_i - pts->c_r;
		tmp2 = 2 * fabs(pts->z_r) * fabs(pts->z_i) + pts->c_i;
		pts->z_r = tmp1;
		pts->z_i = tmp2;
		pts->i++;
		if (pts->z_r * pts->z_r + pts->z_i * pts->z_i >= arg->n)
			break ;
	}
	if (arg->pretty == 1)
		i = (double)pts->i + 1.0
		- log(log(sqrt(pts->z_r * pts->z_r + pts->z_i * pts->z_i))) / log(2);
	else
		i = pts->i;
	return (i);
}

double	julia(t_arg *arg, t_pts *pts, double x, double y)
{
	double	tmp1;
	double	tmp2;
	double	i;

	pts->z_r = (x - (double)arg->sizex / 2) / (0.5 * arg->z
	* (double)arg->sizex) + arg->posx;
	pts->z_i = (y - (double)arg->sizex / 2) / (0.5 * arg->z
	* (double)arg->sizex) + arg->posy;
	while (pts->i < arg->i)
	{
		tmp1 = pts->z_r * pts->z_r - pts->z_i * pts->z_i + arg->const1;
		tmp2 = 2 * pts->z_r * pts->z_i + arg->const2;
		pts->z_r = tmp1;
		pts->z_i = tmp2;
		pts->i = pts->i + 1;
		if (pts->z_r * pts->z_r + pts->z_i * pts->z_i > arg->n)
			break ;
	}
	if (arg->pretty == 1)
		i = (double)pts->i + 1.0
		- log(log(sqrt(pts->z_r * pts->z_r + pts->z_i * pts->z_i))) / log(2);
	else
		i = pts->i;
	return (i);
}

double	julia2(t_arg *arg, t_pts *pts, double x, double y)
{
	double	tmp1;
	double	tmp2;
	double	i;

	pts->z_r = (x - (double)arg->sizex / 2) / (0.5 * arg->z
	* (double)arg->sizex) + arg->posx;
	pts->z_i = (y - (double)arg->sizex / 2) / (0.5 * arg->z
	* (double)arg->sizex) + arg->posy;
	while (pts->i < arg->i)
	{
		tmp1 = pts->z_r * pts->z_r - pts->z_i * pts->z_i + arg->const1;
		tmp2 = 2 * pts->z_r * pts->z_i + arg->const2;
		pts->z_r = tmp1;
		pts->z_i = tmp2;
		pts->i = pts->i + 1;
		if (pts->z_r * pts->z_r + pts->z_i * pts->z_i > 1)
			break ;
	}
	if (arg->pretty == 1)
		i = (double)pts->i + 1.0
		- log(log(sqrt(pts->z_r * pts->z_r + pts->z_i * pts->z_i))) / log(2);
	else
		i = pts->i;
	return (i);
}

double	special1(t_arg *arg, t_pts *pts, double x, double y)
{
	double	tmp1;
	double	tmp2;
	double	i;

	pts->c_r = (x - (double)arg->sizex / 2) / (0.5 * arg->z
	* (double)arg->sizex) + arg->posx;
	pts->c_i = (y - (double)arg->sizex / 2) / (0.5 * arg->z
	* (double)arg->sizex) + arg->posy;
	while (pts->i < arg->i)
	{
		tmp1 = pts->z_r * pts->z_r - pts->z_i * pts->z_i - pts->c_r;
		tmp2 = 2 * fabs(pts->z_r) * fabs(pts->z_i) + pts->c_i;
		pts->z_r = tmp1;
		pts->z_i = tmp2;
		pts->i++;
		if (pts->z_r * pts->z_r + pts->z_i * pts->z_i >= 1)
			break ;
	}
	if (arg->pretty == 1)
		i = (double)pts->i + 1.0
		- log(log(sqrt(pts->z_r * pts->z_r + pts->z_i * pts->z_i))) / log(2);
	else
		i = pts->i;
	return (i);
}
