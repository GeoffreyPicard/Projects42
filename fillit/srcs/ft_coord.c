/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:28:38 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/14 10:15:31 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*ft_str_without_back_slash(char *str)
{
	int		i;
	int		j;
	char	*dst;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != '\n')
			j++;
	}
	if (!(dst = (char*)malloc(sizeof(char) * j + 1)))
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != '\n')
		{
			dst[j] = str[i];
			j++;
		}
	}
	dst[j] = '\0';
	return (dst);
}

int		ft_nb_piece(char *str)
{
	return (ft_strlen(str) / 16 == 1 ? 1 : ft_strlen(str) / 16);
}

char	**ft_str_to_tab(char *str)
{
	char	**tab;
	int		i;
	int		k;
	int		j;

	i = -1;
	k = 0;
	j = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * ft_nb_piece(str) + 1)))
		return (NULL);
	while (i++ < ft_nb_piece(str) - 1)
	{
		k += 16;
		tab[i] = ft_strsub(str, j, k - j);
		j += 16;
	}
	tab[i] = 0;
	return (tab);
}
