/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 14:26:34 by semen             #+#    #+#             */
/*   Updated: 2020/08/31 00:19:18 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	change_status_one(t_number *list_b)
{
	int num;
	num = list_b->n;
	int count = 0;

	while (list_b)
	{
		list_b->status = 1;
		count++;
		list_b = list_b->next;
		if (num == list_b->n)
			break;
	}
}

static int	calculation_quantity(int count_assist, int n)
{
	int q;
	int quantity;
	int ret;

	q = 0;
	quantity = 0;
	ret = 0;
	if (n <= 100)
		q = 2;
	else
		q = 5;
	quantity = n / q;
	if (count_assist < q)
		return (quantity);
	else
	{
		count_assist--;
		ret = n - count_assist * quantity;
		return (ret);
	}
	return (-1);
}

void		timsort(t_number *list_a, t_number *list_b)
{
	int n;
	int q;
	int quantity;
	int count_assist;

	count_assist = 1;
	n = count_list(list_a);
	q = (n <= 100) ? 2 : 5;
	quantity = calculation_quantity(count_assist, n);
	insertion_sort_first(&list_a, &list_b, quantity);
	change_status_one(list_b);
	centering_stack_first(&list_b);
	merge_sort_first(&list_a, &list_b);
	while(--q)
	{
		count_assist++;
		quantity = calculation_quantity(count_assist, n);
		insertion_sort_regular(&list_a, &list_b, quantity);
		change_status_one(list_b);
		centering_stack_regular(&list_a, &list_b);
		merge_sort_regular(&list_a, &list_b);
	}
	centering_stack_regular_a(&list_a);
}
