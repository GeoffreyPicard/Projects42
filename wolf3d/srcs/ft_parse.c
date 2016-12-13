/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:30:27 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/12 09:57:10 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_lenfd(int fd, t_t *t)
{
	int		ret;
	int		tmp;
	char	buf[2];

	tmp = 0;
	while ((ret = read(fd, buf, 1)))
	{
		if (buf[0] == '\n')
		{
			if (tmp != t->l && tmp != 0)
				return (-1);
			tmp = t->l;
			t->l = -1;
			t->h++;
		}
		if (buf[0] != '\n' && !(buf[0] >= '0' && buf[0] <= '9'))
			return (-1);
		t->l++;
		if (t->l > 550)
			return (-1);
		buf[1] = '\0';
	}
	t->l = tmp;
	return ((t->h < 4 || t->l < 4) ? -1 : 0);
}

int		ft_open_len(char *str, t_t *t)
{
	int len;
	int fd;

	fd = 0;
	if (!(fd = open(str, O_RDWR)))
		return (-1);
	if (fd == -1)
	{
		ft_putstr("Map error\n");
		return (-1);
	}
	len = ft_lenfd(fd, t);
	if (len == -1)
	{
		ft_putstr("Map error\n");
		return (-1);
	}
	if (close(fd) == -1)
	{
		ft_putstr("close error ()");
		return (-1);
	}
	return (0);
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

void	ft_char_to_int(char *str, int fd, t_t *t)
{
	int i;
	int j;
	int	k;

	j = -1;
	i = -1;
	k = -1;
	str = ft_string_to_fd(str, fd);
	t->map = (int **)malloc(sizeof(int *) * t->h);
	while (++i < t->h)
		(t->map)[i] = malloc(sizeof(int) * t->l);
	while (++j < t->h)
	{
		i = 0;
		while (i < t->l)
		{
			if (str[++k] != '\n')
			{
				t->map[j][i] = str[k] - '0';
				i++;
			}
		}
	}
}

int		ft_main_parse(t_t *t, char **av)
{
	char	*str;
	int		fd;

	if (ft_open_len(av[1], t) == -1)
		return (1);
	fd = open(av[1], O_RDWR);
	str = (char *)malloc(sizeof(char) * t->l * t->h);
	ft_char_to_int(str, fd, t);
	return (0);
}
