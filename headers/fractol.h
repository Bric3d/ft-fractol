/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 12:59:52 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/15 16:23:56 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <errno.h>
# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct		s_x
{
	void			*mlx;
	void			*win;
}					t_x;

typedef struct		s_arg
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
	double			const1;
	double			const2;
	short			mouse;
	double			prec;
}					t_arg;

typedef struct		s_pts
{
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			i;
}					t_pts;

/*
**	fractals.c
*/

double				mandelbrot(t_arg *arg, t_pts *pts, double x, double y);
double				burning_ship(t_arg *arg, t_pts *pts, double x, double y);
double				special1(t_arg *arg, t_pts *pts, double x, double y);
double				julia(t_arg *arg, t_pts *pts, double x, double y);
double				julia2(t_arg *arg, t_pts *pts, double x, double y);

/*
**	fractals2.c
*/

double				carpet(int x, int y);

/*
**	error.c
*/

void				ft_error(char *name, int error, char *cause);

/*
**	tools.c
*/

double				choosefract(t_arg arg, t_pts pts, double x, double y);

/*
**	color.c
*/

int					ft_color(double i, int max, t_arg arg);

/*
**	random.c
*/

void				randomcolor(int kc, t_arg *arg);
void				printrgb(t_arg *arg);

/*
**	keys.c
*/

int					ft_key_hook(int kc, t_arg *arg);
void				ft_toogleprecision(int kc, t_arg *arg);
void				ft_changetar(int kc, t_arg *arg);
void				ft_changergb(int kc, t_arg *arg);

/*
**	keys2.c
*/

void				ft_zoom(int kc, t_arg *arg);
void				ft_iterate(int kc, t_arg *arg);
void				ft_reset(int kc, t_arg *arg);
void				selectfrac(int kc, t_arg *arg);
void				ft_move(int kc, t_arg *arg);

/*
**	mouse_hook.c
*/

int					motion_hook(int x, int y, t_arg *arg);
int					mouse_hook(int button, int x, int y, t_arg *arg);

/*
**	img.c
*/

int					ft_putimg(t_arg *arg);

/*
**	init.c
*/

t_arg				ft_args(int ac, char **av);
void				ft_initvar(t_arg *arg);
void				*wininit(t_arg *arg);

/*
**	main.c
*/

void				ft_fracarg(int ac, char **av, t_arg *arg);

#endif
