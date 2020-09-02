/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_step_in_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:15:01 by oem               #+#    #+#             */
/*   Updated: 2020/09/02 22:51:16 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_number_left(t_number **list_a, int *i) //complete
{
	int max;
	int count;
	int n;

	max = (*list_a)->n;
	count = 0;
	n = (*list_a)->n;
	while (*list_a)
	{
		if ((*list_a)->prev != NULL)
			*list_a = (*list_a)->prev;
		if ((*list_a)->n >= max)
		{
			max = (*list_a)->n;
			*i = count;
		}
		if (n == (*list_a)->n)
			break ;
		count++;
	}
	// printf("max = %d, *i = %d\n", max, *i);
	// usleep(3000000);
	return (max);
}

static int	find_min_number_left(t_number **list_a, int *i) //comlete
{
	int min;
	int count;
	int n;

	min = (*list_a)->n;
	count = 0;
	n = (*list_a)->n;
	while (*list_a)
	{
		if ((*list_a)->prev != NULL)
			*list_a = (*list_a)->prev;
		if ((*list_a)->n < min)
		{
			min = (*list_a)->n;
			*i = count;
		}
		if (n == (*list_a)->n)
			break ;
		count++;
	}
	// printf("min = %d, *i = %d\n", min, *i);
	// usleep(3000000);
	return (min);
}

static int	find_middle_number_left(t_number **list_a, t_number **list_b) //complete
{
	int max;
	int middle;
	int n;
	int i;
	int count;

	max = 2147483647;
	middle = (*list_b)->n;
	n = (*list_a)->n;
	count = 0;
	while (*list_b)
	{
		if ((*list_a)->n > middle && (*list_a)->n < max)
		{
			max = (*list_a)->n;
			i = count;
		}
		*list_a = (*list_a)->prev;
		if (n == (*list_a)->n)
			break ;
		count++;
	}
	// printf("middle: max = %d, i = %d\n", max, i);
	return (i);
}

static int	find_max_number_right(t_number **list_a, int *i)
{
	int max;
	int count;
	int n;

	max = (*list_a)->n;
	count = 1;
	n = (*list_a)->n;
	while (*list_a)
	{
		if ((*list_a)->n >= max)
		{
			max = (*list_a)->n;
			*i = count;
		}
		if ((*list_a)->next != NULL)
		{
			*list_a = (*list_a)->next;
			count++;
		}
		if (n == (*list_a)->n)
			break ;
	}
	// printf("\n");
	// printf("max = %d, *i = %d\n", max, *i);
	return (max);
}

static int	find_min_number_right(t_number **list_a, int *i)
{
	int min;
	int count;
	int n;

	min = (*list_a)->n;
	count = 0;
	n = (*list_a)->n;
	while (list_a)
	{
		if ((*list_a)->next != NULL)
		{
			*list_a = (*list_a)->next;
			count++;
		}
		if ((*list_a)->n < min)
		{
			min = (*list_a)->n;
			*i = count;
		}
		if (n == (*list_a)->n)
			break ;
	}
	// printf("min = %d, *i = %d\n", min, *i);
	return (min);
}

static int	find_middle_number_right(t_number **list_a, t_number **list_b)
{
	int max;
	int middle;
	int n;
	int i;
	int count;

	max = 2147483647;
	middle = (*list_b)->n;
	n = (*list_a)->n;
	count = 0;
	while (*list_a)
	{
		if ((*list_a)->n > middle && (*list_a)->n < max)
		{
			max = (*list_a)->n;
			i = count;
		}
		*list_a = (*list_a)->next;
		if (n == (*list_a)->n)
			break ;
		count++;
	}
	// printf("middle: max = %d, i = %d\n", max, i);
	return (i);
}

static int	step_left(t_number **list_a, t_number **list_b)
{
	int a;
	int i;
	int x;
	int y;

	a = (*list_b)->n;
	i = 0;
	x = 0;
	if (a > (x = find_max_number_left(list_a, &i)))
		return (i);
	if (a < (x = find_min_number_left(list_a, &i)))
		return (i);
	y = find_middle_number_left(list_a, list_b);
	return (y);
}

static int	step_right(t_number **list_a, t_number **list_b)
{
	int a;
	int i;
	int x;
	int y = 0;

	a = (*list_b)->n;
	i = 0;
	x = 0;
	if (a > (x = find_max_number_right(list_a, &i)))
		return (i);
	if (a < (x = find_min_number_right(list_a, &i)))
		return (i);
	y = find_middle_number_right(list_a, list_b);
	return (y);
}

void		count_step_in_a(t_number **list_a, t_number **list_b)
{
	(*list_b)->rb = step_left(list_a, list_b);
	(*list_b)->lb = step_right(list_a, list_b);
}

