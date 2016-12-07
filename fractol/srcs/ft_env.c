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
    else if (key_code == 91 && t->iteration_max < 300)
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
    else if (key_code == 124 && t->x1 < 0)
    {
        t->x1 += 1 / (float)t->zoom * 25;
        t->x2 += 1 / (float)t->zoom * 25;
    }
    else if (key_code == 123)
    {
      t->x1 -= 1 / (float)t->zoom * 25;
      t->x2 -= 1 / (float)t->zoom * 25;
    }
    else if (key_code == 125)
    {
      t->y1 += 1 / (float)t->zoom * 25;
      t->y2 += 1 / (float)t->zoom * 25;
    }
    else if (key_code == 126)
    {
      t->y1 -= 1 / (float)t->zoom * 25;
      t->y2 -= 1 / (float)t->zoom * 25;
    }
    else if (key_code == 49)
    {
      if (t->fractal == 1)
        ft_init_value_mandelrot(t);
      else if (t->fractal == 2)
        ft_init_value_julia(t);
      else if (t->fractal == 3)
        ft_init_value_fougere(t);
    }
    else if (key_code == 46)
      t->julia += 0.1;
    ft_put_img(t);
    return (0);
}

void ft_zoom(int x, int y, t_t *t)
{
  static int i;

  t->xtmp = x;
  t->ytmp = y;
  t->x1 = (x / t->zoom + t->x1) - (t->l / (t->zoom * 1.2) / 2);
  t->x1 += (t->l / (t->zoom * 1.2) / 2) - (x / (t->zoom * 1.2));
  t->x2 = t->x1 + t->tmp1 / 1.2;
  t->y1 = (y / t->zoom + t->y1) - (t->h / (t->zoom * 1.2) / 2);
  t->y1 += (t->h / (t->zoom * 1.2) / 2) - (y / (t->zoom * 1.2));
  t->y2 = t->y1 + t->tmp2 / 1.2;
  t->zoom *= 1.2;
  i++;
  if (i % 3 == 0)
    t->iteration_max++;
}

void ft_dezoom(t_t *t)
{
  static int j;
  t->x1 = (t->xtmp / t->zoom + t->x1) - (t->l / (t->zoom / 1.2) / 2);
  t->x1 += (t->l / (t->zoom / 1.2) / 2) - (t->xtmp / (t->zoom / 1.2));
  t->x2 = t->x1 + t->tmp1 * 1.2;
  t->y1 = (t->ytmp / t->zoom + t->y1) - (t->h / (t->zoom / 1.2) / 2);
  t->y1 += (t->h / (t->zoom / 1.2) / 2) - (t->ytmp / (t->zoom / 1.2));
  t->y2 = t->y1 + t->tmp2 * 1.2;
  t->zoom /= 1.2;
  j++;
  if (j % 3 == 0)
    t->iteration_max--;
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
  //  t->julia += t->l - (x / t->zoom);
//  }
  ft_put_img(t);
  return (0);
}
