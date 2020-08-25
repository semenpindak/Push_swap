/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_upten_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:04:43 by calpha            #+#    #+#             */
/*   Updated: 2020/08/25 05:38:20 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_max_number(t_number *list_b)
{
	int max;
	int n;

	max = list_b->n;
	n = list_b->n;
	while(list_b)
	{
		list_b = list_b->next;
		if (list_b->n > max)
			max = list_b->n;
		if (n == list_b->n)
			break;
	}
	return (max);
}

static int find_min_number(t_number *list_b)
{
	int min;
	int n;

	min = list_b->n;
	n = list_b->n;
	while(list_b)
	{
		list_b = list_b->next;
		if (list_b->n < min)
			min = list_b->n;
		if (n == list_b->n)
			break;
	}
	return (min);
}

static int sorting_check(t_number *list_a, int min, int n)
{
	int current;

	while (list_a)
	{
		if (list_a->n == min)
			break;
		list_a = list_a->next;
	};
	n--;
	while (list_a)
	{
		current = list_a->n;
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

static int check_next_num(t_number *list_a, int current, int max, int min)
{
	list_a = list_a->next;
	if (current == max && list_a->n == min)
		return (0);
	if (list_a->n < current)
		return(1);
	else
		return (0);
	return (-1);
}

static int check_next_num_two(t_number **list_a, int current, int max, int min)
{
	*list_a = (*list_a)->next;
	if (current == max && (*list_a)->n == min)
	{
		*list_a = (*list_a)->prev;
		return (0);
	}
	if ((*list_a)->n < current)
	{
		*list_a = (*list_a)->prev;
		return(1);
	}
	else
	{
		*list_a = (*list_a)->prev;
		return (0);
	}
	return (-1);
}

static int count_step_sa_right(t_number **list_a, int max, int min)
{
	int n;
	int count;
	int check;
	int current;

	n = (*list_a)->n;
	count = 0;
	current = 0;
	while (*list_a)
	{
		current = (*list_a)->n;
		check = check_next_num_two(list_a, current, max, min);
		if (check == 1)
			return (count);
		*list_a = (*list_a)->next;
		count++;
		if (n == (*list_a)->n)
			break;
	}
	return (-1);
}

static int count_step_sa_left(t_number **list_a, int max, int min)
{
	int n;
	int count;
	int check;
	int current;

	n = (*list_a)->n;
	count = 0;
	current = 0;
	while (*list_a)
	{
		current = (*list_a)->n;
		check = check_next_num_two(list_a, current, max, min);
		if (check == 1)
			return (count);
		*list_a = (*list_a)->prev;
		count++;
		if (n == (*list_a)->n)
			break;
	}
	return (-1);
}

static int rotation(t_number **list_a, int *rotation_logic, int max, int min)
{
	(*list_a)->ra = count_step_sa_right(list_a, max, min);
	(*list_a)->la = count_step_sa_left(list_a, max, min);
	if ((*list_a)->ra < (*list_a)->la)
	{
		*rotation_logic = 1;
		return ((*list_a)->la);
	}
	else
	{
		*rotation_logic = 0;
		return ((*list_a)->la);
	}
	return (-1);
}

int centering_stack_ten(t_number **list_a, t_number **list_b, int max, int min)
{
	int i;
	int step;
	int rotation_logic;

	i = 0;
	step = rotation(list_a, &rotation_logic, max, min);
	while (step)
	{
		if (rotation_logic == 0)
		{
			ra_three(&list_a);
			show_me_two(list_a, list_b);
			i++;
		}
		else
		{
			rra_three(&list_a);
			show_me_two(list_a, list_b);
			i++;
		}
		step--;
	}
	return (i);
}


void sorting_upten_num(t_number *list_a, t_number *list_b)
{
	int n;
	int max;
	int min;
	int current;
	int a;
	int check = 0;
	int i;

	current = 0;
	i = 0;

	n = count_list(list_a);
	min = find_min_number(list_a);
	max = find_max_number(list_a);
	printf("min = %d, max = %d\n", min, max);

	show_me(list_a, list_b);

	while(list_a)
	{
		show_me(list_a, list_b);
		current = list_a->n;
		i += centering_stack_ten(&list_a, &list_b, max, min);


		printf("list_a->ra = %d| list_a->la = %d\n", list_a->ra, list_a->la);
		check = check_next_num(list_a, current, max, min);
		printf("check = %d\n", check);
		if (check == 1)
		{
			sa(list_a);
			i++;
		}
		show_me(list_a, list_b);

		a = sorting_check(list_a, min, n);
		printf("sorting_check = %d\n", a);

		if (a == 1)
			break;


		// usleep(3000000);
		ra(&list_a);
		i++;

		show_me(list_a, list_b);
		printf("\n");
	}


	// while(a)
    // {
    //     printf("(list_a-> = status) = %d | count list = %d | list_a->n = %d \n", list_a->status, n, list_a->n);
    //     list_a = list_a->next;
    //     a--;
    // }
	// list_b = NULL;

	printf("i = %d\n", i);
	i += centering_stack_a(&list_a, &list_b);
	show_me(list_a, list_b);
	printf("i = %d\n", i);
}



