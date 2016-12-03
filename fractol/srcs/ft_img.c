/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:52:33 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/02 11:52:55 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_put_pixel_to_img(unsigned long color, t_t *t, int l, int h)
{
    unsigned char r;
    unsigned char g;
    unsigned char b;

    r = ((color & 0xFF0000) >> 16);
    g = ((color & 0x00FF00) >> 8);
    b = (color & 0x0000FF);
    if (l >= 0 && l < t->l && h >= 0 && h < t->h)
    {
        t->img[h * t->sizeline + l * t->bpp / 8] = b + t->b_color;
        t->img[h * t->sizeline + l * t->bpp / 8 + 1] = g + t->g_color;
        t->img[h * t->sizeline + l * t->bpp / 8 + 2] = r + t->r_color;
    }
}

void    ft_put_pixel_to_img2(unsigned long color, t_t *t, int l, int h)
{
  unsigned char r;
  unsigned char g;
  unsigned char b;

  r = ((color & 0xFF0000) >> 16);
  g = ((color & 0x00FF00) >> 8);
  b = (color & 0x0000FF);
  if (l >= 0 && l < t->l && h >= 0 && h < t->h)
  {
      t->img[h * t->sizeline + l * t->bpp / 8] = b + t->b_color2;
      t->img[h * t->sizeline + l * t->bpp / 8 + 1] = g + t->g_color2;
      t->img[h * t->sizeline + l * t->bpp / 8 + 2] = r + t->r_color2;
  }
}

int     ft_put_img(t_t *t)
{
    t->img_ptr = mlx_new_image(t->mlx_ptr, t->l, t->h);
    t->img = mlx_get_data_addr(t->img_ptr, &(t->bpp),
            &(t->sizeline), &(t->endian));
    ft_mandelbrot(t);
    mlx_put_image_to_window(t->mlx_ptr, t->win_ptr,
            t->img_ptr, 0, 0);
    free(t->img);
    t->img = NULL;
    return (0);
}

void    ft_image(t_t *t)
{
    t->mlx_ptr = mlx_init();
    t->win_ptr = mlx_new_window(t->mlx_ptr, t->l, t->h, "fract'ol");
    mlx_expose_hook(t->win_ptr, ft_put_img, t);
    mlx_hook(t->win_ptr, 2, 1L<<0, ft_key, t);
    mlx_mouse_hook(t->win_ptr, ft_mouse, t);
    mlx_loop(t->mlx_ptr);
}
