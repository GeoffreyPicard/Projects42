/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:13:07 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/02 11:13:08 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_color_2(int iteration_max, int i, t_t *t)
{
  int color;

  (void)iteration_max;
  (void)t;
  color = 0x00FFFFFF;
    color -= 0x000000 - (i * 42);
  return (color);
}

void ft_mandelbrot_help(t_t *t)
{
  t->c_r = (t->x / t->zoom + t->x1);
  t->c_i = (t->y / t->zoom + t->y1);
  t->z_r = 0;
  t->z_i = 0;
  t->i = 0;
  while (t->z_r * t->z_r + t->z_i * t->z_i < 4 && t->i < t->iteration_max)
  {
      t->tmp = t->z_r;
      t->z_r = t->z_r * t->z_r - t->z_i * t->z_i + t->c_r;
      t->z_i = 2 * t->z_i * t->tmp + t->c_i;
      t->i++;
  }
}

void ft_mandelbrot(t_t *t)
{
  t->image_x = ((t->x2 - t->x1) * t->zoom);
  t->image_y = ((t->y2 - t->y1) * t->zoom);
  t->x = 0;
  while (t->x < t->image_x)
  {
    t->y = 0;
    while (t->y < t->image_y)
    {
        ft_mandelbrot_help(t);
        if (t->i == t->iteration_max)
          ft_put_pixel_to_img(0x0033FF, t, t->x, t->y);
        else
          ft_put_pixel_to_img2(ft_color_2(t->iteration_max,
            t->i, t), t, t->x, t->y);
        t->y++;
      }
  t->x++;
  }
}
