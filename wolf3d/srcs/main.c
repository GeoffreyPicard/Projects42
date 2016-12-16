/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 12:53:06 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/11 12:53:31 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void ft_print_tab(int *tab, int l)
{
	int i = 0;
	while (i < l)
	{
		printf("%d ", tab[i]);
		i++;
	}
}

void ft_print(int **tab, int h, int l)
{
	int i = 0;
	while (i < h)
	{
		ft_print_tab(tab[i], l);
		printf("\n");
		i++;
	}
}

void ft_free_tab(int **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void ft_init(t_t *t)
{
	t->L_screen = 2300;
	t->H_screen = 1000;
	t->h = 0;
	t->l = 0;
	t->posX = 2;
	t->posY = 2;
	t->dirX = -1;
	t->dirY = 0;
	t->planeY = 0.66;
	t->planeX = 0;
	t->walk = 0.2;
	t->rot = 0.2;
}

void ft_map_correct(t_t *t)
{
	int j;

	j = -1;
	while (++j < t->h)
		t->map[j][0] = 1;
	j = -1;
	while (++j < t->l)
		t->map[0][j] = 1;
	j = -1;
	while (++j < t->h)
		t->map[j][t->l - 1] = 1;
	j = -1;
	while (++j < t->l)
		t->map[t->h - 1][j] = 1;
	t->map[(int)t->posY][(int)t->posX] = 0;
}

int		main(int ac, char **av)
{
	t_t *t;

	if (ac == 2)
	{
		if (!(t = malloc(sizeof(t_t))))
			return (1);
		ft_init(t);
		if (ft_main_parse(t, av) == 1)
			return (1);
		ft_map_correct(t);
		ft_image(t);
//		ft_print(t->map, t->h, t->l);
//		ft_free_tab(t->map);
//		free(t);
	//	free(str);
	}
	return (0);
}
