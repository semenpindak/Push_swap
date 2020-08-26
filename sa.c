/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 20:06:44 by semen             #+#    #+#             */
/*   Updated: 2020/08/26 13:32:31 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checking_quantity(t_number *list)
{
	int n;

	n = 0;
	while(list)
	{
		list = list->next;
		n++;
		if (n > 1)
			return (1);
	}
	return (0);
}

int			sa(t_number *list)
{
	int tmp_current;
	int tmp_next;

	if ((checking_quantity(list)) == 0)
		return (0);
	tmp_current = list->n;
	list = list -> next;
	tmp_next = list->n;
	list->n = tmp_current;
	list = list->prev;
	list->n = tmp_next;
	printf("sa\n");
	return (1);
}
