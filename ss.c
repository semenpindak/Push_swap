/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 19:01:30 by semen             #+#    #+#             */
/*   Updated: 2020/04/11 07:13:40 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checking_quantity(t_number *list_a, t_number *list_b)
{
	int n;

	n = 0;
	while(list_a)
	{
		list_a = list_a->next;
		n++;
		if (n > 1)
			break;
	}
	if (n <= 1)
		return (0);
	n = 0;
	while(list_b)
	{
		list_b = list_b->next;
		n++;
		if (n > 1)
			break;
	}
	if (n <= 1)
		return (0);
	return (1);
}

int			ss(t_number *list_a, t_number *list_b)
{
	int tmp_current;
	int tmp_next;

	if ((checking_quantity(list_a, list_b)) == 0)
		return (0);
	tmp_current = list_a->n;
	list_a = list_a -> next;
	tmp_next = list_a->n;
	list_a->n = tmp_current;
	list_a = list_a->prev;
	list_a->n = tmp_next;
	tmp_current = list_b->n;
	list_b = list_b -> next;
	tmp_next = list_b->n;
	list_b->n = tmp_current;
	list_b = list_b->prev;
	list_b->n = tmp_next;
	ft_putstr("ss\n");
	return (1);
}
