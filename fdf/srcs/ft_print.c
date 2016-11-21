/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:17:00 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/21 17:03:22 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define EYE_Z 20000
#define EYE_X 100000
#define EYE_Y 100000

int		ft_get_x(int x, int z)
{
	int res;

	res = (EYE_Z * (x - EYE_X)) / (EYE_Z + z) + EYE_X;
	return (res);
}

int		ft_get_y(int y, int z)
{
	int res;

	res = (EYE_Z * (y - EYE_Y)) / (EYE_Z + z) + EYE_Y;
	return (res);
}

void    ft_print_inttab(int *tab, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		printf("%d ", tab[i]);
		i++;
	}
}

void    ft_print_tab_int(int **tab, int h, int l)
{
	int i;

	i = 0;
	while (i < h)
	{
		ft_print_inttab(tab[i], l);
		printf("\n");
		i++;
	}
}

void    ft_print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void    ft_print_list(t_inttab *list, int len)
{
	while (list)
	{
		ft_print_inttab((list->tab), len);
		printf("\n");
		list = list->next;
	}
}
