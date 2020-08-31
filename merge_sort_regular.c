/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_regular.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:19:14 by calpha            #+#    #+#             */
/*   Updated: 2020/08/31 00:15:51 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int count_list_stack_a_status(t_number **list_a)
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

void	merge_sort_regular(t_number **list_a, t_number **list_b)
{
	int n;
	int n_stack_a = 0;

	n = count_list_two(list_b);
	n_stack_a = count_list_stack_a_status(list_a);
	while (n)
	{
		if ((*list_a)->n > (*list_b)->n)
		{
			pa_three(&list_a, &list_b);
			n_stack_a++;
			n--;
		}
		if ((*list_b) != NULL && ((*list_b)->n > (*list_a)->n))
		{
			ra_three(&list_a);
			n_stack_a--;
		}
		if (n_stack_a == 0)
		{
			while(n)
			{
				pa_three(&list_a, &list_b);
				ra_three(&list_a);
				n--;
			}
		}
		if (n == 0)
			break;
	}
}
