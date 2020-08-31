/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centering_stack_regular_kv.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 20:38:32 by oem               #+#    #+#             */
/*   Updated: 2020/08/31 00:02:13 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_min_number_left(t_number **list_b, int *i)
{
	int min;
	int count;
	int n;

	min = 2147483647;
	count = 0;
	n = (*list_b)->n;
	while (*list_b)
	{
		if ((*list_b)->n < min)
		{
			min = (*list_b)->n;
			*i = count;
		}
		*list_b = (*list_b)->prev;
		count++;
		if (n == (*list_b)->n)
			break ;
	}
}

static void	find_min_number_right(t_number **list_b, int *i)
{
	int min;
	int count;
	int n;

	min = 2147483647;
	count = 0;
	n = (*list_b)->n;
	while (*list_b)
	{
		if ((*list_b)->n < min)
		{
			min = (*list_b)->n;
			*i = count;
		}
		*list_b = (*list_b)->next;
		count++;
		if (n == (*list_b)->n)
			break ;
	}
}

static int	find_min_number_stack_b(t_number **list_b, int *rotation_logic)
{
	int a;
	int b;

	a = 0;
	b = 0;
	find_min_number_left(list_b, &a);
	find_min_number_right(list_b, &b);
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

static void	find_min_number_left_stack_a(t_number **list_a, int *i)
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

static void	find_min_number_right_stack_a(t_number **list_a, int *i)
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

static int	find_min_number_stack_a(t_number **list_a, int *rotation_logic)
{
	int a;
	int b;

	a = 0;
	b = 0;
	find_min_number_left_stack_a(list_a, &a);
	find_min_number_right_stack_a(list_a, &b);
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

int			centering_stack_regular_kv(t_number **list_a, t_number **list_b, int i)
{
	int step_a = 0;
	int step_b = 0;
	int rotation_logic_a;
	int rotation_logic_b;
	int sum = 0;
	int twist = 0;

	step_a = find_min_number_stack_a(list_a, &rotation_logic_a);
	step_b = find_min_number_stack_b(list_b, &rotation_logic_b);
	if (rotation_logic_a == rotation_logic_b)
	{
		if (step_a == step_b)
		{
			while(step_a)
			{
				if (rotation_logic_a == 0)
				{
					ft_printf("exec ");
					rr_three(&list_a, &list_b);
					i++;
					ft_printf("move = %d\n", i);
					show_me_two(list_a, list_b);
					usleep(3000000);
					system("clear");
				}
				else
				{
					ft_printf("exec ");
					rrr_three(&list_a, &list_b);
					i++;
					ft_printf("move = %d\n", i);
					show_me_two(list_a, list_b);
					usleep(3000000);
					system("clear");
				}
				step_a--;
			}
		}
		if (step_a > step_b)
		{
			sum = step_b;
			twist = step_a - step_b;
			while(sum)
			{
				if (rotation_logic_a == 0)
				{
					ft_printf("exec ");
					rr_three(&list_a, &list_b);
					i++;
					ft_printf("move = %d\n", i);
					show_me_two(list_a, list_b);
					usleep(3000000);
					system("clear");
				}
				else
				{
					ft_printf("exec ");
					rrr_three(&list_a, &list_b);
					i++;
					ft_printf("move = %d\n", i);
					show_me_two(list_a, list_b);
					usleep(3000000);
					system("clear");
				}
				sum--;
			}
			while(twist)
			{
				if (rotation_logic_a == 0)
				{
					ft_printf("exec ");
					ra_three(&list_a);
					i++;
					ft_printf("move = %d\n", i);
					show_me_two(list_a, list_b);
					usleep(3000000);
					system("clear");
				}
				else
				{
					ft_printf("exec ");
					rra_three(&list_a);
					i++;
					ft_printf("move = %d\n", i);
					show_me_two(list_a, list_b);
					usleep(3000000);
					system("clear");
				}
				twist--;
			}
		}
		else
		{
			sum = step_a;
			twist = step_b - step_a;
			while(sum)
			{
				if (rotation_logic_a == 0)
				{
					ft_printf("exec ");
					rr_three(&list_a, &list_b);
					i++;
					ft_printf("move = %d\n", i);
					show_me_two(list_a, list_b);
					usleep(3000000);
					system("clear");
				}
				else
				{
					ft_printf("exec ");
					rrr_three(&list_a, &list_b);
					i++;
					ft_printf("move = %d\n", i);
					show_me_two(list_a, list_b);
					usleep(3000000);
					system("clear");
				}
				sum--;
			}
			while(twist)
			{
				if (rotation_logic_b == 0)
				{
					ft_printf("exec ");
					rb_three(&list_b);
					i++;
					ft_printf("move = %d\n", i);
					show_me_two(list_a, list_b);
					usleep(3000000);
					system("clear");
				}
				else
				{
					ft_printf("exec ");
					rrb_three(&list_b);
					i++;
					ft_printf("move = %d\n", i);
					show_me_two(list_a, list_b);
					usleep(3000000);
					system("clear");
				}
				twist--;
			}
		}
	}
	else
	{
		while(step_a)
		{
			if (rotation_logic_a == 0)
			{
				ft_printf("exec ");
				ra_three(&list_a);
				i++;
				ft_printf("move = %d\n", i);
				show_me_two(list_a, list_b);
				usleep(3000000);
				system("clear");
			}
			else
			{
				ft_printf("exec ");
				rra_three(&list_a);
				i++;
				ft_printf("move = %d\n", i);
				show_me_two(list_a, list_b);
				usleep(3000000);
				system("clear");
			}
			step_a--;
		}
		while(step_b)
		{
			if (rotation_logic_b == 0)
			{
				ft_printf("exec ");
				rb_three(&list_b);
				i++;
				ft_printf("move = %d\n", i);
				show_me_two(list_a, list_b);
				usleep(3000000);
				system("clear");
			}
			else
			{
				ft_printf("exec ");
				rrb_three(&list_b);
				i++;
				ft_printf("move = %d\n", i);
				show_me_two(list_a, list_b);
				usleep(3000000);
				system("clear");
			}
		step_b--;
		}
	}
	return (i);
}
