/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:07:48 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/20 15:40:28 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_first_part(int fd)
{
	char	*tmp;
	int		ret;
	char	*buf;
	char	*dst;

	dst = ft_strnew(0);
	buf = ft_strnew(BUFF_SIZE);
	while (!ft_memchr(buf, '\n', BUFF_SIZE) && (ret = read(fd, buf, BUFF_SIZE)))
	{
		tmp = ft_strdup(dst);
		free(dst);
		dst = ft_strjoin(tmp, buf);
		free(tmp);
		bzero(buf, BUFF_SIZE);
	}
	if (ft_memchr(buf, '\n', BUFF_SIZE))
	{
		tmp = ft_strdup(dst);
		free(dst);
		dst = ft_strjoin(tmp, buf);
		free(tmp);
	}
	free(buf);
	return (dst);
}

int		ft_help(char *src, char **line, char **temp)
{
	int i;

	i = 0;
	if ((ft_memchr(src, '\n', ft_strlen(src))))
	{
		while (src[i] != '\n')
			i++;
		*line = ft_strsub(src, 0, i);
		free(*temp);
		*temp = ft_strsub(src, i + 1, ft_strlen(src));
		return (1);
	}
	*line = ft_strdup(src);
	if ((*line)[0] != '\0')
	{
		bzero(*temp, ft_strlen(*temp));
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int				i;
	char			*src;
	char			*buf;
	char			*tmp;
	static char		*temp = NULL;

	i = 0;
	buf = ft_strnew(0);
	if (read(fd, buf, 0) == -1 || fd == -1 || !line)
		return (-1);
	free(buf);
	src = ft_first_part(fd);
	if (!temp)
		temp = ft_strnew(0);
	tmp = ft_strdup(src);
	free(src);
	src = ft_strjoin(temp, tmp);
	free(tmp);
	if (ft_help(src, line, &temp) == 1)
		return (1);
	return (0);
}
