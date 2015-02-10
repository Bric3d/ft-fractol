/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 12:59:52 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/10 17:11:57 by bbecker          ###   ########.fr       */
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

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_x
{
	void	*mlx;
	void	*win;
}				t_x;

typedef struct	s_arg
{
	short			sizex;
	short			sizey;
	unsigned int	i;
	t_x				*x;
	double			z;
	double			posx;
	double			posy;
	int				bpp;
	void			*img;
	char			*pimg;
	int				size_line;
	int				endian;
	int				fract;
	double			freq;
	double			r;
	double			g;
	double			b;
	short			pretty;
	short			n;
}				t_arg;

typedef struct s_pts
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
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

int		ft_color(double i, int max, t_pts *pts, t_arg *arg);

#endif