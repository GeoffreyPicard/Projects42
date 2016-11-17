/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:41:09 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/07 09:48:01 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int n)
{
	unsigned int	i;
	unsigned int	nb;

	i = 0;
	nb = 0;
	if (n < 0)
		nb = -n;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
