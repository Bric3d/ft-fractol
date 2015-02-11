/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 12:49:44 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/11 17:16:40 by bbecker          ###   ########.fr       */
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

int		fractbase(t_arg *arg)
{
	t_pts	*pts;
	double	x;
	double	y;
	double	i;

	x = 0;
	pts = ft_pts();
	while (x < arg->sizex)
	{
		y = 0;
		while (y < arg->sizey)
		{
			i = choosefract(*arg, *pts, x, y);
			ft_putpxl(arg, x, y, ft_color(i, arg->i, *arg));
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

void	ft_initvar(t_arg *arg)
{
	arg->i = 50;
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
}

void	ft_size(int ac, char **av, t_arg *arg)
{
	int		tmp1;
	int		tmp2;

	if (ac == 4)
	{
		tmp1 = ft_atoi(av[2]);
		tmp2 = ft_atoi(av[3]);
	}
	if (ac == 4 || (ac == 3 && (tmp1 = ft_atoi(av[1])) > 0 && (tmp2 = ft_atoi(av[2])) > 0))
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
	else if (ft_strcmp(tmp, "special1") == 0)
		arg->fract = 9;
	else
		arg->fract = 1;
}

t_arg	ft_args(int ac, char **av)
{
	t_arg	arg;

	ft_size(ac, av, &arg);
	ft_fracarg(ac, av, &arg);
	ft_initvar(&arg);
	return (arg);
}

int		ft_putimg(t_arg *arg)
{
	arg->img = mlx_new_image(arg->x->mlx, arg->sizex, arg->sizey);
	arg->pimg = mlx_get_data_addr(arg->img, &(arg->bpp),
	&(arg->size_line), &(arg->endian));
	fractbase(arg);
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

void	ft_reset(int kc, t_arg *arg)
{
	if (kc == 114)
		ft_initvar(arg);
	ft_putimg(arg);
}

void	ft_iterate(int kc, t_arg *arg)
{
	if (kc == 65455)
		arg->i = arg->i - 1;
	if (kc == 65450)
		arg->i = arg->i + 1;
	ft_putimg(arg);
}

void	ft_zoom(int kc, t_arg *arg)
{
	if ((kc == 45 || kc == 65453) && arg->i > 1 && arg->z > 0)
	{
		arg->i--;
		arg->z /= 1.5;
	}
	if ((kc == 61 || kc == 65451) && arg->z * 1.5 < 220076276500268)
	{
		arg->i++;
		arg->z *= 1.5;
	}
	ft_putimg(arg);
}

void	ft_putdouble(double n, short size)
{
	int		tmp;
	short	i;

	if (size > 18)
		size = 18;
	i = 0;
	if ((int)n == 0 && n < 0)
		ft_putchar('-');
	ft_putnbr((int)n);
	if ((int)n != n)
		ft_putchar(',');
	tmp = (int)n;
	n = n - (double)tmp;
	while (i < 19)
	{
		n = n * 10;
		tmp = (int)n;
		n = n - (double)tmp;
		if (tmp < 0)
			tmp = -tmp;
		ft_putchar('0' + tmp);
		i++;
	}
}

void	ft_changergb(int kc, t_arg *arg)
{
	if (kc == 65465 && arg->r >= 0.1)
		arg->r = arg->r - 0.1;
	if (kc == 65463 && arg->r <= 0.9)
		arg->r = arg->r + 0.1;
	if (kc == 65462 && arg->g >= 0.1)
		arg->g = arg->g - 0.1;
	if (kc == 65460 && arg->g <= 0.9)
		arg->g = arg->g + 0.1;
	if (kc == 65459 && arg->b >= 0.1)
		arg->b = arg->b - 0.1;
	if (kc == 65457 && arg->b <= 0.9)
		arg->b = arg->b + 0.1;
	ft_putstr("\r                                \rR :");
	ft_putnbr(100 - (int)(arg->r * 100));
	ft_putstr("%  G :");
	ft_putnbr(100 - (int)(arg->g * 100));
	ft_putstr("%  B :");
	ft_putnbr(100 - (int)(arg->b * 100));
	ft_putstr("%");
	ft_putimg(arg);
}

void	ft_changetar(int kc, t_arg *arg)
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
	if (arg->n > 3)
		ft_putimg(arg);
}

int		ft_key_hook(int kc, t_arg *arg)
{
	if (kc == 45 || kc == 61 || kc == 65453|| kc == 65451)
		ft_zoom(kc, arg);
	if (kc == 49 || kc == 50 || kc == 51 || kc == 52 || kc == 53 || kc == 54 || kc == 55 || kc == 56 || kc == 57)
		selectfrac(kc, arg);
	if (kc == 65362 || kc == 65364 || kc == 65361 || kc == 65363)
		ft_move(kc, arg);
	if (kc == 114)
		ft_reset(kc, arg);
	if (kc == 65463 || kc == 65465 || kc == 65460 || kc == 65462 || kc == 65457 || kc == 65459)
		ft_changergb(kc, arg);
	if (kc == 65455 || kc == 65450)
		ft_iterate(kc, arg);
	if (kc == 65365 || kc == 65366 || kc == 112)
		ft_changetar(kc, arg);
	if (kc == 65307)
	{
		ft_putchar('\n');
		exit (0);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_arg	arg;

	arg = ft_args(ac, av);
	arg.x = wininit(&arg);
	ft_putimg(&arg);
	mlx_key_hook(arg.x->win, ft_key_hook, &arg);
	mlx_expose_hook(arg.x->win, ft_putimg, &arg);
	mlx_loop(arg.x->mlx);
	return (0);
}