/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:18:13 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/06 12:10:49 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	ft_getcolor(double i)
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

int				is_infinite(t_cplx z, t_cplx c)
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
