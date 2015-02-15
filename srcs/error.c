/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbecker <bbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 14:53:10 by bbecker           #+#    #+#             */
/*   Updated: 2015/02/15 13:45:38 by bbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_error2(int error, char *cause)
{
	ft_putstr(cause);
	ft_putstr(": ");
	if (error == 1)
		ft_putendl("wrong size, unsing default instead");
}

void		ft_error(char *name, int error, char *cause)
{
	if (name)
	{
		ft_putstr(name);
		ft_putstr(": ");
	}
	if (errno != 0)
		perror(cause);
	else if (error != 0)
		ft_error2(error, cause);
}
