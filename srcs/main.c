/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 12:49:44 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/09 18:24:13 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pts	*ft_pts()
{
	t_pts *pts;

	pts = (t_pts *)ft_memallocpp(sizeof(t_x), &ft_error);
	pts->x1 = -2.1;
	pts->x2 = 0.6;
	pts->y1 = -1.2;
	pts->y2 = 1.2;
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
	int i;

	if (x < 0 || y < 0 || x >= arg->sizex || y >= arg->sizey)
		return ;
	i = x * 4 + y * arg->size_line;
	arg->pimg[i] = (color & 0xFF);
	arg->pimg[i + 1] = (color & 0xFF00) >> 8;
	arg->pimg[i + 2] = (color & 0xFF0000) >> 16;
}

int		mandelbrot(t_arg *arg)
{
	t_pts	*pts;
	double	x;
	double	y;
	double	tmp;

	x = 0;
	pts = ft_pts();
	while (x < arg->sizex)
	{
		y = 0;
		while (y < arg->sizey)
		{
			pts->c_r = 1.5 * (x - (double)arg->sizex / 2) / (0.5 * arg->z * (double)arg->sizex) + (double)arg->posx;
            pts->c_i = (y - (double)arg->sizex / 2) / (0.5 * arg->z * (double)arg->sizex) + (double)arg->posy; 
			//pts->c_r = (double)x / pts->zoom_x + pts->x1;
			//pts->c_i = (double)y / pts->zoom_y + pts->y1;
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
		arg->sizex = 10;
		arg->sizey = 10;
	}
	arg->i = 50;
	arg->z = 0.8;
	arg->posy = 0;
	arg->posx = 0;
	arg->fract = 1;
	return (arg);
}

void	choosefract(t_arg *arg)
{
	if (arg->fract == 1)
		mandelbrot(arg);
}

int		ft_putimg(t_arg *arg)
{
	//int		(*mandelbot)(struct s_arg *);

	//mandelbot = &mandelbrot;
	arg->img = mlx_new_image(arg->x->mlx, arg->sizex, arg->sizey);
	arg->pimg = mlx_get_data_addr(arg->img, &(arg->bpp),
	&(arg->size_line), &(arg->endian));
	choosefract(arg);
	mlx_put_image_to_window(arg->x->mlx, arg->x->win, arg->img, 0, 0);
	mlx_destroy_image(arg->x->mlx, arg->img);
	return (0);
}

void	ft_move( int kc, t_arg *arg)
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

int		ft_key_hook(int kc, t_arg *arg)
{
	if ((kc == 45 || kc == 61 || kc == 65453|| kc == 65451) && arg->i >= 8)
	{
		if (kc == 45 || kc == 65453)
		{
			arg->i--;
			arg->z /= 1.5;
		}
		if (kc == 61 || kc == 65451)
		{
			arg->i++;
			arg->z *= 1.5;
		}
		ft_putimg(arg);
	}
	if (kc == 49 || kc == 50 || kc == 51 || kc == 52 || kc == 53 || kc == 54 || kc == 55 || kc == 56 || kc == 57)
		selectfrac(kc, arg);
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
	ft_putimg(arg);
	mlx_key_hook(arg->x->win, ft_key_hook, arg);
	mlx_expose_hook(arg->x->win, ft_putimg, arg);
	mlx_loop(arg->x->mlx);
	return (0);
}