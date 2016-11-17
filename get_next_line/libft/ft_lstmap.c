/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:21:46 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/06 15:19:12 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*res;
	t_list		*rescpy;
	t_list		*new;

	res = NULL;
	rescpy = NULL;
	if (lst && f)
		while (lst)
		{
			if (!(new = (t_list*)malloc(sizeof(t_list))))
				return (NULL);
			new = f(lst);
			if (!res)
			{
				res = new;
				rescpy = new;
			}
			else
			{
				res->next = new;
				res = res->next;
			}
			lst = lst->next;
		}
	return (rescpy);
}
