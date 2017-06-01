/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:21:08 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/01 17:45:27 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_env *e)
{
	(void)e;
	if (keycode == 53)
		exit(0);
	return (0);
}

void	choose_fractal(char **av, int ac)
{
	int 	i;
	t_env 	e[ac - 1];

	i = 0;
	while (i < ac - 1)
	{
		if (!(e[i].mlx = mlx_init()))
			return ;
		e[i].win = mlx_new_window(e[i].mlx, WINX, WINY, "Fractol");
		e[i].image = mlx_new_image(e[i].mlx, WINY, WINY);
		mlx_put_image_to_window(e[i].mlx, e[i].win, e[i].image, 0, 0);
		if (ft_strcmp("julia", av[i + 1]) == 0)
			ft_julia(&e[i], -1, 0.5, cplx_new(0.285, 0.013));
		if (ft_strcmp("mendelbrot", av[i + 1]) == 0)
			ft_mendelbrot(&e[i], -1, 0.5);
		mlx_hook(e[i].win, 2, 3, key_hook, &e[i]);
		i++;
	}
	mlx_loop(e[i - 1].mlx);
}

int		main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr_fd("input error", 2);
		return (0);
	}
	choose_fractal(av, ac);
	return (0);
}