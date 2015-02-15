/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 15:33:21 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/15 16:14:38 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*wininit(t_arg *arg)
{
	t_x	*xinfos;

	xinfos = (t_x *)ft_memallocpp(sizeof(t_x *), &ft_error);
	xinfos->mlx = NULL;
	if ((xinfos->mlx = mlx_init()) == NULL)
	{
		ft_error("fractol", 2, "mlx_init");
		exit (-1);
	}
	xinfos->win = NULL;
	if ((xinfos->win = mlx_new_window(xinfos->mlx, arg->sizex, arg->sizey,
		"Fract'ol")) == NULL)
	{
		ft_error("fractol", 2, "mlx_init");
		exit (-1);
	}
	return (xinfos);
}

static void	ft_size(int ac, char **av, t_arg *arg)
{
	int		tmp1;
	int		tmp2;

	if (ac == 4)
	{
		tmp1 = ft_atoi(av[2]);
		tmp2 = ft_atoi(av[3]);
	}
	if (ac == 4 || (ac == 3 && (tmp1 = ft_atoi(av[1])) > 0
		&& (tmp2 = ft_atoi(av[2])) > 0))
	{
		if (tmp1 <= 0 || tmp1 > 2560)
			ft_error("fractol", 1, "X size"), arg->sizex = 200;
		else
			arg->sizex = tmp1;
		if (tmp2 <= 0 || tmp2 > 1350)
			ft_error("fractol", 1, "Y size"), arg->sizey = 200;
		else
			arg->sizey = tmp2;
	}
	else
	{
		arg->sizex = 200;
		arg->sizey = 200;
	}
}

void		ft_initvar(t_arg *arg)
{
	arg->i = 100;
	if (arg->sizex <= arg->sizey)
		arg->z = (double)arg->sizex / (double)arg->sizey / 2;
	else
		arg->z = (double)arg->sizey / (double)arg->sizex / 2;
	arg->posy = 0;
	arg->posx = 0;
	arg->freq = 1;
	arg->r = 0.2;
	arg->g = 0.4;
	arg->b = 0.8;
	arg->pretty = 1;
	arg->n = 8;
	arg->prec = 1;
}

t_arg		ft_args(int ac, char **av)
{
	t_arg	arg;

	ft_size(ac, av, &arg);
	ft_fracarg(ac, av, &arg);
	ft_initvar(&arg);
	arg.mouse = 1;
	return (arg);
}
