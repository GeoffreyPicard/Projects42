/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:46:58 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/29 17:55:15 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <stdio.h>
# include "mlx.h"
#include <math.h>
#define LEFT 500
#define RIGHT -500
#define ECART 10
#define ROT 0

typedef	struct	s_inttab
{
	int				*tab;
	struct s_inttab *next;
}				t_inttab;

typedef struct	s_t
{
	void 	*mlx;
	void	*win;
	void	*mlx_ptr;
	void	*img_ptr;
	void	*win_ptr;
	int		endian;
	int		bpp;
	int		sizeline;
	int		i;
	int		j;
	int		x;
	int		y;
	int		h;
	int		l;
	int		fd;
	int		dx;
	int		dy;
	int		sy;
	int		sx;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		err;
	int		e2;
}				t_t;



t_inttab    *ft_create_elem(int *tab);
void    ft_list_push_back(t_inttab *list, int *tab);
int     ft_count_len(char **tab);
int     *ft_tab_to_inttab(char **tab);
char    **ft_char_to_tab(char *line);
t_inttab	*ft_parse(int fd, char **line, int *l);
int     ft_list_size(t_inttab *list);
int     **ft_list_to_tab(t_inttab *list, int h, int l);
char    **ft_char_to_tab(char *line);
int     ft_get_x(int x, int y, int z);
int     ft_get_y(int x, int y, int z);
void    ft_put_line(t_t *t, int **tab, int x, int y);
void    ft_li(int y0, int x1, int y1, t_t *t);
void    ft_put_main(int **tab, int h, int l, t_t *t);


#endif
