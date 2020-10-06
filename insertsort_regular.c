/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertsort_regular.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:47:12 by oem               #+#    #+#             */
/*   Updated: 2020/09/03 17:24:58 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int search_struct_to_move(t_num **list_a, int *step_a, int *step_b, int *logic_a)
{
	int logic_b;
	int min = 2147483647;
	int num = (*list_a)->n;

	min = 2147483647;
	num = (*list_a)->n;
	while (*list_a)
	{
		if ((*list_a)->sum_steps < min)
		{
			min = (*list_a)->sum_steps;
			*step_a = (*list_a)->step_a;
			*step_b = (*list_a)->step_b;
			*logic_a = (*list_a)->logic_a;
			logic_b = (*list_a)->logic_b;
		}
		*list_a = (*list_a)->next;
		if (num == (*list_a)->n)
			break;
	}
	return (logic_b);
}

void	insertsort_regular(t_num **list_a, t_num **list_b, int d, t_key *bonus)
{
	int step_a = 0;
	int step_b = 0;
	int logic_a = 0;
	int logic_b = 0;

	while (*list_a)
	{
		if (*list_b == NULL)
		{
			pb_when_stack_b_null(list_a, list_b, bonus);
			pb(&list_a, &list_b, bonus);
			(*list_b)->status = 1;
			debug_print_two(list_a, list_b, bonus);
		}
		find_min_steps_regular(list_a, list_b);
		logic_b = search_struct_to_move(list_a, &step_a, &step_b, &logic_a);
		(*list_a)->step_a = step_a;
		(*list_b)->step_b = step_b;
		if (logic_a == logic_b)
		{
			if (step_a >= step_b)
			{
				rotation_both_stacks(list_a, list_b, bonus, logic_a);
				(*list_a)->step_a = step_a - step_b;
				rotation_stack_a(list_a, list_b, bonus, logic_a);
			}
			else
			{
				rotation_both_stacks(list_a, list_b, bonus, logic_a);
				(*list_b)->step_b = step_b - step_a;
				rotation_stack_b(list_a, list_b, bonus, logic_b);
			}
		}
		else
		{
			rotation_stack_a(list_a, list_b, bonus, logic_a);
			rotation_stack_b(list_a, list_b, bonus, logic_b);
		}
		pb(&list_a, &list_b, bonus);
		(*list_b)->status = 1;
		debug_print_two(list_a, list_b, bonus);
		if (--d == 1)
			break ;
	}
}
