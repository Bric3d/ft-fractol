/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 14:45:05 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/15 16:14:47 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move(int kc, t_arg *arg)
{
	double	y;

	y = 0.05 / arg->z;
	if (kc == 65362)
		arg->posy = arg->posy - y;
	if (kc == 65364)
		arg->posy = arg->posy + y;
	if (kc == 65361)
		arg->posx = arg->posx - y;
	if (kc == 65363)
		arg->posx = arg->posx + y;
	ft_putimg(arg);
}

void	selectfrac(int kc, t_arg *arg)
{
	if (kc == 49)
		arg->fract = 1;
	if (kc == 50)
		arg->fract = 2;
	if (kc == 51)
		arg->fract = 3;
	if (kc == 52)
		arg->fract = 4;
	if (kc == 53)
		arg->fract = 5;
	if (kc == 54)
		arg->fract = 6;
	if (kc == 55)
		arg->fract = 7;
	if (kc == 56)
		arg->fract = 8;
	if (kc == 57)
		arg->fract = 9;
	ft_putimg(arg);
}

void	ft_reset(int kc, t_arg *arg)
{
	if (kc == 114)
	{
		ft_initvar(arg);
		ft_putimg(arg);
	}
}

void	ft_iterate(int kc, t_arg *arg)
{
	int i;
	int j;

	i = (int)arg->prec;
	if (i < 1)
		i = 1;
	if (kc == 65455 && (j = arg->i - 1 * i) >= 3)
		arg->i = j;
	if (kc == 65450 && (j = arg->i + 1 * i) <= 10000)
		arg->i = j;
	printrgb(arg);
	ft_putimg(arg);
}

void	ft_zoom(int kc, t_arg *arg)
{
	if ((kc == 45 || kc == 65453) && arg->i > 1 && arg->z > 0)
	{
		arg->i -= 2;
		arg->z /= 1.5;
	}
	if ((kc == 61 || kc == 65451) && arg->z * 1.5 < 220076276500268)
	{
		arg->i += 2;
		arg->z *= 1.5;
	}
	ft_putimg(arg);
}
