/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:26:48 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/13 14:26:50 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void ft_direction(t_t *t)
{
  if (t->raydirX < 0)
  {
	   t->stepX = -1;
 	   t->sidedistX = (t->rayposX - t->pos_now_x) * t->ecart_sideX;
  }
  else
  {
	   t->stepX = 1;
 	   t->sidedistX = (t->pos_now_x + 1.0 - t->rayposX) * t->ecart_sideX;
   }
  if (t->raydirY < 0)
  {
	    t->stepY = -1;
	   t->sidedistY = (t->rayposY - t->pos_now_y) * t->ecart_sideY;
  }
  else
  {
	   t->stepY = 1;
	  t->sidedistY = (t->pos_now_y + 1.0 - t->rayposY) * t->ecart_sideY;
  }
}

void ft_hit_wall(t_t *t)
{
  while (t->mur == 0)
  {
	if (t->sidedistX < t->sidedistY)
  {
		t->sidedistX += t->ecart_sideX;
		t->pos_now_x += t->stepX;
		t->orientation = 0;
	}
  else
  {
		t->sidedistY += t->ecart_sideY;
		t->pos_now_y += t->stepY;
		t->orientation = 1;
	}
	if (t->map[t->pos_now_x][t->pos_now_y] > 0)
		t->mur = 1;
  }
}

void ft_draw_and_calcul_h(t_t *t, int x)
{
  int h_max;
  int h_min;
  int y;
  int color;

  t->h_line = (int)(t->H_screen / t->di_cor);
  h_min = (-t->h_line / 2 + t->H_screen / 2);
  h_max = (t->h_line / 2 + t->H_screen / 2);
  if (h_min < 0)
	 h_min = 0;
  if (h_max >= t->H_screen)
	  h_max = t->H_screen - 1;
  y = 0;
  while (y <= h_min)
  {
    ft_put_pixel_to_img(0x00CCFF, t, x, y);
    y++;
  }
  while (y < h_max)
  {
    color = 0x333300;
    if (t->orientation == 1)
      color = 0x009933;
    ft_put_pixel_to_img(color, t, x, y);
    y++;
  }
  while (y <= t->H_screen)
  {
    ft_put_pixel_to_img(778899, t, x, y);
    y++;
  }
}

void ft_ray_casting(t_t *t)
{
  int x;

  x = 0;
  while (x < t->L_screen)
  {
    t->cameraX = (2 * x / (double)(t->L_screen)) - 1;
    t->rayposX = t->posX;
    t->rayposY = t->posY;
    t->raydirX = t->dirX + t->planeX * t->cameraX;
    t->raydirY = t->dirY + t->planeY * t->cameraX;

    t->pos_now_x = (int)t->rayposX;
    t->pos_now_y = (int)t->rayposY;
    t->ecart_sideX = sqrt(1 + (t->raydirY * t->raydirY) / (t->raydirX * t->raydirX));
    t->ecart_sideY = sqrt(1 + (t->raydirX * t->raydirX) / (t->raydirY * t->raydirY));
    t->mur = 0;
    ft_direction(t);
    ft_hit_wall(t);
    if (t->orientation == 0)
	     t->di_cor = ((t->pos_now_x - t->rayposX + (1 - t->stepX) / 2) / t->raydirX);
    else
	     t->di_cor = ((t->pos_now_y - t->rayposY + (1 - t->stepY) / 2) / t->raydirY);
    ft_draw_and_calcul_h(t, x);
    x++;
  }
}
