/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:57:04 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/02 16:57:06 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     ft_key(int key_code, t_t *t)
{
    if (key_code == 53)
        exit(1);
    else if (key_code == 91 && t->iteration_max < 60)
        t->iteration_max++;
    else if (key_code == 87 && t->iteration_max > 1)
        t->iteration_max--;
    else if (key_code == 12)
        t->b_color += 20;
    else if (key_code == 0)
        t->b_color -= 20;
    else if (key_code == 13)
        t->g_color += 20;
    else if (key_code == 1)
        t->g_color -= 20;
    else if (key_code == 14)
        t->r_color += 20;
    else if (key_code == 2)
        t->r_color -= 20;
    else if (key_code == 15)
        t->b_color2 += 20;
    else if (key_code == 3)
        t->b_color2 -= 20;
    else if (key_code == 17)
        t->g_color2 += 20;
    else if (key_code == 5)
        t->g_color2 -= 20;
    else if (key_code == 16)
        t->r_color2 += 20;
    else if (key_code == 4)
        t->r_color2 -= 20;
    else if (key_code == 49)
    {
      if (t->fractal == 1)
        ft_init_value_mandelrot(t);
      else if (t->fractal == 2)
        ft_init_value_julia(t);
    }
    ft_put_img(t);
    return (0);
}

void ft_zoom(int x, int y, t_t *t)
{
  t->xtmp = x;
  t->ytmp = y;
  t->x1 = (x / t->zoom + t->x1) - (t->l / (t->zoom * 1.2) / 2);
  t->x1 += (t->l / (t->zoom * 1.2) / 2) - (x / (t->zoom * 1.2));
  t->x2 = t->x1 + t->tmp1;
  t->y1 = (y / t->zoom + t->y1) - (t->h / (t->zoom * 1.2) / 2);
  t->y1 += (t->h / (t->zoom * 1.2) / 2) - (y / (t->zoom * 1.2));
  t->y2 = t->y1 + t->tmp2;
  t->zoom *= 1.2;
}

void ft_dezoom(t_t *t)
{
  t->x1 = (t->xtmp / t->zoom + t->x1) - (t->l / (t->zoom / 1.2) / 2);
  t->x1 += (t->l / (t->zoom / 1.2) / 2) - (t->xtmp / (t->zoom / 1.2));
  t->x2 = t->x1 + t->tmp1;
  t->y1 = (t->ytmp / t->zoom + t->y1) - (t->h / (t->zoom / 1.2) / 2);
  t->y1 += (t->h / (t->zoom / 1.2) / 2) - (t->ytmp / (t->zoom / 1.2));
  t->y2 = t->y1 + t->tmp2;
  t->zoom /= 1.2;
}

int   ft_mouse(int mouse_code, int x, int y, t_t *t)
{
  t->tmp1 = t->x2 - t->x1;
  t->tmp2 = t->y2 - t->y1;
  if (mouse_code == 1 || mouse_code == 4)
      ft_zoom(x, y, t);
  if ((mouse_code == 2 || mouse_code == 5) && t->zoom > 300)
    ft_dezoom(t);
//  if (t->fractal == 2)
//  {
//    t->c_r += (x / t->zoom + t->x1);
//  }
  ft_put_img(t);
  return (0);
}
