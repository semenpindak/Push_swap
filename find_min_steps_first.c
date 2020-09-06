/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_steps_first.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 00:44:42 by semen             #+#    #+#             */
/*   Updated: 2020/09/04 15:50:42 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	record_value_in_stack_a(t_num ***list_a)
{
	int num;
	int count;

	num = (**list_a)->n;
	count = 0;
	while (**list_a)
	{
		(**list_a)->la = count;
		if ((**list_a)->next != NULL)
			(**list_a) = (**list_a)->next;
		count++;
		if (num == (**list_a)->n)
			break ;
	}
	count = 0;
	while (**list_a)
	{
		(**list_a)->ra = count;
		if ((**list_a)->prev != NULL)
			(**list_a) = (**list_a)->prev;
		count++;
		if (num == (**list_a)->n)
			break ;
	}
}

static void	fill_struct_resulting_values(t_num **list_a)
{
	if ((*list_a)->ra < (*list_a)->la)
	{
		(*list_a)->step_a = (*list_a)->ra;
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

void		find_min_steps_first(t_num **list_a, t_num **list_b)
{
	int n;

	record_value_in_stack_a(&list_a);
	n = count_list_two(list_a);
	while (n)
	{
		count_step_in_b_first(list_a, list_b);
		fill_struct_resulting_values(list_a);
		*list_a = (*list_a)->next;
		n--;
	}
}
