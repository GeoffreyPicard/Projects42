/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:27:20 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/29 17:55:13 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_li_img(int y0, int x1, int y1, t_t *t)
{
	t->dx = abs(x1 - t->x0);
	t->sx = t->x0 < x1 ? 1 : -1;
	t->dy = abs(y1 - y0);
	t->sy = y0 < y1 ? 1 : -1;
	t->err = (t->dx > t->dy ? t->dx : -(t->dy)) / 2;
	while (1)
	{
//		ft_put_pixel_to_img(0xFF000000, img, sizeline, bpp, t->x0, y0);
		if (t->x0 == x1 && y0 == y1)
			break ;
		t->e2 = t->err;
		if (t->e2 > -(t->dx))
		{
			t->err -= t->dy;
			t->x0 += t->sx;
		}
		if (t->e2 < t->dy)
		{
			t->err += t->dx;
			y0 += t->sy;
		}
	}
}

void    ft_put_main_img(int **tab, int h, int l, t_t *t)
{
	t->y = 0;
	t->j = RIGHT;
	(void)tab;
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, 2300, 1300, "tinkiete");
	while (t->j < ((h * ECART + RIGHT)))
	{
		t->x = 0;
		t->i = LEFT;
		while (t->i < (l * ECART + LEFT))
		{
			mlx_pixel_put(t->mlx, t->win, ft_get_x(t->i, t->j,
						tab[t->y][t->x]), ft_get_y(t->i, t->j,
							tab[t->y][t->x]), 0x00FFFFFF);
			ft_put_line(t, tab, t->x, t->y);
			t->i += ECART;
			t->x++;
		}
		t->y++;
		t->j += ECART;
	}
	mlx_loop(t->mlx);
}

void	ft_put_pixel_to_img(unsigned long color, char *img, int sizeline, int bpp, int l, int h)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = ((color & 0xFF000000) >> 16);
	g = ((color & 0xFF0000) >> 8);
	b = (color & 0xFF00);
	img[h / sizeline + l / bpp * 8 ] = b;
	img[h / sizeline + l / bpp * 8 + 1] = g;
	img[h / sizeline + l / bpp * 8 + 2] = r;
}

void	ft_image(int **tab, t_t *t)
{
	char		*img;
	int			i;

	i = 0;
	(void)tab;
	t->mlx_ptr = mlx_init();
	t->win_ptr = mlx_new_window(t->mlx_ptr, 2300, 1300, "tinkiete2");
	t->img_ptr = mlx_new_image(t->mlx_ptr, 2300, 1300);
	img = mlx_get_data_addr(t->img_ptr, &(t->bpp), &(t->sizeline), &(t->endian));


//	ft_put_main_img(tab, h, l, t);


	mlx_put_image_to_window(t->mlx_ptr, t->win_ptr, t->img_ptr, 2300, 1300);
	mlx_loop(t->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_t			*t;
	char		*line;
	int			**tab;
	t_inttab	*list;

	t = malloc(sizeof(t_t));
	(void)ac;
	t->fd = open(av[1], O_RDONLY);
	list = ft_parse(t->fd, &line, &(t->l));
	t->h = ft_list_size(list);
	tab = ft_list_to_tab(list, t->h, t->l);
//	ft_put_main(tab, t->h, t->l, t);
	ft_image(tab, t);
	close(t->fd);
	return (0);
}
