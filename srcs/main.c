/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 12:49:44 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/08 18:17:46 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pts	*ft_pts(t_arg *arg)
{
	t_pts *pts;

	pts = (t_pts *)ft_memallocpp(sizeof(t_x), &ft_error);
	pts->x1 = -2.1;
	pts->x2 = 0.6;
	pts->y1 = -1.2;
	pts->y2 = 1.2;
	pts->zoom_x = (double)arg->sizex/(pts->x2 - pts->x1) + arg->z;
	pts->zoom_y = (double)arg->sizey/(pts->y2 - pts->y1) + arg->z;
	pts->c_r = 0;
	pts->c_i = 0;
	pts->z_r = 0;
	pts->z_i = 0;
	pts->i = 0;
	return (pts);
}

void	resetpts(t_pts *pts)
{
	pts->z_r = 0;
	pts->z_i = 0;
	pts->i = 0;
}

void	ft_putpxl(t_arg *arg, int x, int y, int color)
{
	mlx_pixel_put(arg->x->mlx, arg->x->win, x + arg->posx, y + arg->posy, color);
}

int		mandelbrot(t_arg *arg)
{
	t_pts	*pts;
	int		x;
	int		y;
	double	tmp;

	x = 0;
	pts = ft_pts(arg);
	while (x + arg->posx < arg->sizex)
	{
		y = 0;
		while (y + arg->posy < arg->sizey)
		{
			pts->c_r = (double)x / pts->zoom_x + pts->x1;
			pts->c_i = (double)y / pts->zoom_y + pts->y1;
			while((pts->z_r*pts->z_r + pts->z_i*pts->z_i) < 4 && pts->i < arg->i)
			{
				tmp = pts->z_r;
				pts->z_r = pts->z_r*pts->z_r - pts->z_i*pts->z_i + pts->c_r;
				pts->z_i = 2*pts->z_i*tmp + pts->c_i;
            	pts->i = pts->i+1;
			}
			ft_putpxl(arg, x, y, ft_color(pts->i, arg->i));
			resetpts(pts);
			y++;
		}
		x++;
	}
	free(pts);
	return (0);
}

void	*wininit(t_arg *arg)
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

t_arg	*ft_args(int ac, char **av)
{
	t_arg	*arg;
	int		tmp;

	arg = (t_arg *)ft_memallocpp(sizeof(t_arg *), &ft_error);
	if (ac == 3)
	{
		tmp = ft_atoi(av[1]);
		if (tmp <= 0 || tmp > 2560)
			ft_error("fractol", 1, "X size"), arg->sizex = 200;
		else
			arg->sizex = tmp;
		tmp = ft_atoi(av[2]);
		if (tmp <= 0 || tmp > 1350)
			ft_error("fractol", 1, "Y size"), arg->sizey = 200;
		else
			arg->sizey = tmp;
	}
	else
	{
		arg->sizex = 200;
		arg->sizey = 200;
	}
	arg->i = 50;
	arg->z = 0;
	arg->posy = 0;
	arg->posx = 0;
	return (arg);
}

int		ft_expose(t_arg *arg)
{
	mlx_clear_window(arg->x->mlx, arg->x->win);
	mandelbrot(arg);
	return (0);
}

void	ft_move( int kc, t_arg *arg)
{
	int x;
	int y;

	y = arg->sizey / 10;
	x = arg->sizex / 10;
	if (kc == 65362)
		arg->posy = arg->posy + y;
	if (kc == 65364)
		arg->posy = arg->posy - y;
	if (kc == 65361)
		arg->posx = arg->posx + x;
	if (kc == 65363)
		arg->posx = arg->posx - x;
	ft_expose(arg);
}

int		ft_key_hook(int kc, t_arg *arg)
{
	if ((kc == 45 || kc == 61 || kc == 65453|| kc == 65451) && arg->i >= 50)
	{
		if (kc == 45 || kc == 65453)
		{
			arg->i--;
			arg->z -= 10;
		}
		if (kc == 61 || kc == 65451)
		{
			arg->i++;
			arg->z += 10;
		}
		ft_expose(arg);
	}
	if (kc == 65362 || kc == 65364 || kc == 65361 || kc == 65363)
		ft_move(kc, arg);
	if (kc == 65307)
		exit (0);
	return (0);
}

int		main(int ac, char **av)
{
	t_arg	*arg;

	arg = ft_args(ac, av);
	arg->x = wininit(arg);
	mandelbrot(arg);
	mlx_key_hook(arg->x->win, ft_key_hook, arg);
	mlx_expose_hook(arg->x->win, ft_expose, arg);
	mlx_loop(arg->x->mlx);
	return (0);
}