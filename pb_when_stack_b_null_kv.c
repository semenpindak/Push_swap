/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_when_stack_b_null_kv.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 20:54:33 by oem               #+#    #+#             */
/*   Updated: 2020/08/30 23:58:40 by oem              ###   ########.fr       */
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

int			pb_when_stack_b_null_kv(t_number ***list_a, t_number ***list_b, int i)
{
	int step;
	int rotation_logic;

	step = find_number_status_null(list_a, &rotation_logic);
	while (step)
	{
		if (rotation_logic == 0)
		{
			ft_printf("exec ");
			ra_four(&list_a);
			i++;
			ft_printf("move = %d\n", i);
			show_me_three(list_a, list_b);
			usleep(3000000);
			system("clear");
		}
		else
		{
			ft_printf("exec ");
			rra_four(&list_a);
			i++;
			ft_printf("move = %d\n", i);
			show_me_three(list_a, list_b);
			usleep(3000000);
			system("clear");
		}
		step--;
	}
	return (i);
}
