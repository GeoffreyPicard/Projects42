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

typedef struct  s_inttab
{
    int             *tab;
    struct s_inttab *next;
}               t_inttab;

typedef struct  s_t
{
  int **map;
  int h;
  int l;
  int fd;
  int L_screen;
  int H_screen;
  double posx;
  double posy;
  double fov;
}               t_t;

void ft_free_tab(int **tab);
int     ft_lenfd(int fd, t_t *t);
int ft_open_len(char *str, t_t *t);
char    *ft_string_to_fd(char *dst, int fd);
void ft_char_to_int(char *str, int fd, t_t *t);
int ft_main_parse(t_t *t, char **av);

#endif
