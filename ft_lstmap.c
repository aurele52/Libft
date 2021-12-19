/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:20:14 by audreyer          #+#    #+#             */
/*   Updated: 2021/12/01 00:23:23 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		i;
	t_list	*newlist;
	t_list	*mem;
	t_list	*lol;

	i = 0;
	if (!lst)
		return (0);
	newlist = ft_lstnew((*f)(lst->content));
	mem = newlist;
	if (!newlist)
		return (0);
	lst = lst->next;
	while (lst)
	{
		lol = ft_lstnew((*f)(lst->content));
		if (lol == 0)
		{
			ft_lstclear(&newlist, del);
			return (0);
		}
		ft_lstadd_back(&newlist, lol);
		lst = lst->next;
	}
	return (newlist);
}
