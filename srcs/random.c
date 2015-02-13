/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:12:09 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/13 15:42:11 by bbecker          ###   ########.fr       */
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
	int r1;
	int r2;
	int g1;
	int g2;
	int b1;
	int b2;

	if (kc == 32)
	{
		r1 = rand();
		r2 = rand();
		g1 = rand();
		g2 = rand();
		b1 = rand();
		b2 = rand();
		arg->r = (choose(r1, r2));
		arg->g = (choose(g1, g2));
		arg->b = (choose(b1, b2));
		printrgb(arg);
		ft_putimg(arg);
	}
}

void	printrgb(t_arg *arg)
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