/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centering_stack_regular_a_kv.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 20:40:10 by oem               #+#    #+#             */
/*   Updated: 2020/08/31 00:02:22 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_number_left(t_number **list_a, int *i)
{
	int min;
	int count;
	int n;

	min = (*list_a)->n;
	count = 0;
	n = (*list_a)->n;
	while (*list_a)
	{
		if ((*list_a)->status == 1)
		{
			if ((*list_a)->n < min)
			{
				min = (*list_a)->n;
				*i = count;
			}
			if ((*list_a)->next != NULL)
			{
				*list_a = (*list_a)->prev;
				count++;
			}
		}
		else
		{
			*list_a = (*list_a)->prev;
			count++;
		}
		if (n == (*list_a)->n)
			break ;
	}
	return (min);
}

static int	find_min_number_right(t_number **list_a, int *i)
{
	int min;
	int count;
	int n;

	min = (*list_a)->n;
	count = 0;
	n = (*list_a)->n;
	while (*list_a)
	{
		if ((*list_a)->status == 1)
		{
			if ((*list_a)->n < min)
			{
				min = (*list_a)->n;
				*i = count;
			}
			if ((*list_a)->next != NULL)
			{
				*list_a = (*list_a)->next;
				count++;
			}
		}
		else
		{
			*list_a = (*list_a)->next;
			count++;
		}
		if (n == (*list_a)->n)
			break ;
	}
	return (min);
}

static int	find_min_number(t_number **list_a, int *rotation_logic)
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

int			centering_stack_regular_a_kv(t_number **list_a, t_number **list_b, int i)
{
	int step = 0;
	int rotation_logic;

	step = find_min_number(list_a, &rotation_logic);
	while(step)
	{
		if (rotation_logic == 0)
		{
			system("clear");
			ft_printf("exec ");
			ra_three(&list_a);
			i++;
			ft_printf("move = %d\n", i);
			show_me_two(list_a, list_b);
			usleep(3000000);
		}
		else
		{
			system("clear");
			ft_printf("exec ");
			rra_three(&list_a);
			i++;
			ft_printf("move = %d\n", i);
			show_me_two(list_a, list_b);
			usleep(3000000);
		}
		step--;
	}
	return (i);
}
