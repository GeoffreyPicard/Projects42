/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 12:53:41 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/11 12:54:09 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
#define WOLF3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "mlx.h"

typedef struct  s_inttab
{
    int             *tab;
    struct s_inttab *next;
}               t_inttab;

typedef struct  s_t
{
  char *img;
  int sizeline;
  void *mlx_ptr;
  void *win_ptr;
  void *img_ptr;
  int endian;
  int bpp;
  int **map;
  int h;
  int l;
  int fd;
  int dx;
  int x0;
  int sx;
  int dy;
  int sy;
  int err;
  int e2;
  int L_screen;
  int H_screen;
  double posX;
  double posY;
  int    pos_now_x;
  int    pos_now_y;
  double raydirX;
  double raydirY;
  double cameraX;

}               t_t;

void ft_free_tab(int **tab);
int     ft_lenfd(int fd, t_t *t);
int ft_open_len(char *str, t_t *t);
char    *ft_string_to_fd(char *dst, int fd);
void ft_char_to_int(char *str, int fd, t_t *t);
int ft_main_parse(t_t *t, char **av);
void	ft_image(t_t *t);
void	ft_put_pixel_to_img(unsigned long color, t_t *t, int l, int h);
void	ft_li_img(int y0, int x1, int y1, t_t *t);

#endif
