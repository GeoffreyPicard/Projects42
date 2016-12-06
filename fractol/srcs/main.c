/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 09:25:41 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/02 10:57:58 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "fractol.h"

void ft_init_value_mandelrot(t_t *t)
{
	t->fractal = 1;
	t->l = 810;
	t->h = 720;
	t->iteration_max = 20;
	t->g_color = 0;
	t->b_color = 0;
	t->r_color = 0;
	t->g_color2 = 0;
	t->b_color2 = 0;
	t->r_color2 = 0;
	t->k = 1;
	t->x1 = -2.1;
	t->x2 = 0.6;
	t->y1 = -1.2;
	t->y2 = 1.2;
	t->zoom = 300;
}

void ft_init_value_julia(t_t *t)
{
	t->fractal = 2;
	t->l = 600;
	t->h = 720;
	t->x1 = -1;
	t->x2 = 1;
	t->y1 = -1.2;
	t->y2 = 1.2;
	t->zoom = 300;
	t->iteration_max = 150;
}

int	ft_init_value(t_t *t, char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		ft_init_value_mandelrot(t);
	else if (ft_strcmp(str, "julia") == 0)
		ft_init_value_julia(t);
	else
	{
		ft_putstr("You can only use:\n\nmandelbrot\njulia\n\n");
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_t			*t;

	(void)av;
	if (ac == 2)
	{
		t = (t_t *)malloc(sizeof(t_t));
		if (ft_init_value(t, av[1]) == 1)
			return (1);
		ft_image(t);
	}
	return (0);
}
