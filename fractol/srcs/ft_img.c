/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:52:33 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/08 11:14:28 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pixel_to_img(unsigned long color, t_t *t, int l, int h)
{
	(void)color;
	if (l >= 0 && l < t->l && h >= 0 && h < t->h)
	{
		t->img[h * t->sizeline + l * t->bpp / 8] = 0 *
			((float)t->i / t->iteration_max) + t->b_color;
		t->img[h * t->sizeline + l * t->bpp / 8 + 1] = 275 *
			((float)t->i / t->iteration_max) + t->g_color;
		t->img[h * t->sizeline + l * t->bpp / 8 + 2] = 255 *
			((float)t->i / t->iteration_max) + t->r_color + 20;
	}
}

void	ft_put_str(t_t *t)
{
	char *str;

	str = ft_itoa(t->iteration_max);
	str = ft_strjoin("Iterations: ", str);
	mlx_string_put(t->mlx_ptr, t->win_ptr, 10, 10, 0x00FFFFFF, str);
	if (t->iteration_max > 50)
	{
		mlx_string_put(t->mlx_ptr, t->win_ptr, 10, 40, 0x00FFFFFF,
				"Piano Piano sur les iterations");
		mlx_string_put(t->mlx_ptr, t->win_ptr, 320, 40, 0x00FFFFFF, t->prenom);
	}
	if (t->iteration_max > 60)
		mlx_string_put(t->mlx_ptr, t->win_ptr, 10, 70, 0x00FFFFFF,
				"Piano piano...");
	if (t->iteration_max > 80)
	{
		mlx_string_put(t->mlx_ptr, t->win_ptr, 10, 100,
				0x00FFFFFF, "Ca va ramer");
		mlx_string_put(t->mlx_ptr, t->win_ptr, 130, 100, 0x00FFFFFF, t->prenom);
	}
	if (t->iteration_max >= 100)
		mlx_string_put(t->mlx_ptr, t->win_ptr, 10, 130,
				0x00FFFFFF, "Je t'avais prevenu :)");
	free(str);
}

int		ft_put_img(t_t *t)
{
	ft_bzero(t->img, t->h * t->sizeline);
	if (t->fractal == 1)
		ft_mandelbrot(t);
	if (t->fractal == 2)
		ft_julia(t);
	if (t->fractal == 3)
		ft_carre(t);
	if (t->fractal == 4)
		ft_bille(t);
	mlx_put_image_to_window(t->mlx_ptr, t->win_ptr,
			t->img_ptr, 0, 0);
	ft_put_str(t);
	return (0);
}

int		ft_close(void)
{
	exit(1);
	return (1);
}

void	ft_image(t_t *t)
{
	t->mlx_ptr = mlx_init();
	t->win_ptr = mlx_new_window(t->mlx_ptr, t->l, t->h, "fract'ol");
	t->img_ptr = mlx_new_image(t->mlx_ptr, t->l, t->h);
	t->img = mlx_get_data_addr(t->img_ptr, &(t->bpp),
			&(t->sizeline), &(t->endian));
	mlx_expose_hook(t->win_ptr, ft_put_img, t);
	if (t->fractal == 2)
		mlx_hook(t->win_ptr, 6, 1L << 6, ft_mouse_move, t);
	mlx_hook(t->win_ptr, 2, 1L << 0, ft_key, t);
	mlx_hook(t->win_ptr, 17, 0L, ft_close, 0);
	mlx_mouse_hook(t->win_ptr, ft_mouse, t);
	mlx_string_put(t->mlx_ptr, t->win_ptr, 20, 20, 0x00FFFFFF, "hello");
	mlx_loop(t->mlx_ptr);
}
