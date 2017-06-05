/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:21:08 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/05 20:39:37 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_mlx(t_env *e)
{
	e->p1.x = -1;
	e->p1.y = -1;
	e->p2.x = 1;
	e->p2.y = 1;
	e->move_x = 2;
	e->move_y = 2;
	if (!(e->mlx = mlx_init()))
		return (window_error());
	e->win = mlx_new_window(e->mlx, WINX, WINY, "Fractol");
	e->image = mlx_new_image(e->mlx, WINY, WINY);
	mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
	return (0);
}

void	choose_fractal(char *av, t_env *e)
{
	if (init_mlx(e) == -1)
		return ;
	else if (ft_strcmp("Julia", av) == 0)
	{
		e->new_x = 0.285;
		e->new_y = 0.013;
		ft_julia(e, e->p1, e->p2, cplx_new(e->new_x, e->new_y));
		mlx_mouse_hook(e->win, mouse_hook_j, e);
		mlx_hook(e->win, 6, 3, mouse_julia, e);
		mlx_hook(e->win, 2, 3, key_hook_j, e);
	}
	else if (ft_strcmp("Mandelbrot", av) == 0)
	{
		ft_mendelbrot(e, e->p1, e->p2);
		mlx_mouse_hook(e->win, mouse_hook_m, e);
		mlx_hook(e->win, 2, 3, key_hook_m, e);
	}
	else if (ft_strcmp("DoubleBrot", av) == 0)
	{
		ft_custom1(e, e->p1, e->p2);
		mlx_mouse_hook(e->win, mouse_hook_c1, e);
		mlx_hook(e->win, 2, 3, key_hook_c1, e);
	}	
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac < 2)
	{
		input_error();
		return (0);
	}
	if (ft_strcmp("Julia", av[1]) == 0 ||
		ft_strcmp("Mandelbrot", av[1]) == 0||
		ft_strcmp("DoubleBrot", av[1]) == 0)
		{
			choose_fractal(av[1], &e);
			mlx_loop(e.mlx);
		}
	else
		input_error();
	return (0);
}
