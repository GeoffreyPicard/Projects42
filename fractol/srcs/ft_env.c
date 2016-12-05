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
        ft_init_value(t, "julia");
    ft_put_img(t);
    return (0);
}

int   ft_mouse(int mouse_code, int x, int y, t_t *t)
{
  float tmp;
  float tmp2;
  static int xtmp;
  static int ytmp;

  tmp = t->x2 - t->x1;
  tmp2 = t->y2 - t->y1;
  if (mouse_code == 1 || mouse_code == 4)
  {
      xtmp = x;
      ytmp = y;
      t->x1 = (x / t->zoom + t->x1) - (t->l / (t->zoom * 1.2) / 2);
      t->x1 += (t->l / (t->zoom * 1.2) / 2) - (x / (t->zoom * 1.2));
      t->x2 = t->x1 + tmp;
      t->y1 = (y / t->zoom + t->y1) - (t->h / (t->zoom * 1.2) / 2);
      t->y1 += (t->h / (t->zoom * 1.2) / 2) - (y / (t->zoom * 1.2));
      t->y2 = t->y1 + tmp2;
      t->zoom *= 1.2;
  }
  else if ((mouse_code == 2 || mouse_code == 5) && t->zoom > 300)
  {
    t->x1 = (xtmp / t->zoom + t->x1) - (t->l / (t->zoom / 1.2) / 2);
    t->x1 += (t->l / (t->zoom / 1.2) / 2) - (xtmp / (t->zoom / 1.2));
    t->x2 = t->x1 + tmp;
    t->y1 = (ytmp / t->zoom + t->y1) - (t->h / (t->zoom / 1.2) / 2);
    t->y1 += (t->h / (t->zoom / 1.2) / 2) - (ytmp / (t->zoom / 1.2));
    t->y2 = t->y1 + tmp2;
    t->zoom /= 1.2;
  }
  ft_put_img(t);
  return (0);
}
