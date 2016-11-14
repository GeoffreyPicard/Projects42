/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:00:28 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/03 11:32:52 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	else
	{
		tab = (int *)malloc(sizeof(int) * (max - min));
		while (min <= max)
		{
			tab[i] = min;
			min++;
			i++;
		}
	}
	return (tab);
}
