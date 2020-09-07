/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centering_stack_regular.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 20:38:32 by oem               #+#    #+#             */
/*   Updated: 2020/09/07 12:18:41 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_min_number_left_stack(t_num **list_a, int *i)
{
	int min;
	int count;
	int n;

	min = 2147483647;
	count = 0;
	n = (*list_a)->n;
	while (*list_a)
	{
		if ((*list_a)->n < min && (*list_a)->status == 1)
		{
			min = (*list_a)->n;
			*i = count;
		}
		*list_a = (*list_a)->prev;
		count++;
		if (n == (*list_a)->n)
			break ;
	}
}

static void	find_min_number_right_stack(t_num **list_a, int *i)
{
	int min;
	int count;
	int n;

	min = 2147483647;
	count = 0;
	n = (*list_a)->n;
	while (*list_a)
	{
		if ((*list_a)->n < min && (*list_a)->status == 1)
		{
			min = (*list_a)->n;
			*i = count;
		}
		*list_a = (*list_a)->next;
		count++;
		if (n == (*list_a)->n)
			break ;
	}
}

static int	find_min_number_stack(t_num **list_a, int *rotation_logic)
{
	int a;
	int b;

	a = 0;
	b = 0;
	find_min_number_left_stack(list_a, &a);
	find_min_number_right_stack(list_a, &b);
	if (a < b)
	{
		*rotation_logic = 1;
		return (a);
	}
	else
	{
		*rotation_logic = 0;
		return (b);
	}
	return (-1);
}

void		centering_stack_regular(t_num **list_a, t_num **list_b, t_key *bonus)
{
	int step_a;
	int step_b;
	int logic_a;
	int logic_b;

	step_a = find_min_number_stack(list_a, &logic_a);
	step_b = find_min_number_stack(list_b, &logic_b);
	(*list_a)->step_a = step_a;
	(*list_b)->step_b = step_b;
	if (logic_a == logic_b)
	{
		if (step_a >= step_b)
		{
			joint_rotation(list_a, list_b, bonus, logic_a);
			(*list_a)->step_a = step_a - step_b;
			rotation_stack_a(list_a, list_b, bonus, logic_a);
		}
		else
		{
			joint_rotation(list_a, list_b, bonus, logic_a);
			(*list_b)->step_b = step_b - step_a;
			rotation_stack_b(list_a, list_b, bonus, logic_b);
		}
	}
	else
	{
		rotation_stack_a(list_a, list_b, bonus, logic_a);
		rotation_stack_b(list_a, list_b, bonus, logic_b);
	}
}
