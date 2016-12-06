/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:42:51 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/14 10:16:21 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		ft_lstaddxy(t_coordxy **alst, t_coordxy *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_coord		*ft_push_coords(int x, int y, t_coord *piece_coords, int number)
{
	t_coordxy	*coordxy;

	if (!(coordxy = (t_coordxy *)malloc(sizeof(t_coordxy))))
		return (NULL);
	coordxy->x = x;
	coordxy->y = y;
	coordxy->number = number;
	if (piece_coords->coords)
		ft_lstaddxy((&(piece_coords->coords)), coordxy);
	else
	{
		coordxy->next = NULL;
		piece_coords->coords = coordxy;
	}
	return (piece_coords);
}

int			ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int			ft_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}
