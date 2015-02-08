/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 18:05:49 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/07 18:54:35 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_rgbtohexa(float r, float g, float b)
{
	return (0xFF & (int)r) << 16 | (0xFF & (int)g) << 8 | (0xFF & (int)b);
}

int	ft_color(double i, int max)
{
    if (i == max)
        return (0);
    else
        i = log(i) / 2.71828182846;
    if (i < 0.33)
        return (ft_rgbtohexa(255 - 1020 * i * i, 200, 200));
    else if (i > 0.33 && i < 0.66)
        return (ft_rgbtohexa(200, 255 - 1020 * (i - 0.5) * (i - 0.5), 200));
    else
        return (ft_rgbtohexa(200, 200, 255 - 1020 * (i - 1) * (i - 1)));
}