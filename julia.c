/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:34:25 by ojebbari          #+#    #+#             */
/*   Updated: 2023/05/17 15:44:08 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	julia(double a, double b, t_vars *hadik)
{
	double		zr;
	double		zi;
	double		tmp;
	int			i;

	i = 0;
	zr = a;
	zi = b;
	while (i < ITER && mag(zr, zi) < 2.0)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + hadik->mouse_x ;
		zi = 2 * tmp * zi + hadik->mouse_y;
		i++;
	}
	return (i);
}

void render_julia(t_vars *hadik)
{
	int i;
	int j;
	int it;

	i = 0;
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			it = (julia((i - WIDTH / 2) / hadik->zoom, \
			(j - HEIGHT / 2) / hadik->zoom, hadik) / ITER) * 255;
			my_mlx_pixel_put(hadik, i, j, create_trgb(0, it, it, it));
			i++;
		}
		j++;
	}
}
