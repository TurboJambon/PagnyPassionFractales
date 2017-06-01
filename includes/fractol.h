/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:54:21 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/01 18:15:20 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define WINX 		500
# define WINY 		500
# define ITER_MAX 	100

# define KEY_LEFT	123
# define KEY_DOWN	125
# define KEY_RIGHT	124
# define KEY_UP		126

typedef struct	s_cplx
{
	float	re;
	float	im;
}				t_cplx;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*image;
}				t_env;

t_cplx			cplx_new(float re, float im);
t_cplx			cplx_add(t_cplx z1, t_cplx z2);
t_cplx			cplx_sub(t_cplx z1, t_cplx z2);
t_cplx			cplx_mul(t_cplx z1, t_cplx z2);
t_cplx			cplx_mod(t_cplx z1, t_cplx z2);

void			ft_mendelbrot(t_env *e, float min, float max);
void			ft_julia(t_env *e, float min, float max, t_cplx c);

#endif
