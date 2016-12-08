/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:07:30 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/08 11:08:23 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_value_mandelrot(t_t *t)
{
	t->fractal = 1;
	t->l = 810;
	t->h = 720;
	t->iteration_max = 20;
	t->g_color = 0;
	t->b_color = 0;
	t->r_color = 0;
	t->k = 1;
	t->x1 = -2.1;
	t->x2 = 0.6;
	t->y1 = -1.2;
	t->y2 = 1.2;
	t->zoom = 300;
}

void	ft_init_value_julia(t_t *t)
{
	t->fractal = 2;
	t->l = 600;
	t->h = 720;
	t->x1 = -1;
	t->x2 = 1;
	t->y1 = -1.2;
	t->y2 = 1.2;
	t->zoom = 300;
	t->iteration_max = 50;
	t->julia = 0;
}

void	ft_init_value_carre(t_t *t)
{
	ft_init_value_mandelrot(t);
	t->fractal = 3;
}

void	ft_init_value_pouet(t_t *t)
{
	ft_init_value_mandelrot(t);
	t->zoom = 173.611111;
	t->x1 = -2.388;
	t->x2 = 2.2776;
	t->y1 = -2.064;
	t->y2 = 10.832;
	t->fractal = 4;
}
