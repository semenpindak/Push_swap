/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:21:36 by calpha            #+#    #+#             */
/*   Updated: 2019/10/26 21:22:08 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *cur;
	t_list *tmp;

	cur = *alst;
	if (*alst && alst && del)
	{
		while (cur)
		{
			tmp = cur->next;
			ft_lstdelone(&cur, del);
			cur = tmp;
		}
		*alst = NULL;
	}
}
