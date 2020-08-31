/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 00:12:10 by oem               #+#    #+#             */
/*   Updated: 2020/09/01 00:12:39 by oem              ###   ########.fr       */
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

int			sa_checker(t_number *list)
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
	return (1);
}
