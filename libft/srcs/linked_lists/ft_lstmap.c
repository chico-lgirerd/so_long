/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirerd <lgirerd@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:39:31 by lgirerd           #+#    #+#             */
/*   Updated: 2024/12/12 16:26:51 by lgirerd          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_node(void *content, void (*del)(void *))
{
	t_list	*node;

	node = ft_lstnew(content);
	if (!node && del)
		del(content);
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lsthead;
	t_list	*newnode;
	t_list	*current;

	if (!lst || !f || !del)
		return (NULL);
	newnode = ft_node(f(lst->content), del);
	if (!newnode)
		return (NULL);
	lsthead = newnode;
	current = lsthead;
	lst = lst->next;
	while (lst)
	{
		newnode = ft_node(f(lst->content), del);
		if (!newnode)
		{
			ft_lstclear(&lsthead, del);
			return (NULL);
		}
		current->next = newnode;
		current = newnode;
		lst = lst->next;
	}
	return (lsthead);
}
