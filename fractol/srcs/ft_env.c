/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:57:04 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/08 11:31:17 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom(int x, int y, t_t *t)
{
	static int i;

	t->xtmp = x;
	t->ytmp = y;
	t->x1 = (x / t->zoom + t->x1) - (t->l / (t->zoom * 1.2) / 2);
	t->x1 += (t->l / (t->zoom * 1.2) / 2) - (x / (t->zoom * 1.2));
	t->x2 = t->x1 + t->tmp1 / 1.2;
	t->y1 = (y / t->zoom + t->y1) - (t->h / (t->zoom * 1.2) / 2);
	t->y1 += (t->h / (t->zoom * 1.2) / 2) - (y / (t->zoom * 1.2));
	t->y2 = t->y1 + t->tmp2 / 1.2;
	t->zoom *= 1.2;
	i++;
	if (i % 3 == 0)
		t->iteration_max++;
}

void	ft_dezoom(t_t *t)
{
	static int j;

	t->x1 = (t->xtmp / t->zoom + t->x1) - (t->l / (t->zoom / 1.2) / 2);
	t->x1 += (t->l / (t->zoom / 1.2) / 2) - (t->xtmp / (t->zoom / 1.2));
	t->x2 = t->x1 + t->tmp1 * 1.2;
	t->y1 = (t->ytmp / t->zoom + t->y1) - (t->h / (t->zoom / 1.2) / 2);
	t->y1 += (t->h / (t->zoom / 1.2) / 2) - (t->ytmp / (t->zoom / 1.2));
	t->y2 = t->y1 + t->tmp2 * 1.2;
	t->zoom /= 1.2;
	j++;
	if (j % 3 == 0)
		t->iteration_max--;
}

int		ft_mouse_move(int x, int y, t_t *t)
{
	static int tmp_x;

	if (t->fractal == 2)
	{
		if (x > 0 && x < t->l && y > 0 && y < t->h)
		{
			if (x > tmp_x && t->c_r <= 1)
				t->julia += (float)x / t->zoom / 100;
			else if (x < tmp_x && t->c_r >= 0.03)
				t->julia -= (float)x / t->zoom / 100;
			tmp_x = x;
		}
	}
	ft_put_img(t);
	return (0);
}

int		ft_mouse(int mouse_code, int x, int y, t_t *t)
{
	t->tmp1 = t->x2 - t->x1;
	t->tmp2 = t->y2 - t->y1;
	if (mouse_code == 1 || mouse_code == 4)
		ft_zoom(x, y, t);
	if ((mouse_code == 2 || mouse_code == 5) && t->zoom <= 2147483647)
		ft_dezoom(t);
	ft_put_img(t);
	return (0);
}
