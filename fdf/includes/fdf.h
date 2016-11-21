/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:46:58 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/21 17:03:27 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <stdio.h>
# include "mlx.h"

typedef	struct	s_inttab
{
	int				*tab;
	struct s_inttab *next;
}				t_inttab;

t_inttab    *ft_create_elem(int *tab);
void    ft_list_push_back(t_inttab *list, int *tab);
int     ft_count_len(char **tab);
int     *ft_tab_to_inttab(char **tab);
char    **ft_char_to_tab(char *line);
t_inttab	*ft_parse(int fd, char **line, int *l);
int     ft_list_size(t_inttab *list);
int     **ft_list_to_tab(t_inttab *list, int h, int l);
char    **ft_char_to_tab(char *line);
int     ft_get_x(int x, int z);
int     ft_get_y(int y, int z);





void    ft_print_inttab(int *tab, int len);
void    ft_print_tab(char **tab);
void    ft_print_tab_int(int **tab, int h, int l);
void    ft_print_list(t_inttab *list, int len);


#endif
