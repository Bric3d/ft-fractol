/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 10:46:05 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/13 18:43:47 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	motion_hook(int x, int y, t_arg *arg)
{
	if ((arg->fract == 3 || arg->fract == 4) && arg->mouse == 1)
	{
		arg->const1 = x / (double)arg->sizex * 4 - 2;
		arg->const2 = y / (double)arg->sizey * 4 - 2;
		ft_putimg(arg);
		(void)x;
	}
	return (0);
}

static void	mousezoom(int button, int x, int y, t_arg *arg)
{
	double	tmp;
	double	zoom;

	if (button == 3)
	{
		zoom = 0.5;
		arg->i -= 2;
	}
	if (button == 1)
	{
		zoom = 2;
		arg->i += 2;
	}
	tmp = (double)x / (double)arg->sizex;
	arg->posx -= tmp * (-3.75 / arg->z) + (1.875 / arg->z);
	tmp = (double)y / (double)arg->sizey;
	arg->posy -= tmp * (-2.5 / arg->z) + (1.25 / arg->z);
	arg->z *= zoom;
	ft_putimg(arg);
}


int mouse_hook(int button, int x, int y, t_arg *arg)
{
	(void)x;
	(void)y;

	if (button != 1 && button != 3)
		randomcolor(32, arg);
	if (button == 1 || button == 3)
		mousezoom(button, x, y, arg);
	return (0);
}