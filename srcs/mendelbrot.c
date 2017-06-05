/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:14:33 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/05 16:29:28 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

unsigned int    ft_getcolor(float i)
{
	i = log(ITER_MAX - i) / log(ITER_MAX / 2.55) * 4.997083;
    if (i >= 0 && i < 1)
        return (0x0000FF + (int)(i * 255) * 0x010000);
    if (i >= 1 && i < 2)
        return (0xFF00FF - (int)((i - 1) * 255));
    if (i >= 2 && i < 3)
        return (0xFF0000 + (int)((i - 2) * 255) * 0x000100);
    if (i >= 3 && i < 4)
        return (0xFFFF00 - (int)((i - 3) * 255) * 0x010000);
    if (i >= 4 && i < 5)
        return (0x00FF00 + (int)((i - 4) * 255));
    if (i >= 5 && i < 6)
        return (0x00FFFF - (int)((i - 5) * 255) * 0x000100);
    return (0);
}

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

void	ft_mendelbrot(t_env *e, t_pnt min, t_pnt max)
{
	float	step;
	float	tmp;
	t_cplx 	z;
	int 	x;
	int 	y;
	int     i;

	step = (max.x - min.x) / WINX;
	tmp = min.x;
	y = 0;
	while (min.y < max.y)
	{
		min.x = tmp;
		x = 0;
		while (min.x < max.x)
		{
			z = cplx_new(0, 0);
			i = 0;
			while (i < ITER_MAX && ((z.re * z.re) + (z.im * z.im)) <= 4)
			{
				z = cplx_add(cplx_mul(z, z), cplx_new(min.x, min.y));
				i++;
			}
			if (i != ITER_MAX)
				mlx_pixel_put(e->image, e->win, x, y, ft_getcolor((float)i + 1 - log(log(4) / log(z.re * z.re + z.im * z.im)) / log(2)));
			min.x += step;
			x++;
		}
		y++;
		min.y += step;
	}
}

void	ft_julia(t_env *e, t_pnt min, t_pnt max, t_cplx c)
{
	t_cplx 	z;
	float	step;
	float	tmp;
	float	x;
	float	y;
	int 	i;

	step = (max.x - min.x) / WINX;
	tmp = min.x;
	y = 0;
	while (min.y < max.y)
	{
		x = 0;
		min.x = tmp;
		while (min.x < max.x)
		{
			z = cplx_new(min.x, min.y);
			i = 0;
			while (i < ITER_MAX && ((z.re * z.re) + (z.im * z.im)) <= 4)
			{
				z = cplx_add(cplx_mul(z, z), c);
				i++;	
			}
			if (i != ITER_MAX)
				mlx_pixel_put(e->image, e->win, x, y, ft_getcolor((float)i + 1 - log(log(4) / log(z.re * z.re + z.im * z.im)) / log(2)));
			min.x += step;
			x++;
		}
		min.y += step;
		y++;
	}
}
