/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 10:32:09 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/14 10:16:26 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	j;

	i = 0;
	j = start;
	if (!s)
		return (NULL);
	if (!(dst = ft_strnew(len)))
		return (NULL);
	while (j < len + start)
	{
		dst[i] = s[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

void		ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char*)s)[i] != '\0')
			((char*)s)[i] = '\0';
		i++;
	}
}

void		*ft_memalloc(size_t size)
{
	void	*dst;
	size_t	i;

	i = 0;
	if (!(dst = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(dst, size);
	return (dst);
}

char		*ft_strnew(size_t size)
{
	char	*dst;

	dst = (char*)ft_memalloc(size + 1);
	return (dst);
}

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char*)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
