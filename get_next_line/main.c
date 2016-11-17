/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:26:28 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/17 16:28:20 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	int		fd;

	fd = 0;
	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	get_next_line(fd, &av[1]);
////get_next_line(fd, &av[1]);
////get_next_line(fd, &av[1]);
//	get_next_line(fd, &av[1]);
//	get_next_line(fd, &av[1]);
//	get_next_line(fd, &av[1]);
//	get_next_line(fd, &av[1]);
//	printf("%d\n", get_next_line(fd, &av[1]));
//	printf("%d\n", get_next_line(fd, &av[1]));
//	printf("%d\n", get_next_line(fd, &av[1]));
//	printf("%d\n", get_next_line(fd, &av[1]));
//	printf("%d\n", get_next_line(fd, &av[1]));
	close(fd);
	return (0);
}
