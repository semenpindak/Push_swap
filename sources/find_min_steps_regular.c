/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_steps_regular.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 21:31:15 by oem               #+#    #+#             */
/*   Updated: 2020/09/04 10:16:53 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	record_value_in_stack_a(t_num ***list_a)
{
	int num;
	num = (**list_a)->n;
	int count;

	count = 0;
	while (**list_a)
	{
		if ((**list_a)->status == 1)
			(**list_a)->la = 100;
		if ((**list_a)->status == 0)
			(**list_a)->la = count;
		if ((**list_a)->next != NULL)
			(**list_a) = (**list_a)->next;
		count++;
		if (num == (**list_a)->n)
			break;
	}
	count = 0;
	while (**list_a)
	{
		if ((**list_a)->status == 1)
			(**list_a)->ra = 100;
		if ((**list_a)->status == 0)
			(**list_a)->ra = count;
		if ((**list_a)->prev != NULL)
			(**list_a) = (**list_a)->prev;
		count++;
		if (num == (**list_a)->n)
			break;
	}
}

static void	fill_struct_resulting_values(t_num **list_a)
{
	if ((*list_a)->ra < (*list_a)->la)
	{
		(*list_a)->step_a =  (*list_a)->ra;
		(*list_a)->logic_a = 1;
	}
	else
	{
		(*list_a)->step_a = (*list_a)->la;
		(*list_a)->logic_a = 0;
	}
	if ((*list_a)->ra == (*list_a)->la)
	{
		(*list_a)->step_a = (*list_a)->ra;
		(*list_a)->logic_a = 2;
	}
	if ((*list_a)->rb < (*list_a)->lb)
	{
		(*list_a)->step_b = (*list_a)->rb;
		(*list_a)->logic_b = 1;
	}
	else
	{
		(*list_a)->step_b = (*list_a)->lb;
		(*list_a)->logic_b = 0;
	}
	if ((*list_a)->rb == (*list_a)->lb)
	{
		(*list_a)->step_b = (*list_a)->rb;
		(*list_a)->logic_b = 2;
	}
	(*list_a)->sum_steps = (*list_a)->step_a + (*list_a)->step_b;
}

void	find_min_steps_regular(t_num **list_a, t_num **list_b)
{
	int n;

	record_value_in_stack_a(&list_a);
	n = count_list_two(list_a);
	while (n)
	{
		count_step_in_b_regular(list_a, list_b);
		fill_struct_resulting_values(list_a);
		// printf("n = %3d | ", (*list_a)->n);
		// printf("ra = %3d ", (*list_a)->ra);
		// printf("la = %3d ", (*list_a)->la);
		// printf("step_a = %3d ", (*list_a)->step_a);
		// printf("logic_a = %3d |", (*list_a)->logic_a);
		// printf("rb = %3d ", (*list_a)->rb);
		// printf("lb = %3d ", (*list_a)->lb);
		// printf("step_b = %3d ", (*list_a)->step_b);
		// printf("logic_b = %3d |", (*list_a)->logic_b);
		// printf("sum_steps = %3d ", (*list_a)->sum_steps);
		// printf("status = %3d ", (*list_a)->status);
		// printf("(*list_b)->n = %3d\n", (*list_b)->n);
		*list_a = (*list_a)->next;
		n--;
	}
}
