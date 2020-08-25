/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centering_stack_first.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:00:18 by calpha            #+#    #+#             */
/*   Updated: 2020/08/25 06:46:03 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_number_left(t_number **list_b, int *i)
{
	int max;
	int count;
	int n;

	max = (*list_b)->n;
	count = 0;
	n = (*list_b)->n;
	while (*list_b)
	{
		if ((*list_b)->prev != NULL)
		{
			*list_b = (*list_b)->prev;
			count++;
		}
		if ((*list_b)->n > max)
		{
			max = (*list_b)->n;
			*i = count;
		}
		if (n == (*list_b)->n)
			break ;
	}
	return (max);
}

static int	find_max_number_right(t_number **list_b, int *i)
{
	int max;
	int count;
	int n;

	max = (*list_b)->n;
	count = 0;
	n = (*list_b)->n;
	while (*list_b)
	{
		if ((*list_b)->next != NULL)
		{
			*list_b = (*list_b)->next;
			count++;
		}
		if ((*list_b)->n > max)
		{
			max = (*list_b)->n;
			*i = count;
		}
		if (n == (*list_b)->n)
			break ;
	}
	return (max);
}

static int	find_max_number(t_number **list_b, int *rotation_logic)
{
	int a;
	int b;

	a = 0;
	b = 0;
	find_max_number_left(list_b, &a);
	find_max_number_right(list_b, &b);
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

int			centering_stack_first(t_number **list_a, t_number **list_b)
{
	int i;
	int step;
	int rotation_logic;

	i = 0;
	rotation_logic = 0;
	step = find_max_number(list_b, &rotation_logic);
	while (step)
	{
		if (rotation_logic == 0)
		{
			ra_three(&list_b);
			show_me_two(list_a, list_b);
			// usleep(3000000);
			i++;
		}
		else
		{
			rra_three(&list_b);
			show_me_two(list_a, list_b);
			// usleep(3000000);
			i++;
		}
		step--;
	}
	return (i);
}
