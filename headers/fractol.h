/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 12:59:52 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/08 17:55:56 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <errno.h> 
#include "libft.h"
#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_x
{
	void	*mlx;
	void	*win;
}				t_x;

typedef struct	s_arg
{
	short	sizex;
	short	sizey;
	short	i;
	t_x		*x;
	int		z;
	int		posx;
	int		posy;
}				t_arg;

typedef struct s_pts
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	zoom_x;
	double	zoom_y;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	i;
}				t_pts;

/*
 *	error.c
 */

void	ft_error(char *name, int error, char *cause);

/*
 *	color.c
 */

int		ft_color(double i, int max);

#endif