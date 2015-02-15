/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:12:09 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/15 13:41:27 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	choose(int nu1, int nu2)
{
	if (nu1 > nu2)
		return ((double)nu2 / (double)nu1);
	else
		return ((double)nu1 / (double)nu2);
}

void			randomcolor(int kc, t_arg *arg)
{
	int var1;
	int var2;

	if (kc == 32)
	{
		var1 = rand();
		var2 = rand();
		arg->r = (choose(var1, var2));
		var1 = rand();
		var2 = rand();
		arg->g = (choose(var1, var2));
		var1 = rand();
		var2 = rand();
		arg->b = (choose(var1, var2));
		var1 = rand();
		var2 = rand();
		printrgb(arg);
		ft_putimg(arg);
	}
}

void			printrgb(t_arg *arg)
{
	ft_putstr("                                                     \r R :");
	ft_putnbr(100 - (int)(arg->r * 100));
	ft_putstr("%  G : ");
	ft_putnbr(100 - (int)(arg->g * 100));
	ft_putstr("%  B : ");
	ft_putnbr(100 - (int)(arg->b * 100));
	ft_putstr("%  Prec : ");
	ft_putdouble(arg->prec, 4);
	ft_putstr("  I : ");
	ft_putnbr(arg->i);
	ft_putchar('\r');
}
