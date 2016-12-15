/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 09:32:41 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/14 09:32:42 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int ft_key(int key_code, t_t *t)
{
  if (key_code == 53)
    exit(1);
  else if (key_code == 49)
    ft_init(t);
  else if (key_code == 13)
  {
    if (t->map[(int)(t->posX + t->dirX * t->walk)][(int)(t->posY)] == 0)
      t->posX += t->dirX * t->walk;
    if (t->map[(int)(t->posX)][(int)(t->posY + t->dirY * t->walk)] == 0)
      t->posY += t->dirY * t->walk;
  }
  else if (key_code == 1)
  {
    if (t->map[(int)(t->posX - t->dirX * t->walk)][(int)(t->posY)] == 0)
      t->posX -= t->dirX * t->walk;
    if (t->map[(int)(t->posX)][(int)(t->posY - t->dirY * t->walk)] == 0)
      t->posY -= t->dirY * t->walk;
  }
  else if (key_code == 0)
  {
    double oldDirX = t->dirX;
    t->dirX = t->dirX * cos(t->rot) - t->dirY * sin(t->rot);
    t->dirY = oldDirX * sin(t->rot) + t->dirY * cos(t->rot);
    double oldPlaneX = t->planeX;
    t->planeX = t->planeX * cos(t->rot) - t->planeY * sin(t->rot);
    t->planeY = oldPlaneX * sin(t->rot) + t->planeY * cos(t->rot);
  }
  else if (key_code == 2)
  {
    double oldDirX = t->dirX;
    t->dirX = t->dirX * cos(-t->rot) - t->dirY * sin(-t->rot);
    t->dirY = oldDirX * sin(-t->rot) + t->dirY * cos(-t->rot);
    double oldPlaneX = t->planeX;
    t->planeX = t->planeX * cos(-t->rot) - t->planeY * sin(-t->rot);
    t->planeY = oldPlaneX * sin(-t->rot) + t->planeY * cos(-t->rot);
  }
  ft_put_img(t);
  return (0);
}
