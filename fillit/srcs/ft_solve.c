/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:35:38 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/14 10:16:01 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_check_htg(t_coord **piece, char **res,
		int i, int size)
{
	t_coordxy	*first;
	int			x;
	int			y;
	int			x_ind;
	int			y_ind;

	x_ind = i % size;
	y_ind = i / size;
	first = (*piece)->coords;
	if (x_ind + (piece[0])->x_max < size && y_ind + (piece[0])->y_max < size)
		while ((*piece)->coords)
		{
			x = (*piece)->coords->x + x_ind;
			y = (*piece)->coords->y + y_ind;
			if (res[y][x] >= 'A')
			{
				(*piece)->coords = first;
				return (1);
			}
			(*piece)->coords = (*piece)->coords->next;
		}
	else
		return (1);
	(*piece)->coords = first;
	return (0);
}

int			ft_check_htg_all(t_coord **pieces, char **res,
		int i, int size)
{
	int x_index;
	int y_index;
	int j;

	x_index = i % size;
	y_index = i / size;
	j = 0;
	while (j < (pieces[0])->nb_pieces)
	{
		if (pieces[j]->in == 0)
			if (!ft_check_htg(&pieces[j], res, i, size))
				return (1);
		j++;
	}
	return (0);
}

int			ft_all_pieces(t_coord **piece)
{
	int i;

	i = 0;
	while (piece[i])
	{
		if ((piece[i])->in == 0)
			return (0);
		i++;
	}
	return (1);
}

int			ft_backtrack(t_coord **pieces, int size, char **res, int i_piece)
{
	int x_index;
	int y_index;
	int i;

	i = 0;
	if (ft_all_pieces(pieces))
		return (1);
	x_index = 0;
	y_index = 0;
	while (i < size * size)
	{
		x_index = i % size;
		y_index = i / size;
		if (ft_check_htg(&pieces[i_piece], res, i,
					size) != 1 && (pieces[i_piece])->in == 0)
		{
			ft_write_piece(&pieces[i_piece], res, x_index, y_index);
			if (ft_backtrack(pieces, size, res, i_piece + 1) == 1)
				return (1);
			ft_reset_piece(&pieces[i_piece], res, x_index, y_index);
		}
		i++;
	}
	return (0);
}

void		ft_solve(t_coord **pieces, int nb_pieces, int taille)
{
	char	**tab;
	int		i;

	i = 0;
	while (nb_pieces * 4 > taille * taille)
		taille++;
	tab = (char **)malloc(sizeof(char *) * taille + 1);
	while (i < taille)
	{
		tab[i] = ft_strnew(taille - 1);
		tab[i] = ft_memset(tab[i], '.', taille);
		i++;
	}
	if (ft_backtrack(pieces, taille, tab, 0) == 1)
	{
		ft_print_tab(tab);
		return ;
	}
	else
		ft_solve(pieces, nb_pieces, taille + 1);
	ft_free_tab(tab);
}
