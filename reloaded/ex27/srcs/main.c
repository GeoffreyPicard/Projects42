/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 20:02:20 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/03 09:16:24 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_error(int nb)
{
	if (nb == 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	if (nb == 3)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[2];

	fd = open(av[1], O_RDONLY);
	if (ac == 1)
		return (ft_error(3));
	else if (ac == 2)
	{
		while ((ret = read(fd, buf, 1)))
		{
			buf[1] = '\0';
			ft_putchar(buf[0]);
		}
	}
	else if (ac > 2)
		return (ft_error(2));
	close(fd);
	return (0);
}
