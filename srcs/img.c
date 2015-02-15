/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 14:47:40 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/15 16:14:26 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_pts	*ft_pts(void)
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

static void		resetpts(t_pts *pts)
{
	pts->z_r = 0;
	pts->z_i = 0;
	pts->i = 0;
}

static void		ft_putpxl(t_arg *arg, int x, int y, int color)
{
	int i;

	if (x < 0 || y < 0 || x >= arg->sizex || y >= arg->sizey)
		return ;
	i = x * 4 + y * arg->size_line;
	arg->pimg[i] = (color & 0xFF);
	arg->pimg[i + 1] = (color & 0xFF00) >> 8;
	arg->pimg[i + 2] = (color & 0xFF0000) >> 16;
}

static int		fractbase(t_arg *arg)
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
			resetpts(pts);
			y++;
		}
		x++;
	}
	free(pts);
	return (0);
}

int				ft_putimg(t_arg *arg)
{
	arg->img = mlx_new_image(arg->x->mlx, arg->sizex, arg->sizey);
	arg->pimg = mlx_get_data_addr(arg->img, &(arg->bpp),
	&(arg->size_line), &(arg->endian));
	fractbase(arg);
	mlx_put_image_to_window(arg->x->mlx, arg->x->win, arg->img, 0, 0);
	mlx_destroy_image(arg->x->mlx, arg->img);
	return (0);
}
