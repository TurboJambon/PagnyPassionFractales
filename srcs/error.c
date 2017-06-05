/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:58:04 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/05 18:44:21 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	input_error(void)
{
	ft_putstr_fd(
	"/!\\ Input error, please type one of the following /!\\\n"
	, 2);
	ft_putstr_fd("julia - mendelbrot\n", 2);
}

int		window_error(void)
{
	ft_putstr_fd("Minilibx failed to open a window\n", 2);
	return (-1);
}
