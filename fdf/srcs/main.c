/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:27:20 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/21 17:03:25 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_main(int **tab, int h, int l)
{
	void	*mlx;
	void	*win;
	int		i;
	int		j;

	j = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "tinkiete");
	while (j < h)
	{
		i = 0;
		while (i < l)
		{
			mlx_pixel_put(mlx, win, ft_get_x(i, tab[j][i]), ft_get_y(j, tab[j][i]), 0x00FFFFFFF);
			i++;
		}
		j++;
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
