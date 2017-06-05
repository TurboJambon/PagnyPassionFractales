/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 18:39:24 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/05 20:30:30 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook_j(int button, int x, int y, t_env *e)
{
	if (button == 4)
	{
		ft_zoom(x, y, e);
		ft_julia(e, e->p1, e->p2, cplx_new(e->new_x, e->new_y));
	}
	if (button == 5)
	{
		ft_dezoom(x, y, e);
		ft_julia(e, e->p1, e->p2, cplx_new(e->new_x, e->new_y));
	}
	return (0);
}

int		mouse_julia(int x, int y, t_env *e)
{
	e->new_x = ((float)x / WINX) * (e->p2.x - e->p1.x) + e->p1.x;
	e->new_y = ((float)y / WINY) * (e->p2.y - e->p1.y) + e->p1.y;
	ft_julia(e, e->p1, e->p2, cplx_new(e->new_x, e->new_y));
	return (0);
}

int		key_hook_j(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == KEY_RIGHT)
	{
		ft_movexr(e);
		ft_julia(e, e->p1, e->p2, cplx_new(e->new_x, e->new_y));
	}
	else if (keycode == KEY_LEFT)
	{
		ft_movexl(e);
		ft_julia(e, e->p1, e->p2, cplx_new(e->new_x, e->new_y));
	}
	else if (keycode == KEY_DOWN)
	{
		ft_moveyd(e);
		ft_julia(e, e->p1, e->p2, cplx_new(e->new_x, e->new_y));
	}
	else if (keycode == KEY_UP)
	{
		ft_moveyu(e);
		ft_julia(e, e->p1, e->p2, cplx_new(e->new_x, e->new_y));
	}
	return (0);
}

void	julia_calc(t_env *e, t_pnt *min, t_cplx c)
{
	t_cplx	z;

	z = cplx_new(min->x, min->y);
	e->i = 0;
	while (e->i < ITER_MAX && ((z.re * z.re) + (z.im * z.im)) <= 4)
	{
		z = cplx_add(cplx_mul(z, z), c);
		e->i++;
	}
	if (e->i != ITER_MAX)
		mlx_pixel_put(e->image, e->win, e->x, e->y, ft_getcolor((float)e->i
		+ 1 - log(log(4) / log(z.re * z.re + z.im * z.im)) / log(2)));
}

void	ft_julia(t_env *e, t_pnt min, t_pnt max, t_cplx c)
{
	float	step;
	float	tmp;

	mlx_clear_window(e->mlx, e->win);
	step = (max.x - min.x) / WINX;
	tmp = min.x;
	e->y = 0;
	while (min.y < max.y)
	{
		e->x = 0;
		min.x = tmp;
		while (min.x < max.x)
		{
			julia_calc(e, &min, c);
			min.x += step;
			e->x++;
		}
		min.y += step;
		e->y++;
	}
}
