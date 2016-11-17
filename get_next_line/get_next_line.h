/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:24:02 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/17 15:47:08 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE 100

int		get_next_line(const int fd, char **line);
void	ft_putchar(char c);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
