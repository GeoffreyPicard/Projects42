/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:41:27 by abonneca          #+#    #+#             */
/*   Updated: 2016/12/01 09:56:37 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_lenfd(int fd)
{
	int		ret;
	int		i;
	char	buf[2];

	i = 0;
	while ((ret = read(fd, buf, 1)))
	{
		if (i > 550)
			return (-1);
		buf[1] = '\0';
		i++;
	}
	if (i > 550)
		return (-1);
	return (i);
}

char	*ft_string_to_fd(char *dst, int fd)
{
	int		ret;
	char	buf[2];
	int		i;

	i = 0;
	while ((ret = read(fd, buf, 1)))
	{
		buf[1] = '\0';
		dst[i] = buf[0];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

int		ft_open_len(char *av)
{
	int len;
	int fd;

	fd = 0;
	if (!(fd = open(av, O_RDWR)))
		return (-1);
	if (fd == -1)
	{
		ft_putstr("error\n");
		return (-1);
	}
	len = ft_lenfd(fd);
	if (len == -1)
	{
		ft_putstr("error\n");
		return (-1);
	}
	if (close(fd) == -1)
	{
		ft_putstr("close error ()");
		return (-1);
	}
	return (len);
}

void	ft_exe_main(char *src)
{
	char	**tab;
	char	*str;
	t_coord	**pieces;

	str = ft_str_without_back_slash(src);
	tab = ft_str_to_tab(str);
	pieces = ft_store_pieces(tab, ft_nb_piece(str), ft_nb_piece(str));
	ft_solve(pieces, ft_nb_piece(str), 1);
}

int		main(int ac, char **ar)
{
	int		fd;
	char	*dst;
	int		len;

	fd = 0;
	len = 0;
	if (ac == 2)
	{
		if (ft_open_len(ar[1]) == -1)
			return (1);
		len = ft_open_len(ar[1]);
		fd = open(ar[1], O_RDWR);
		if (!(dst = malloc(sizeof(char) * len + 1)))
			return (1);
		dst = ft_string_to_fd(dst, fd);
		if (ft_check_main(dst) != 0)
		{
			ft_putstr("error\n");
			return (1);
		}
		ft_exe_main(dst);
	}
	else
		ft_putstr("usage: ./fillit target_file");
	return (0);
}
