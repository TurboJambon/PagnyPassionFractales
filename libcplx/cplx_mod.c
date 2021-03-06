/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:38:58 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/05 20:50:26 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	cplx_mod(t_cplx p1)
{
	return (sqrt((p1.re * p1.re) + (p1.im * p1.re)));
}
