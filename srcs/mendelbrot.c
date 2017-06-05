/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:14:33 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/05 20:48:14 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_hook_m(int button, int x, int y, t_env *e)
{
	if (button == 4)
	{
		ft_zoom(x, y, e);
		ft_mendelbrot(e, e->p1, e->p2);
	}
	if (button == 5)
	{
		ft_dezoom(x, y, e);
		ft_mendelbrot(e, e->p1, e->p2);
	}
	return (0);
}

int				key_hook_m(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == KEY_RIGHT)
	{
		ft_movexr(e);
		ft_mendelbrot(e, e->p1, e->p2);
	}
	else if (keycode == KEY_LEFT)
	{
		ft_movexl(e);
		ft_mendelbrot(e, e->p1, e->p2);
	}
	else if (keycode == KEY_DOWN)
	{
		ft_moveyd(e);
		ft_mendelbrot(e, e->p1, e->p2);
	}
	else if (keycode == KEY_UP)
	{
		ft_moveyu(e);
		ft_mendelbrot(e, e->p1, e->p2);
	}
	return (0);
}

void			mendel_calc(t_env *e, t_pnt *min)
{
	t_cplx	z;

	z = cplx_new(0, 0);
	e->i = 0;
	while (e->i < ITER_MAX && ((z.re * z.re) + (z.im * z.im)) <= 4)
	{
		z = cplx_add(cplx_mul(z, z), cplx_new(min->x, min->y));
		e->i++;
	}
	if (e->i != ITER_MAX)
		mlx_pixel_put(e->image, e->win, e->x, e->y, ft_getcolor((double)e->i
		+ 1 - log(log(4) / log(z.re * z.re + z.im * z.im)) / log(2)));
}

void			ft_mendelbrot(t_env *e, t_pnt min, t_pnt max)
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
			mendel_calc(e, &min);
			min.x += step;
			e->x++;
		}
		e->y++;
		min.y += step;
	}
}
