/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 17:34:14 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/06 12:10:29 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_movexr(t_env *e)
{
	e->p1.x += 0.1 / e->move_x;
	e->p2.x += 0.1 / e->move_x;
}

void		ft_movexl(t_env *e)
{
	e->p1.x -= 0.1 / e->move_x;
	e->p2.x -= 0.1 / e->move_x;
}

void		ft_moveyu(t_env *e)
{
	e->p1.y -= 0.1 / e->move_x;
	e->p2.y -= 0.1 / e->move_x;
}

void		ft_moveyd(t_env *e)
{
	e->p1.y += 0.1 / e->move_x;
	e->p2.y += 0.1 / e->move_x;
}
