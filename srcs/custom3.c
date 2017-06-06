/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:13:37 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/06 12:27:29 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cplx			ft_cplxpow(t_cplx z, int pow)
{
	t_cplx	ret;
	int		i;

	if (pow <= 0)
		return (cplx_new(0, 0));
	if (pow == 1)
		return (z);
	ret = z;
	i = 1;
	while ((i <<= 1) <= pow)
		ret = cplx_mul(ret, ret);
	i >>= 1;
	while (i++ < pow)
		ret = cplx_mul(ret, z);
	return (ret);
}

int				mouse_hook_c3(int button, int x, int y, t_env *e)
{
	if (button == 4)
	{
		ft_zoom(x, y, e);
		ft_custom3(e, e->p1, e->p2);
	}
	if (button == 5)
	{
		ft_dezoom(x, y, e);
		ft_custom3(e, e->p1, e->p2);
	}
	return (0);
}

int				key_hook_c3(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == KEY_RIGHT)
	{
		ft_movexr(e);
		ft_custom3(e, e->p1, e->p2);
	}
	else if (keycode == KEY_LEFT)
	{
		ft_movexl(e);
		ft_custom3(e, e->p1, e->p2);
	}
	else if (keycode == KEY_DOWN)
	{
		ft_moveyd(e);
		ft_custom3(e, e->p1, e->p2);
	}
	else if (keycode == KEY_UP)
	{
		ft_moveyu(e);
		ft_custom3(e, e->p1, e->p2);
	}
	return (0);
}

void			custom3_calc(t_env *e, t_pnt *min)
{
	t_cplx	z;

	z = cplx_new(0, 0);
	e->i = 0;
	while (e->i < ITER_MAX && ((z.re * z.re) + (z.im * z.im)) <= 4)
	{
		z = cplx_add(ft_cplxpow(z, 20), cplx_new(min->x, min->y));
		e->i++;
	}
	if (e->i != ITER_MAX)
		mlx_pixel_put(e->image, e->win, e->x, e->y, ft_getcolor((double)e->i
		+ 1 - log(log(4) / log(z.re * z.re + z.im * z.im)) / log(2)));
}

void			ft_custom3(t_env *e, t_pnt min, t_pnt max)
{
	double	step;
	double	tmp;

	mlx_clear_window(e->mlx, e->win);
	step = (max.x - min.x) / WINX;
	tmp = min.x;
	e->y = 0;
	while (min.y < max.y)
	{
		min.x = tmp;
		e->x = 0;
		while (min.x < max.x)
		{
			custom3_calc(e, &min);
			min.x += step;
			e->x++;
		}
		e->y++;
		min.y += step;
	}
}
