/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 09:26:04 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/02 17:02:30 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>

# define IT_MAX

typedef struct	s_t
{
	void		*mlx;
	void		*win;
	void		*mlx_ptr;
	void		*img_ptr;
	void		*win_ptr;
	int			endian;
	int			bpp;
	int			sizeline;
	char		*img;
  int     haut;
  int     larg;
  int     l;
  int     h;
  int     iteration_max;
  int     color1;
  int     color2;
  int     b_color;
  int     g_color;
  int     r_color;
  int     b_color2;
  int     g_color2;
  int     r_color2;
	int			k;
	float			xpos;
	float			ypos;
	int			fractal;
	int			xtmp;
	int			ytmp;
	float		tmp1;
	float		tmp2;

  double x1;
  double x2;
  double y1;
  double y2;
  double zoom;
  double c_r;
  double c_i;
  int x;
  int y;
  double tmp;
  int i;
  double z_r;
  double z_i;
  int image_x;
  int image_y;
}				       t_t;

void	ft_put_pixel_to_img(unsigned long color, t_t *t, int l, int h);
void	ft_put_pixel_to_img2(unsigned long color, t_t *t, int l, int h);
int		ft_put_img(t_t *t);
void	ft_image(t_t *t);
void ft_mandelbrot(t_t *t);
void ft_julia(t_t *t);
int     ft_key(int key_code, t_t *t);
int   ft_mouse(int mouse_code, int x, int y, t_t *t);
int ft_init_value(t_t *t, char *str);
void ft_init_value_mandelrot(t_t *t);
void ft_init_value_julia(t_t *t);
void ft_init_value_buddhabrot(t_t *t);

#endif
