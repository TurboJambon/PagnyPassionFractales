/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:21:08 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/04 20:21:33 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"

void	 	ft_zoom(t_pnt *p1, t_pnt *p2, int x, int y)
{
	float new_x;
	float new_y;

	new_x = ((float)x / WINX) * (p2->x - p1->x) + p1->x;
	new_y = ((float)y / WINY) * (p2->y - p1->y) + p1->y; 
	p1->x = new_x - ((new_x - p1->x) * 0.9);
	p2->x = new_x + ((p2->x - new_x) * 0.9);
	p1->y = new_y - ((new_y - p1->y) * 0.9);
	p2->y = new_y + ((p2->y - new_y) * 0.9);
}

int		mouse_hook_j(int button, int x, int y, t_env *e)
{
	static	t_pnt p1 = {-1.5, -1.5};
	static	t_pnt p2 = {1, 1};
	static	double new_x = 0.285;
	static	double new_y = 0.013;
	
	if (button == 4)
	{
		ft_zoom(&p1, &p2, x, y);
		mlx_clear_window(e->mlx, e->win);
		ft_julia(e, p1, p2, cplx_new(new_x, new_y));
	}
	mlx_clear_window(e->mlx, e->win);
	new_x = ((float)x / WINX) * (p2.x - p1.x) + p1.x;
	new_y = ((float)y / WINY) * (p2.y - p1.y) + p1.y;
	ft_julia(e, p1, p2, cplx_new(new_x, new_y));
	return (0);
}

int		mouse_hook_m(int button, int x, int y, t_env *e)
{
	static t_pnt p1 = {-1.5, -1.5};
	static t_pnt p2 = {1, 1};

	if (button == 4)
	{
		ft_zoom(&p1, &p2, x, y);
		mlx_clear_window(e->mlx, e->win);
		ft_mendelbrot(e, p1, p2);
	}	
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	(void)e;

	if (keycode == 53)
		exit(0);
	return (0);
}

void	choose_fractal(char *av)
{
	t_env	e;
	static t_pnt p1 = {-1.5, -1.5};
	static t_pnt p2 = {1, 1};

	if (!(e.mlx = mlx_init()))
		return ;
	e.win = mlx_new_window(e.mlx, WINX, WINY, "Fractol");
	e.image = mlx_new_image(e.mlx, WINY, WINY);
	mlx_put_image_to_window(e.mlx, e.win, e.image, 0, 0);
	if (ft_strcmp("julia", av) == 0)
	{
			ft_julia(&e, p1, p2, cplx_new(0.285, 0.013));
			mlx_mouse_hook(e.win, mouse_hook_j, &e);
	}
	if (ft_strcmp("mendelbrot", av) == 0)
	{
		ft_mendelbrot(&e, p1, p2);
		mlx_mouse_hook(e.win, mouse_hook_m, &e);
	}
	if (ft_strcmp("dchirol", av) == 0)
	{
		ft_dchirol(&e, p1, p2);
		mlx_mouse_hook(e.win, mouse_hook_m, &e);
	}
	mlx_hook(e.win, 2, 3, key_hook, &e);
	mlx_loop(e.mlx);
}

int		main(int ac, char **av)
{
	int i;

	if (ac < 2)
	{
		input_error();
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		if (ft_strcmp("julia", av[i]) == 0 ||
			ft_strcmp("mendelbrot", av[i]) == 0 ||
			ft_strcmp("dchirol", av[i]) == 0)
			choose_fractal(av[1]);
		else
			input_error();
	}
	return (0);
}
