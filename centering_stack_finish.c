/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centering_stack_finish.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 17:23:46 by oem               #+#    #+#             */
/*   Updated: 2020/09/06 17:24:45 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_min_number_left(t_num **list_a, int *i)
{
	int min;
	int count;
	int n;

	min = (*list_a)->n;
	count = 0;
	n = (*list_a)->n;
	while (*list_a)
	{
		if ((*list_a)->n < min)
		{
			min = (*list_a)->n;
			*i = count;
		}
		if ((*list_a)->prev != NULL)
			*list_a = (*list_a)->prev;
		count++;
		if (n == (*list_a)->n)
			break ;
	}
}

static void	find_min_number_right(t_num **list_a, int *i)
{
	int min;
	int count;
	int n;

	min = (*list_a)->n;
	count = 0;
	n = (*list_a)->n;
	while (*list_a)
	{
		if ((*list_a)->n < min)
		{
			min = (*list_a)->n;
			*i = count;
		}
		if ((*list_a)->next != NULL)
			*list_a = (*list_a)->next;
		count++;
		if (n == (*list_a)->n)
			break ;
	}
}

static int	find_min_number(t_num **list_a, int *rotation_logic)
{
	int a;
	int b;

	a = 0;
	b = 0;
	find_min_number_left(list_a, &a);
	find_min_number_right(list_a, &b);
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

void		centering_stack_finish(t_num **list_a, t_num **list_b, t_key *bonus)
{
	int step;
	int rotation_logic;

	rotation_logic = 0;
	step = find_min_number(list_a, &rotation_logic);
	while (step)
	{
		if (rotation_logic == 0)
		{
			ra_three(&list_a, bonus);
			debug_print_two(list_a, list_b, bonus);
		}
		else
		{
			rra_three(&list_a, bonus);
			debug_print_two(list_a, list_b, bonus);
		}
		step--;
	}
}
