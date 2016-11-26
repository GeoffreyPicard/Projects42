/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:27:20 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/26 17:07:11 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define ECART 10


void	ft_horizontal(int xa, int xb, int ya, void *mlx, void *win)
{
	int i;

	i = xb;
	while (i >= xa)
	{
		mlx_pixel_put(mlx, win, i, ya, 0xFF0000);
		i--;
	}
}

void	ft_vertical(int xa, int ya, int yb, void *mlx, void *win)
{
	int	i;

	i = yb;
	while (i >= ya)
	{
		mlx_pixel_put(mlx, win, xa, i, 0xFF0000);
		i--;
	}
}

void	ft_diago(int xa, int ya, int xb, int yb, void *mlx, void* win)
{
	int x;
	int y;
	int dx;
	int dy;
	int div;

	x = xa;
	y = ya;
	dx = xb - xa;
	dy = yb - ya;
	mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
	div = dx / 2;
	x++;
	while (x <= xb)
	{
		div += dy;
		if (div >= dx)
		{
			div -= dx;
			y++;
		}
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		x++;
	}
}

void	ft_line_main(int xa, int ya, int xb, int yb, void *mlx, void *win)
{
	if (xa == xb)
		ft_vertical(xa, ya, yb, mlx, win);
	else if (ya == yb)
		ft_horizontal(xa, xb, ya, mlx, win);
	else
	{
		if (ya > yb)
		{
			ft_swap(&ya, &yb);
			ft_swap(&xa, &xb);
		}
		ft_diago(xa, ya, xb, yb, mlx, win);
	}
}

void	ft_put_main(int **tab, int h, int l)
{
	void	*mlx;
	void	*win;
	int		i;
	int		x;
	int		y;
	int		j;
	int		tmp;
	int		tmp2;

	y = 0;
	tmp = tab[0][0];
	tmp2 = tab[0][0];
	j = ((h * 2 * ECART) / 4) + h / 2;
	(void)tab;
	mlx = mlx_init();
	win = mlx_new_window(mlx, l * 2 * ECART, h * 2 * ECART, "tinkiete");
//	ft_line_main(10, 10, 100, 100, mlx, win);
	ft_line_main(100, 100, 20, 20, mlx, win);
	while (j < h * ECART + ((h * 2 * ECART) / 4) + h / 2)
	{
		x = 0;
		i = ((l * 2 * ECART) / 4) + l / 2;
		while (i < l * ECART + ((l * 2 * ECART) / 4) + l / 2)
		{
//			mlx_pixel_put(mlx, win, i, j, 0x00FFFFFF);
//			ft_line_main(10, 10, i, j, mlx, win);
			tmp = ft_get_x(i, tab[y][x]);
			tmp2 = ft_get_y(j, tab[y][x]);
			i += ECART;
			x++;
		}
		y++;
		j += ECART;
	}
	mlx_loop(mlx);
}

int		main(int ac, char **av)
{
	char *line;
	int	**tab;
	int	fd;
	int h;
	int l;
	t_inttab *list;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	list = ft_parse(fd, &line, &l);
	h = ft_list_size(list);
	tab = ft_list_to_tab(list, h, l);
	ft_put_main(tab, h, l);
	//	printf("%d\n", ft_get_x(0, 4));
	//	printf("%d\n", ft_get_y(0, 4));
	close(fd);
	return (0);
}
