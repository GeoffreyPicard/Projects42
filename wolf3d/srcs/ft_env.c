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
  if (key_code == 13)
    t->up = 1;
  if (key_code == 1)
    t->down = 1;
  if (key_code == 0)
    t->left = 1;
  if (key_code == 2)
    t->right = 1;
  if (key_code == 126)
    t->walk = 0.15;
  if (key_code == 125)
    t->walk = 0.025;
  return (0);
}

int ft_key_stop(int key_code, t_t *t)
{
  if (key_code == 13)
    t->up = 0;
  if (key_code == 1)
    t->down = 0;
  if (key_code == 0)
    t->left = 0;
  if (key_code == 2)
    t->right = 0;
  if (key_code == 126)
    t->walk = 0.05;
  if (key_code == 125)
    t->walk = 0.05;
  return (0);
}

void ft_move_up(t_t *t)
{
  if (t->map[(int)(t->posX + t->dirX * t->walk)][(int)(t->posY)] == 0)
    t->posX += t->dirX * t->walk;
  if (t->map[(int)(t->posX)][(int)(t->posY + t->dirY * t->walk)] == 0)
    t->posY += t->dirY * t->walk;
}

void ft_move_down(t_t *t)
{
  if (t->map[(int)(t->posX - t->dirX * t->walk)][(int)(t->posY)] == 0)
    t->posX -= t->dirX * t->walk;
  if (t->map[(int)(t->posX)][(int)(t->posY - t->dirY * t->walk)] == 0)
    t->posY -= t->dirY * t->walk;
}

void ft_move_left(t_t *t)
{
  double oldDirX = t->dirX;
  t->dirX = t->dirX * cos(t->rot) - t->dirY * sin(t->rot);
  t->dirY = oldDirX * sin(t->rot) + t->dirY * cos(t->rot);
  double oldPlaneX = t->planeX;
  t->planeX = t->planeX * cos(t->rot) - t->planeY * sin(t->rot);
  t->planeY = oldPlaneX * sin(t->rot) + t->planeY * cos(t->rot);
}

void ft_move_right(t_t *t)
{
  double oldDirX = t->dirX;
  t->dirX = t->dirX * cos(-t->rot) - t->dirY * sin(-t->rot);
  t->dirY = oldDirX * sin(-t->rot) + t->dirY * cos(-t->rot);
  double oldPlaneX = t->planeX;
  t->planeX = t->planeX * cos(-t->rot) - t->planeY * sin(-t->rot);
  t->planeY = oldPlaneX * sin(-t->rot) + t->planeY * cos(-t->rot);
}
