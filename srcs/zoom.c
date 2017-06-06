/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 18:38:08 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/06 11:36:11 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_zoom(int x, int y, t_env *e)
{
	double new_x;
	double new_y;

	new_x = ((double)x / WINX) * (e->p2.x - e->p1.x) + e->p1.x;
	new_y = ((double)y / WINY) * (e->p2.y - e->p1.y) + e->p1.y;
	e->p1.x = new_x - ((new_x - e->p1.x) * 0.5);
	e->p2.x = new_x + ((e->p2.x - new_x) * 0.5);
	e->p1.y = new_y - ((new_y - e->p1.y) * 0.5);
	e->p2.y = new_y + ((e->p2.y - new_y) * 0.5);
	e->move_x *= 1.8;
	e->move_y *= 1.8;
}

void		ft_dezoom(int x, int y, t_env *e)
{
	double new_x;
	double new_y;

	new_x = ((double)x / WINX) * (e->p2.x - e->p1.x) + e->p1.x;
	new_y = ((double)y / WINY) * (e->p2.y - e->p1.y) + e->p1.y;
	e->p1.x = new_x - ((new_x - e->p1.x) / 0.5);
	e->p2.x = new_x + ((e->p2.x - new_x) / 0.5);
	e->p1.y = new_y - ((new_y - e->p1.y) / 0.5);
	e->p2.y = new_y + ((e->p2.y - new_y) / 0.5);
	e->move_x /= 1.8;
	e->move_y /= 1.8;
}
