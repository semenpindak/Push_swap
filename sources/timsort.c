/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 14:26:34 by semen             #+#    #+#             */
/*   Updated: 2020/09/05 14:55:37 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculation_piece(int count, int n)
{
	int q;
	int d;
	int ret;

	q = 0;
	d = 0;
	ret = 0;
	q = (n <= 100) ? 2 : 5;
	d = n / q;
	if (count < q)
		return (d);
	else
	{
		count--;
		ret = n - count * d;
		return (ret);
	}
	return (-1);
}

void		timsort(t_num *list_a, t_num *list_b, t_key *bonus)
{
	int n;
	int q;
	int d;
	int count;

	count = 1;
	n = count_list(list_a);
	q = (n <= 100) ? 2 : 5;
	d = calculation_piece(count, n);
	insertsort_first(&list_a, &list_b, d, bonus);
	centering_stack_first(&list_a, &list_b, bonus);
	mergesort_first(&list_a, &list_b, bonus);
	while(--q)
	{
		count++;
		d = calculation_piece(count, n);
		insertsort_regular(&list_a, &list_b, d, bonus);
		centering_stack_regular(&list_a, &list_b, bonus);
		mergesort_regular(&list_a, &list_b, bonus);
	}
	centering_stack_finish(&list_a, &list_b, bonus);
}
