/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:23:56 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/16 11:36:14 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		ft_mult_5(int i)
{
	if (i == 1)
		return (0);
	if (i / 5 * 5 == i)
		return (1);
	return (0);
}

static int		ft_check_back_line(char *str)
{
	int nb_line;
	int	tab[3];

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 1;
	nb_line = 1;
	while (str[++tab[0]])
	{
		if (ft_mult_5(nb_line) == 1 && str[tab[0]] != '\n')
			return (1);
		if (ft_mult_5(nb_line) == 1)
			tab[2]--;
		if (str[tab[0]] == '\n')
			nb_line++;
		tab[2]++;
		if (ft_mult_5(tab[2]) == 1 && str[tab[0]] != '\n')
			return (1);
		tab[1]++;
		if (ft_mult_5(nb_line) == 1 && str[tab[0] + 1] != '\0')
			tab[1] = 0;
	}
	if (tab[0] == 20 && tab[1] == 19)
		return (0);
	return (tab[1] != 21 ? 1 : 0);
}

static int		ft_check_char(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '#' &&
				str[i] != '.' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int				ft_check_main(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = ft_check_char(str);
	if (i == 1)
		return (1);
	i = ft_check_back_line(str);
	if (i == 1)
		return (1);
	j = ft_check_pattern(str);
	return (i + j);
}
