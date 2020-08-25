/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_step_in_b_for_struct_three_regular.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:23:17 by semen             #+#    #+#             */
/*   Updated: 2020/08/25 15:43:29 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_next_number_left(t_number **list_b)
{
	int a;

	a = 0;
	*list_b = (*list_b)->prev;
	a = (*list_b)->n;
	*list_b = (*list_b)->next;
	return (a);
}

static int	check_next_number_left_add(t_number **list_b)
{
	int a;

	a = 0;
	*list_b = (*list_b)->next;
	a = (*list_b)->n;
	*list_b = (*list_b)->prev;
	return (a);
}

static int	count_to_range_left(t_number **list_b, int max, int min, int **c)
{
	int count;

	count = 0;
	while (*list_b)
	{
		if (max == (*list_b)->n)
		{
			if (min == check_next_number_left(list_b))
				return (count);
			if (min == check_next_number_left_add(list_b))
				return (count);
		}
		*list_b = (*list_b)->prev;
		count++;
		**c = count;
	}
	return (-1);
}

static int	find_middle_number_left(t_number **list_a, t_number **list_b, int *c)
{
	int min;
	int max;
	int middle;
	int n;

	min = -2147483647;
	max = 2147483647;
	middle = (*list_a)->n;
	n = (*list_b)->n;
	while (*list_b)
	{
		if ((*list_b)->n > middle && (*list_b)->n < max)
			max = (*list_b)->n;
		if ((*list_b)->n > min && (*list_b)->n < middle)
			min = (*list_b)->n;
		*list_b = (*list_b)->prev;
		if (n == (*list_b)->n)
			break ;
	}
	return (count_to_range_left(list_b, max, min, &c));
}

static int	find_max_number_left(t_number **list_b, int *i)
{
	int max;
	int count;
	int n;

	max = (*list_b)->n;
	count = 1;
	n = (*list_b)->n;
	while (*list_b)
	{
		if ((*list_b)->prev != NULL)
		{
			*list_b = (*list_b)->prev;
			count++;
		}
		if ((*list_b)->n >= max)
			max = (*list_b)->n;
		if (n == (*list_b)->n)
			break ;
		*i = count;
	}
	return (max);
}

static int	find_min_number_left(t_number **list_b, int *i)
{
	int min;
	int count;
	int n;

	min = (*list_b)->n;
	count = 0;
	n = (*list_b)->n;
	while (*list_b)
	{
		if ((*list_b)->prev != NULL)
		{
			*list_b = (*list_b)->prev;
			count++;
		}
		if ((*list_b)->n < min)
		{
			min = (*list_b)->n;
			*i = count;
		}
		if (n == (*list_b)->n)
			break ;
	}
	return (min);
}

static int	check_next_number_right(t_number **list_b)
{
	int a;

	a = 0;
	*list_b = (*list_b)->next;
	a = (*list_b)->n;
	*list_b = (*list_b)->prev;
	return (a);
}

static int	check_next_number_right_add(t_number **list_b)
{
	int a;

	a = 0;
	*list_b = (*list_b)->prev;
	a = (*list_b)->n;
	*list_b = (*list_b)->next;
	return (a);
}

static int	count_to_range_right(t_number **list_b, int max, int min, int **c)
{
	int count;

	count = 0;
	while (*list_b)
	{
		if (max == (*list_b)->n)
		{
			if (min == check_next_number_right(list_b))
				return (count);
			if (min == check_next_number_right_add(list_b))
				return (count);
		}
		*list_b = (*list_b)->next;
		count++;
		**c = count;
	}
	return (-1);
}

static int	find_middle_number_right(t_number **list_a, t_number **list_b, int *c)
{
	int min;
	int max;
	int middle;
	int n;

	min = -2147483647;
	max = 2147483647;
	middle = (*list_a)->n;
	n = (*list_b)->n;
	while (*list_b)
	{
		if ((*list_b)->n < max && (*list_b)->n > middle)
			max = (*list_b)->n;
		if ((*list_b)->n > min && (*list_b)->n < middle)
			min = (*list_b)->n;
		*list_b = (*list_b)->next;
		if (n == (*list_b)->n)
			break ;
	}
	return (count_to_range_right(list_b, max, min, &c));
}

static int	find_max_number_right(t_number **list_b, int *i)
{
	int max;
	int count;
	int n;

	max = (*list_b)->n;
	count = 1;
	n = (*list_b)->n;
	while (*list_b)
	{
		if ((*list_b)->n >= max)
		{
			max = (*list_b)->n;
			*i = count;
		}
		if ((*list_b)->next != NULL)
		{
			*list_b = (*list_b)->next;
			count++;
		}
		if (n == (*list_b)->n)
			break ;
	}
	return (max);
}

static int	find_min_number_right(t_number **list_b, int *i)
{
	int min;
	int count;
	int n;

	min = (*list_b)->n;
	count = 0;
	n = (*list_b)->n;
	while (list_b)
	{
		if ((*list_b)->next != NULL)
		{
			*list_b = (*list_b)->next;
			count++;
		}
		if ((*list_b)->n < min)
		{
			min = (*list_b)->n;
			*i = count;
		}
		if (n == (*list_b)->n)
			break ;
	}
	return (min);
}

static int	step_left(t_number **list_a, t_number **list_b)
{
	int a;
	int i;
	int x;
	int y;
	int c;

	a = (*list_a)->n;
	i = 0;
	x = 0;
	c = 0;
	if (a > (x = find_max_number_left(list_b, &i)))
		return (i);
	if (a < (x = find_min_number_left(list_b, &i)))
		return (i);
	y = find_middle_number_left(list_a, list_b, &c);
	while (c)
	{
		*list_b = (*list_b)->next;
		c--;
	}
	return (y);
}

static int	step_right(t_number **list_a, t_number **list_b)
{
	int a;
	int i;
	int x;
	int y;
	int c;

	a = (*list_a)->n;
	i = 0;
	x = 0;
	c = 0;
	if (a > (x = find_max_number_right(list_b, &i)))
		return (i);
	if (a < (x = find_min_number_right(list_b, &i)))
		return (i);
	y = find_middle_number_right(list_a, list_b, &c);
	while (c)
	{
		*list_b = (*list_b)->prev;
		c--;
	}
	return (y);
}

void		count_step_in_b_for_struct_three_regular(t_number **list_a, t_number **list_b)
{
	(*list_a)->rb = step_left(list_a, list_b);
	(*list_a)->lb = step_right(list_a, list_b);
}

