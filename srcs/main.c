/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 12:49:44 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/15 15:37:21 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fracarg(int ac, char **av, t_arg *arg)
{
	char *tmp;

	tmp = NULL;
	if (ac == 2 || ac == 4)
		tmp = av[1];
	if (ft_strcmp(tmp, "mandelbrot") == 0)
		arg->fract = 1;
	else if (ft_strcmp(tmp, "burning_ship") == 0)
		arg->fract = 2;
	else if (ft_strcmp(tmp, "julia") == 0)
		arg->fract = 3;
	else if (ft_strcmp(tmp, "julia2") == 0)
		arg->fract = 4;
	else if (ft_strcmp(tmp, "carpet") == 0)
		arg->fract = 5;
	else if (ft_strcmp(tmp, "special1") == 0)
		arg->fract = 9;
	else
		arg->fract = 1;
}

int		main(int ac, char **av)
{
	t_arg	arg;

	arg = ft_args(ac, av);
	arg.x = wininit(&arg);
	ft_putimg(&arg);
	mlx_key_hook(arg.x->win, ft_key_hook, &arg);
	mlx_expose_hook(arg.x->win, ft_putimg, &arg);
	mlx_hook(arg.x->win, 4, 5, mouse_hook, &arg);
	mlx_hook(arg.x->win, 1, 1, ft_key_hook, &arg);
	mlx_hook(arg.x->win, 6, 64, motion_hook, &arg);
	mlx_loop(arg.x->mlx);
	return (0);
}
