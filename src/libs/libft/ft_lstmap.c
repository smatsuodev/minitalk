/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:57:47 by smatsuo           #+#    #+#             */
/*   Updated: 2023/05/22 07:02:06 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	head;
	t_list	*cur;
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*tmp;

	head.next = NULL;
	cur = lst;
	new_lst = &head;
	while (cur != NULL)
	{
		new_node = ft_calloc(1, sizeof(t_list));
		if (new_node == NULL)
		{
			ft_lstclear(&head.next, del);
			return (NULL);
		}
		new_node->content = f(cur->content);
		new_lst->next = new_node;
		new_lst = new_lst->next;
		tmp = cur->next;
		cur = tmp;
	}
	return (head.next);
}
