/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_when_stack_b_null.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 05:28:19 by calpha            #+#    #+#             */
/*   Updated: 2020/08/31 00:24:25 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_left_status(t_number ***list_a, int *i)
{
	int count;
	int flag;
	int n;

	count = 0;
	flag = 0;
	n = (**list_a)->n;
	while (**list_a)
	{
		if ((**list_a)->status == 0 && flag == 0)
		{
			*i = count;
			flag = 1;
		}
		**list_a = (**list_a)->prev;
		count++;
		if (n == (**list_a)->n)
			break ;
	}
}

static void	find_right_status(t_number ***list_a, int *i)
{
	int count;
	int flag;
	int n;

	count = 0;
	flag = 0;
	n = (**list_a)->n;
	while (**list_a)
	{
		if ((**list_a)->status == 0 && flag == 0)
		{
			*i = count;
			flag = 1;
		}
		**list_a = (**list_a)->next;
		count++;
		if (n == (**list_a)->n)
			break ;
	}
}

static int	find_number_status_null(t_number ***list_a, int *rotation_logic)
{
	int a;
	int b;

	a = 0;
	b = 0;
	find_left_status(list_a, &a);
	find_right_status(list_a, &b);
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

void			pb_when_stack_b_null(t_number ***list_a)
{
	int step;
	int rotation_logic;

	step = find_number_status_null(list_a, &rotation_logic);
	while (step)
	{
		if (rotation_logic == 0)
			ra_four(&list_a);
		else
			rra_four(&list_a);
		step--;
	}
}
