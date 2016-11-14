/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:14:05 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/03 11:15:36 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int res;

	res = 1;
	if (nb == 0)
		return (1);
	if (nb < 1 || nb > 12)
		return (0);
	while (nb >= 1)
	{
		res = res * nb;
		nb--;
	}
	return (res);
}
