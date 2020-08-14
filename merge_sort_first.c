/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 00:01:01 by semen             #+#    #+#             */
/*   Updated: 2020/08/07 16:28:57 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_stack_a_one(t_number **list_a)
{
    int num;
	num = (*list_a)->n;
    // printf("%d\n", list_b->n);
	while (*list_a)
	{
		if ((*list_a)->next != NULL)
        {
            if((*list_a)->status == 1)
                return (1);
            else
                *list_a = (*list_a)->next;
        }
		if (num == (*list_a)->n)
			return (0);
	}
    return (0);
}

static int count_list(t_number **list_b)
{
	int num;
	num = (*list_b)->n;
	int count;

	count = 0;
	while (*list_b)
	{
		if ((*list_b)->next != NULL)
			*list_b = (*list_b)->next;
		count++;
		if (num == (*list_b)->n)
			break;
	}
	return (count);
}

static int find_max_number_left(t_number **list_b, int *i)
{
    int max;
    int count;

    max = (*list_b)->n;
    count = 0;
    int n = (*list_b)->n;
    while(*list_b)
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
            break;
    }
    // printf("find_max_number_left = %d\n", max);
    return (max);
}

static int find_max_number_right(t_number **list_b, int *i)
{
    int max;
    int count;

    max = (*list_b)->n;
    count = 0;
    int n = (*list_b)->n;
    while(*list_b)
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
            break;
    }
    // printf("find_max_number_right = %d\n", max);
    return (max);
}

static int find_max_number(t_number **list_b, int *rotation_logic)
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


void	merge_sort_first(t_number **list_a, t_number **list_b)
{
    int x = 0;
    int step = 0;
    int rotation_logic;
    int n;

    x = check_stack_a_one(list_a);
    // printf("x = %d\n", x);
    // printf("%d\n", (*list_b)->n);
	if (x == 0)
        step = find_max_number(list_b, &rotation_logic);
    // printf("z = %d, r = %d\n", step, rotation_logic);
    while(step)
    {
        if (rotation_logic == 0)
        {
            ra_three(&list_b);
            show_me_two(list_a, list_b);
                // i++;
        }
        else
        {
            rra_three(&list_b);
            show_me_two(list_a, list_b);
                // i++;
        }
        step--;
        usleep(3000000);
        show_me_two(list_a, list_b);
    }

    n = count_list(list_b);
    //  printf("n = %d\n", n);
    //  show_me_two(list_a, list_b);
    while (n)
    {
        pa_three(&list_a, &list_b);
        usleep(1000000);
        show_me_two(list_a, list_b);
        n--;
    }
}
