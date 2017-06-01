/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:14:33 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/01 17:51:04 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		is_infinite(t_cplx z, t_cplx c)
{
	int 	i;

	i = 0;
	while (i < ITER_MAX)
	{
		z = cplx_add(cplx_mul(z, z), c);
		if (((z.re * z.re) + (z.im * z.im)) > 4)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_mendelbrot(t_env *e, float min, float max)
{
	float 	step;
	float 	x;
	float 	y;
	int 	color;

	step = (max - min) / WINX;
	y = 0;
	while (y < WINY)
	{
		x = 0;
		while (x < WINX)
		{
			if ((color = is_infinite(cplx_new(0, 0), cplx_new(min + (step * x), min + (step * y)))) >= 0)
				mlx_pixel_put(e->image, e->win, x, y, color * 2.5);
			x++;
		}
		y++;
	}
}

void	ft_julia(t_env *e, float min, float max, t_cplx c)
{
	float 	step;
	float 	x;
	float 	y;
	int 	color;

	step = (max - min) / WINX;
	y = 0;
	while (y < WINY)
	{
		x = 0;
		while (x < WINX)
		{
			if ((color = is_infinite(cplx_new(min + (step * x), min + (step * y)), c)) >= 0)
				mlx_pixel_put(e->image, e->win, x, y, color * 2.5);
			x++;
		}
		y++;
	}
}