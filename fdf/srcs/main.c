/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:27:20 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/24 18:56:18 by geoffrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line(int xa, int ya, int xb, int yb, void *mlx, void* win)
{
	int i;
	int j;
	int a;
	int b;

	if (xb - xa > 0)
		a = (yb - ya) / (xb - xa);
	else
		a = 0;
	b = ya - a * xa;
	i = xa;
	while (i <= xb)
	{
		j = (a * i + b);
		mlx_pixel_put(mlx, win, i, j, 0x00FFFFFF);
		i++;
	}
}

void	ft_put_main(int **tab, int h, int l)
{
	void	*mlx;
	void	*win;
	int		i;
	int		j;

	j = 0;
	(void)tab;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "tinkiete");
	ft_line(0, 0, 10, 10, mlx, win);
	while (j < h * 10)
	{
		i = 0;
		while (i < l * 10)
		{
			mlx_pixel_put(mlx, win, i, j, 0x00FFFFFFF);
			i += 10;
		}
		j += 10;
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
	close(fd);
	return (0);
}
