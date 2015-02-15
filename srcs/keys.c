/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 14:35:14 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/15 16:15:23 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void ft_changergb2(t_arg *arg)
{
	printrgb(arg);
	ft_putimg(arg);
}

void		ft_changergb(int kc, t_arg *arg)
{
	if (kc == 65465 && arg->r - 0.1 * arg->prec >= 0)
		arg->r = arg->r - 0.1 * arg->prec;
	else if (kc == 65465)
		arg->r = 0;
	if (kc == 65463 && arg->r + 0.1 * arg->prec <= 1)
		arg->r = arg->r + 0.1 * arg->prec;
	else if (kc == 65463)
		arg->r = 1;
	if (kc == 65462 && arg->g - 0.1 * arg->prec >= 0)
		arg->g = arg->g - 0.1 * arg->prec;
	else if (kc == 65462)
		arg->g = 0;
	if (kc == 65460 && arg->g + 0.1 * arg->prec <= 1)
		arg->g = arg->g + 0.1 * arg->prec;
	else if (kc == 65460)
		arg->g = 1;
	if (kc == 65459 && arg->b - 0.1 * arg->prec >= 0)
		arg->b = arg->b - 0.1 * arg->prec;
	else if (kc == 65459)
		arg->b = 0;
	if (kc == 65457 && arg->b + 0.1 * arg->prec <= 1)
		arg->b = arg->b + 0.1 * arg->prec;
	else if (kc == 65457)
		arg->b = 1;
	ft_changergb2(arg);
}

void		ft_changetar(int kc, t_arg *arg)
{
	if (kc == 65365)
		arg->n = arg->n + 1;
	if (kc == 65366 && arg->n > 3)
		arg->n = arg->n - 1;
	if (kc == 112)
	{
		if (arg->pretty == 1)
			arg->pretty = 0;
		else
			arg->pretty = 1;
	}
	if (kc == 109 && (arg->fract == 3 || arg->fract == 4))
	{
		if (arg->mouse == 1)
			arg->mouse = 0;
		else
			arg->mouse = 1;
	}
	if (arg->n > 3 && kc != 109)
		ft_putimg(arg);
}

void		ft_toogleprecision(int kc, t_arg *arg)
{
	if (kc == 65360 && arg->prec / 10 >= 0.0001)
		arg->prec = arg->prec / 10;
	if (kc == 65367 && arg->prec * 10 <= 10000)
		arg->prec = arg->prec * 10;
	printrgb(arg);
}

int			ft_key_hook(int kc, t_arg *arg)
{
	if (kc == 45 || kc == 61 || kc == 65453 || kc == 65451)
		ft_zoom(kc, arg);
	if (kc == 49 || kc == 50 || kc == 51 || kc == 52 || kc == 53
		|| kc == 54 || kc == 55 || kc == 56 || kc == 57)
		selectfrac(kc, arg);
	if (kc == 65362 || kc == 65364 || kc == 65361 || kc == 65363)
		ft_move(kc, arg);
	if (kc == 114)
		ft_reset(kc, arg);
	if (kc == 65463 || kc == 65465 || kc == 65460 || kc == 65462
		|| kc == 65457 || kc == 65459)
		ft_changergb(kc, arg);
	if (kc == 65455 || kc == 65450)
		ft_iterate(kc, arg);
	if (kc == 65365 || kc == 65366 || kc == 112 || kc == 109)
		ft_changetar(kc, arg);
	if (kc == 32)
		randomcolor(kc, arg);
	if (kc == 65360 || kc == 65367)
		ft_toogleprecision(kc, arg);
	if (kc == 65307)
		exit (0);
	return (0);
}
