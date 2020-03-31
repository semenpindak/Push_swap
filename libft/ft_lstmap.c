/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:18:15 by calpha            #+#    #+#             */
/*   Updated: 2019/10/26 21:37:15 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		del(t_list *lst)
{
	t_list *temp;

	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp->content);
		free(temp);
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *ret_list;

	head = NULL;
	ret_list = f(lst);
	head = ret_list;
	if (lst && f)
	{
		while (lst->next != NULL)
		{
			if ((head->next = f(lst->next)))
			{
				head = head->next;
				lst = lst->next;
			}
			else
			{
				del(head);
				break ;
			}
		}
	}
	return (ret_list);
}
