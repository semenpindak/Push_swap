/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ten_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 20:11:13 by oem               #+#    #+#             */
/*   Updated: 2020/10/06 15:10:43 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_max_number(t_num *list_b)
{
	int max;
	int n;

	max = list_b->n;
	n = list_b->n;
	while (list_b)
	{
		if (list_b->next != NULL)
			list_b = list_b->next;
		if (list_b->n > max)
			max = list_b->n;
		if (n == list_b->n)
			break ;
	}
	return (max);
}

static int find_min_number(t_num *list_b)
{
	int min;
	int n;

	min = list_b->n;
	n = list_b->n;
	while (list_b)
	{
		if (list_b->next != NULL)
			list_b = list_b->next;
		if (list_b->n < min)
			min = list_b->n;
		if (n == list_b->n)
			break ;
	}
	return (min);
}

static int check_next_num_two(t_num **list_a, int current, int max, int min)
{
	if ((*list_a)->next != NULL)
		*list_a = (*list_a)->next;
	if (current == max && (*list_a)->n == min)
	{
		if ((*list_a)->prev != NULL)
			*list_a = (*list_a)->prev;
		return (0);
	}
	if ((*list_a)->n < current)
	{
		if ((*list_a)->prev != NULL)
			*list_a = (*list_a)->prev;
		return (1);
	}
	else
	{
		if ((*list_a)->prev != NULL)
			*list_a = (*list_a)->prev;
		return (0);
	}
	return (-1);
}

static int count_step_sa_right(t_num **list_a, int max, int min)
{
	int n;
	int count;
	int check;
	int current;
	int i;
	int flag;

	n = (*list_a)->n;
	count = 0;
	current = 0;
	i = 0;
	flag = 0;
	while (*list_a)
	{
		current = (*list_a)->n;
		check = check_next_num_two(list_a, current, max, min);
		if (check == 1 && flag == 0)
		{
			i = count;
			flag = 1;
		}
		if ((*list_a)->next != NULL)
			*list_a = (*list_a)->next;
		count++;
		if (n == (*list_a)->n)
			break ;
	}
	return (i);
}

static int count_step_sa_left(t_num **list_a, int max, int min)
{
	int n;
	int count;
	int check;
	int current;
	int i;
	int flag;

	n = (*list_a)->n;
	count = 0;
	current = 0;
	i = 0;
	flag = 0;
	while (*list_a)
	{
		current = (*list_a)->n;
		check = check_next_num_two(list_a, current, max, min);
		if (check == 1 && flag == 0)
		{
			i = count;
			flag = 1;
		}
		if ((*list_a)->prev != NULL)
			*list_a = (*list_a)->prev;
		count++;
		if (n == (*list_a)->n)
			break ;
	}
	return (i);
}

static int rotation(t_num **list_a, int *rotation_logic, int max, int min)
{
	(*list_a)->ra = count_step_sa_right(list_a, max, min);
	(*list_a)->la = count_step_sa_left(list_a, max, min);
	if ((*list_a)->ra < (*list_a)->la)
	{
		*rotation_logic = 0;
		return ((*list_a)->ra);
	}
	else
	{
		*rotation_logic = 1;
		return ((*list_a)->la);
	}
	return (-1);
}

static void centering_stack_ten(t_num **list_a, t_num **list_b, int max, int min, t_key *bonus)
{
	int step;
	int rotation_logic;

	step = rotation(list_a, &rotation_logic, max, min);
	while (step)
	{
		if (rotation_logic == 0)
		{
			ra(&list_a, bonus);
			debug_print_two(list_a, list_b, bonus);
		}
		else
		{
			rra(&list_a, bonus);
			debug_print_two(list_a, list_b, bonus);
		}
		step--;
	}
}

static int checking_stack_sorted(t_num *list_a, int min, int n)
{
	int current;

	while (list_a)
	{
		if (list_a->n == min)
			break ;
		if (list_a->next != NULL)
			list_a = list_a->next;
	};
	n--;
	while (list_a)
	{
		current = list_a->n;
		if (list_a->prev != NULL)
			list_a = list_a->next;
		if (current < list_a->n)
		{
			n--;
			if (n == 0)
				return (1);
		}
		else
			return (0);
	}
	return (-1);
}

static void start(t_num **list_a, t_num **list_b, t_key *bonus)
{
	if (*list_b == NULL)
	{
		pb(&list_a, &list_b, bonus);
		(*list_b)->status = 1;
		debug_print_two(list_a, list_b, bonus);
	}
}

void sort_ten_num(t_num *list_a, t_num *list_b, t_key *bonus)
{
	int n;
	int max;
	int min;

	if (count_list(list_a) > 3)
		start(&list_a, &list_b, bonus);
	n = count_list(list_a);
	min = find_min_number(list_a);
	max = find_max_number(list_a);
	while (list_a)
	{
		centering_stack_ten(&list_a, &list_b, max, min, bonus);
		if (checking_stack_sorted(list_a, min, n) == 0)
		{
			sa(list_a, bonus);
			debug_print(list_a, list_b, bonus);
		}
		else
			break ;
	}
	insertsort_finish(&list_a, &list_b, bonus);
	centering_stack_finish(&list_a, &list_b, bonus);
}
