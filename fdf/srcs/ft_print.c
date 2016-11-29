/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:17:00 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/29 17:55:17 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_get_x(int x, int y, int z)
{
	int	res;
	int	i;

	i = 0;
	(void)z;
	res = x - 1 * y;
	while (i < ROT)
	{
		res = res - 1 * y;
		i++;
	}
	return (res);
}

int		ft_get_y(int x, int y, int z)
{
	int	res;
	int	i;

	i = 0;
	z = -z;
	res = z + x / 2 + y / 2;
	while (i < ROT)
	{
		res = z + x / 2 + res / 2;
		i++;
	}
	return (res);
}

void	ft_put_line(t_t *t, int **tab, int x, int y)
{
	if (t->i - ECART >= (LEFT))
	{
		t->x0 = ft_get_x(t->i - ECART, t->j, tab[y][x - 1]);
		ft_li(ft_get_y(t->i - ECART, t->j, tab[y][x - 1]),
				ft_get_x(t->i, t->j, tab[y][x]),
				ft_get_y(t->i, t->j, tab[y][x]), t);
	}
	if (t->j - ECART >= RIGHT)
	{
		t->x0 = ft_get_x(t->i, t->j - ECART, tab[y - 1][x]);
		ft_li(ft_get_y(t->i, t->j - ECART, tab[y - 1][x]),
				ft_get_x(t->i, t->j, tab[y][x]),
				ft_get_y(t->i, t->j, tab[y][x]), t);
	}
}

void	ft_li(int y0, int x1, int y1, t_t *t)
{
	t->dx = abs(x1 - t->x0);
	t->sx = t->x0 < x1 ? 1 : -1;
	t->dy = abs(y1 - y0);
	t->sy = y0 < y1 ? 1 : -1;
	t->err = (t->dx > t->dy ? t->dx : -(t->dy)) / 2;
	while (1)
	{
		mlx_pixel_put(t->mlx, t->win, t->x0, y0, 0x00FFFFFF);
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

void	ft_put_main(int **tab, int h, int l, t_t *t)
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
