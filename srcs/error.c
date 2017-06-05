/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:58:04 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/05 20:38:41 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	input_error(void)
{
	ft_putstr_fd(RED, 1);
	ft_putstr_fd(
	"/!\\ Input error, please type one of the following /!\\\n"
	,1);
	ft_putstr_fd(GRN, 1);
	ft_putstr_fd("-- \t\tJulia\n", 1);
	ft_putstr_fd("-- \t\tMandelbrot\n", 1);
	ft_putstr_fd("-- \t\tDoubleBrot\n", 1);
	ft_putstr_fd(RESET, 1);
}

int		window_error(void)
{
	ft_putstr_fd("Minilibx failed to open a window\n", 2);
	return (-1);
}
