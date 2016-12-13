/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:32:23 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/13 14:32:25 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_li_img(int y0, int x1, int y1, t_t *t)
{
	t->dx = abs(x1 - t->x0);
	t->sx = t->x0 < x1 ? 1 : -1;
	t->dy = abs(y1 - y0);
	t->sy = y0 < y1 ? 1 : -1;
	t->err = (t->dx > t->dy ? t->dx : -(t->dy)) / 2;
	while (1)
	{
		ft_put_pixel_to_img(0x00FFFFFF, t, t->x0, y0);
		if (t->x0 == x1 && y0 == y1)
			break ;
		t->e2 = t->err;
		if (t->e2 > -(t->dx))
		{
			t->err -= t->dy;
			t->x0 += t->sx;
		}
		if (t->e2 < t->dy)
		{
			t->err += t->dx;
			y0 += t->sy;
		}
	}
}

void	ft_put_pixel_to_img(unsigned long color, t_t *t, int l, int h)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0x00FF00) >> 8);
	b = (color & 0x0000FF);
	if (l >= 0 && l < 2300 && h >= 0 && h < 1300)
	{
		t->img[h * t->sizeline + l * t->bpp / 8] = b;
		t->img[h * t->sizeline + l * t->bpp / 8 + 1] = g;
		t->img[h * t->sizeline + l * t->bpp / 8 + 2] = r;
	}
}

int		ft_put_img(t_t *t)
{
	ft_bzero(t->img, t->h * t->sizeline);

	mlx_put_image_to_window(t->mlx_ptr, t->win_ptr,
			t->img_ptr, 0, 0);
	return (0);
}

void	ft_image(t_t *t)
{
	t->mlx_ptr = mlx_init();
	t->win_ptr = mlx_new_window(t->mlx_ptr, t->l, t->h, "fract'ol");
	t->img_ptr = mlx_new_image(t->mlx_ptr, t->l, t->h);
	t->img = mlx_get_data_addr(t->img_ptr, &(t->bpp),
			&(t->sizeline), &(t->endian));
	mlx_expose_hook(t->win_ptr, ft_put_img, t);
//	mlx_hook(t->win_ptr, 6, 1L << 6, ft_mouse_move, t);
//	mlx_hook(t->win_ptr, 2, 1L << 0, ft_key, t);
//	mlx_hook(t->win_ptr, 17, 0L, ft_close, t);
//	mlx_mouse_hook(t->win_ptr, ft_mouse, t);
//	mlx_string_put(t->mlx_ptr, t->win_ptr, 20, 20, 0x00FFFFFF, "hello");
	mlx_loop(t->mlx_ptr);
}
