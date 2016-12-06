/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:49:51 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/14 10:16:08 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		ft_reset_piece(t_coord **piece,
		char **res, int x_index, int y_index)
{
	t_coordxy	*first;
	int			x;
	int			y;

	first = (*piece)->coords;
	while ((*piece)->coords)
	{
		x = (*piece)->coords->x + x_index;
		y = (*piece)->coords->y + y_index;
		res[y][x] = '.';
		(*piece)->coords = (*piece)->coords->next;
	}
	(*piece)->in = 0;
	(*piece)->coords = first;
}

void		ft_write_piece(t_coord **piece,
		char **res, int x_index, int y_index)
{
	t_coordxy	*first;
	int			x;
	int			y;

	first = (*piece)->coords;
	while ((*piece)->coords)
	{
		x = (*piece)->coords->x + x_index;
		y = (*piece)->coords->y + y_index;
		res[y][x] = (*piece)->coords->number + 'A';
		(*piece)->coords = (*piece)->coords->next;
	}
	(*piece)->in = 1;
	(*piece)->coords = first;
}

void		ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
}
