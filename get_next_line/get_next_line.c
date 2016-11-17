/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:07:48 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/17 18:46:58 by geoffrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

char	*ft_first_part(int fd)
{
	char	*tmp;
	char	*dst;
	int		ret;
	char	*buf;
	int		i;

	i = 0;
	tmp = ft_strnew(0);
	dst = ft_strnew(0);
	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) && !ft_memchr(buf, '\n', BUFF_SIZE))
	{
		buf[ret] = '\0';
		tmp = ft_strdup(buf);
		free(dst);
		dst = ft_strjoin(dst, tmp);
		free(tmp);
	}
	if (!ft_memchr(buf, '\n', BUFF_SIZE))
		return (buf);
	tmp = ft_strdup(dst);
	dst = ft_strjoin(tmp, buf);
	if (buf)
		free(buf);
	if (tmp)
		free(tmp);
	return (dst);
}

int     get_next_line(const int fd, char **line)
{
	int             i;
	char            *src;
	char            *buf;
	static char     *temp = NULL;

	i = 0;
	buf = ft_strnew(0);
	src = ft_strnew(0);
	if (read(fd, buf, 0) == -1 || fd == -1 || !line)
		return (-1);
	src = ft_first_part(fd);
	if (!temp)
		temp = ft_strnew(0);
	src = ft_strjoin(temp, src);
	if ((ft_memchr(src, '\n', ft_strlen(src))))
	{
		while (src[i] != '\n')
			i++;
		*line = ft_strsub(src, 0, i);
		temp = ft_strsub(src, i + 1, ft_strlen(src));
		return (1);
	}
	*line = ft_strdup(src);
	if ((*line)[0] != '\0')
	{
		temp = ft_strnew(0);
		return (1);
	}
	return (0);
}
