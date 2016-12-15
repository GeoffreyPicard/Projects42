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

void	ft_put_pixel_to_img(unsigned long color, t_t *t, int l, int h)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0x00FF00) >> 8);
	b = (color & 0x0000FF);
	if (l >= 0 && l < t->L_screen && h >= 0 && h < t->H_screen)
	{
		t->img[h * t->sizeline + l * t->bpp / 8] = b;
		t->img[h * t->sizeline + l * t->bpp / 8 + 1] = g;
		t->img[h * t->sizeline + l * t->bpp / 8 + 2] = r;
	}
}

int		ft_put_img(t_t *t)
{
	ft_bzero(t->img, t->H_screen * t->sizeline);
	ft_ray_casting(t);
	mlx_put_image_to_window(t->mlx_ptr, t->win_ptr,
			t->img_ptr, 0, 0);
	return (0);
}

int	ft_close(t_t *t)
{
	free(t);
	exit(1);
	return (1);
}

void	ft_image(t_t *t)
{
	t->mlx_ptr = mlx_init();
	t->win_ptr = mlx_new_window(t->mlx_ptr, t->L_screen, t->H_screen, "wolf3d");
	t->img_ptr = mlx_new_image(t->mlx_ptr, t->L_screen, t->H_screen);
	t->img = mlx_get_data_addr(t->img_ptr, &(t->bpp),
			&(t->sizeline), &(t->endian));
	mlx_expose_hook(t->win_ptr, ft_put_img, t);
//	mlx_hook(t->win_ptr, 6, 1L << 6, ft_mouse_move, t);
	mlx_hook(t->win_ptr, 2, 1L << 0, ft_key, t);
	mlx_hook(t->win_ptr, 17, 0L, ft_close, t);
//	mlx_mouse_hook(t->win_ptr, ft_mouse, t);
//	mlx_string_put(t->mlx_ptr, t->win_ptr, 20, 20, 0x00FFFFFF, "hello");
	mlx_loop(t->mlx_ptr);
}
