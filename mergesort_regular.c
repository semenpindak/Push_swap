/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort_regular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 01:47:40 by oem               #+#    #+#             */
/*   Updated: 2020/10/06 16:52:04 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int count_list_stack_a_status(t_num **list_a)
{
	int num;
	int count;

	num = (*list_a)->n;
	count = 0;
	while (*list_a)
	{
		if ((*list_a)->status == 1)
			count++;
		*list_a = (*list_a)->next;
		if (num == (*list_a)->n)
			break ;
	}
	return (count);
}

void	mergesort_regular(t_num **list_a, t_num **list_b, t_key *bonus)
{
	int n;
	int n_stack_a;

	n = count_list_two(list_b);
	n_stack_a = count_list_stack_a_status(list_a);
	while (n)
	{
		if ((*list_a)->n > (*list_b)->n)
		{
			pa(&list_a, &list_b, bonus);
			debug_print_two(list_a, list_b, bonus);
			n_stack_a++;
			n--;
		}
		if ((*list_b) != NULL && ((*list_b)->n > (*list_a)->n))
		{
			ra(&list_a, bonus);
			debug_print_two(list_a, list_b, bonus);
			n_stack_a--;
		}
		if (n_stack_a == 0)
		{
			while (n)
			{
				pa(&list_a, &list_b, bonus);
				debug_print_two(list_a, list_b, bonus);
				ra(&list_a, bonus);
				debug_print_two(list_a, list_b, bonus);
				n--;
			}
		}
	}
}
