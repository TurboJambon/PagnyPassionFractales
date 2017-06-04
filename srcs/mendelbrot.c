/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:14:33 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/04 20:24:26 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>

int		is_infinite(t_cplx z, t_cplx c)
{
	int	i;

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

int		is_dchirol(t_cplx z, t_cplx c)
{
	int	i;

	i = 0;
	while (i < ITER_MAX)
	{
		if ()
			return (i);
		i++;
	}
	return (-1);
}

void	ft_mendelbrot(t_env *e, t_pnt min, t_pnt max)
{
	float	step;
	float	tmp;
	int 	x;
	int 	y;
	int		color;

	step = (max.x - min.x) / WINX;
	tmp = min.x;
	y = 0;
	while (min.y < max.y)
	{
		min.x = tmp;
		x = 0;
		while (min.x < max.x)
		{
			if ((color = is_infinite(cplx_new(0, 0),
				cplx_new(min.x, min.y))) >= 0)
				mlx_pixel_put(e->image, e->win, x, y, color);
			min.x += step;
			x++;
		}
		y++;
		min.y += step;
	}
}

void	ft_dchirol(t_env *e, t_pnt min, t_pnt max)
{
	float	step;
	float	tmp;
	float	x;
	float	y;
	int		color;

	step = (max.x - min.x) / WINX;
	tmp = min.x;
	y = 0;
	while (min.y < max.y)
	{
		x = 0;
		min.x = tmp;
		while (min.x < max.x)
		{
			if ((color = is_dchirol(x, y) >= 0))
				mlx_pixel_put(e->image, e->win, x, y, color);
			min.x += step;
			x++;
		}
		min.y += step;
		y++;
	}
}

void	ft_julia(t_env *e, t_pnt min, t_pnt max, t_cplx c)
{
	float	step;
	float	tmp;
	float	x;
	float	y;
	int		color;

	step = (max.x - min.x) / WINX;
	tmp = min.x;
	y = 0;
	while (min.y < max.y)
	{
		x = 0;
		min.x = tmp;
		while (min.x < max.x)
		{
			if ((color = is_infinite(cplx_new(min.x + (step * x),
				min.y + (step * y)), c)) >= 0)
				mlx_pixel_put(e->image, e->win, x, y, color);
			min.x += step;
			x++;
		}
		min.y += step;
		y++;
	}
}
