/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:54:21 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/06 13:30:35 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define RED   			"\x1B[31m"
# define GRN   			"\x1B[32m"
# define YEL   			"\x1B[33m"
# define BLU   			"\x1B[34m"
# define MAG   			"\x1B[35m"
# define CYN   			"\x1B[1;96m"
# define RESET 			"\x1B[0m"

# define WINX 		450
# define WINY 		450
# define ITER_MAX 	80

# define KEY_LEFT	123
# define KEY_DOWN	125
# define KEY_RIGHT	124
# define KEY_UP		126

# define WHEEL_UP	4
# define WHEEL_DOWN 3

typedef struct	s_pnt
{
	double x;
	double y;
}				t_pnt;

typedef struct	s_cplx
{
	double	re;
	double	im;
}				t_cplx;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*image;
	t_pnt	p1;
	t_pnt	p2;
	double	new_x;
	double	new_y;
	double	move_x;
	double	move_y;
	int		i;
	double	x;
	double	y;
}				t_env;

t_cplx			cplx_new(double re, double im);
t_cplx			cplx_add(t_cplx z1, t_cplx z2);
t_cplx			cplx_sub(t_cplx z1, t_cplx z2);
t_cplx			cplx_mul(t_cplx z1, t_cplx z2);
double			cplx_mod(t_cplx p1);

unsigned int	ft_getcolor(double i);
int				is_infinite(t_cplx z, t_cplx c);
t_cplx			ft_cplxpow(t_cplx z, int pow);

void			ft_mendelbrot(t_env *e, t_pnt min, t_pnt max);
int				mouse_hook_m(int button, int x, int y, t_env *e);
int				key_hook_m(int keycode, t_env *e);

void			ft_julia(t_env *e, t_pnt min, t_pnt max, t_cplx c);
int				mouse_hook_j(int button, int x, int y, t_env *e);
int				mouse_julia(int x, int y, t_env *e);
int				key_hook_j(int keycode, t_env *e);

void			ft_custom1(t_env *e, t_pnt min, t_pnt max);
int				key_hook_c1(int keycode, t_env *e);
int				mouse_hook_c1(int button, int x, int y, t_env *e);

void			ft_custom2(t_env *e, t_pnt min, t_pnt max);
int				key_hook_c2(int keycode, t_env *e);
int				mouse_hook_c2(int button, int x, int y, t_env *e);

int				mouse_hook_c3(int button, int x, int y, t_env *e);
int				key_hook_c3(int keycode, t_env *e);
void			ft_custom3(t_env *e, t_pnt min, t_pnt max);

int				mouse_hook_b(int button, int x, int y, t_env *e);
int				key_hook_b(int keycode, t_env *e);
void			ft_teardrop(t_env *e, t_pnt min, t_pnt max);

void			input_error(void);
int				window_error(void);

void			ft_zoom(int x, int y, t_env *e);
void			ft_dezoom(int x, int y, t_env *e);

void			ft_movexr(t_env *e);
void			ft_movexl(t_env *e);
void			ft_moveyu(t_env *e);
void			ft_moveyd(t_env *e);

#endif
