/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:01:07 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/14 10:16:15 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_check_offy(char *str)
{
	int i;
	int offset;
	int first;

	first = 0;
	offset = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#' && !first)
		{
			offset = i / 4;
			first = 1;
		}
		if (str[i] == '#' && first)
			offset = ft_min(i / 4, offset);
		i++;
	}
	return (offset);
}

int			ft_check_offx(char *str)
{
	int i;
	int offset;
	int first;

	first = 0;
	offset = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#' && !first)
		{
			offset = i % 4;
			first = 1;
		}
		if (str[i] == '#' && first)
			offset = ft_min(i % 4, offset);
		i++;
	}
	return (offset);
}

t_coord		*ft_store(char *str, int number)
{
	int			i;
	int			x_off;
	int			y_off;
	t_coord		*piece_coords;

	i = 0;
	if (!(piece_coords = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	x_off = ft_check_offx(str);
	y_off = ft_check_offy(str);
	while (str[i])
	{
		while (str[i] != '#' && str[i])
			i++;
		if (str[i] == '#')
			piece_coords = ft_push_coords(i % 4 - x_off, i
					/ 4 - y_off, piece_coords, number);
		i++;
	}
	return (piece_coords);
}

void		ft_find_limits(t_coord **piece, int nb_p)
{
	t_coordxy	*first;

	first = (*piece)->coords;
	(*piece)->x_min = (*piece)->coords->x;
	(*piece)->x_max = (*piece)->coords->x;
	(*piece)->y_max = (*piece)->coords->y;
	(*piece)->in = 0;
	(*piece)->nb_pieces = nb_p;
	while ((*piece)->coords)
	{
		if ((*piece)->coords->y == 0)
		{
			if ((*piece)->x_min > (*piece)->coords->x)
				(*piece)->x_min = (*piece)->coords->x;
		}
		if ((*piece)->x_max < (*piece)->coords->x)
			(*piece)->x_max = (*piece)->coords->x;
		if ((*piece)->y_max < (*piece)->coords->y)
			(*piece)->y_max = (*piece)->coords->y;
		(*piece)->coords = (*piece)->coords->next;
	}
	(*piece)->coords = first;
}

t_coord		**ft_store_pieces(char **tab, int size, int nb_p)
{
	int			i;
	t_coord		**piece_coords;

	i = 0;
	if (!(piece_coords = (t_coord **)malloc(sizeof(t_coord *) * size + 1)))
		return (NULL);
	while (i < size)
	{
		piece_coords[i] = ft_store(tab[i], i);
		ft_find_limits(&piece_coords[i], nb_p);
		i++;
	}
	piece_coords[size] = 0;
	return (piece_coords);
}
