/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centering_stack_regular.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:07:27 by calpha            #+#    #+#             */
/*   Updated: 2020/08/15 20:48:10 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_min_number_left(t_number **list_b, int *i)
{
    int min;
    int count;

    min = (*list_b)->n;
    count = 0;
    int n = (*list_b)->n;
    while(*list_b)
    {
		if ((*list_b)->n < min)
        {
            min = (*list_b)->n;
            *i = count;
        }
        if ((*list_b)->next != NULL)
        {
            *list_b = (*list_b)->prev;
            count++;
        }
        if (n == (*list_b)->n)
            break;
    }
    // printf("find_max_number_left = %d\n", max);
    return (min);
}

static int find_min_number_right(t_number **list_b, int *i)
{
    int min;
    int count;
	int n;

    min = (*list_b)->n;
    count = 0;
	n = (*list_b)->n;
    while(*list_b)
    {
		if ((*list_b)->n < min)
        {
            min = (*list_b)->n;
            *i = count;
        }
        if ((*list_b)->next != NULL)
        {
            *list_b = (*list_b)->next;
            count++;
        }
        if (n == (*list_b)->n)
            break;
    }
    // printf("find_max_number_right = %d\n", max);
    return (min);
}

static int find_min_number(t_number **list_b, int *rotation_logic)
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

int centering_stack_regular(t_number **list_a, t_number **list_b)
{
    int i = 0;
	int step = 0;
	int rotation_logic;

	step = find_min_number(list_b, &rotation_logic);
    // printf("z = %d, r = %d\n", step, rotation_logic);
    while(step)
    {
        if (rotation_logic == 0)
        {
            ra_three(&list_b);
            show_me_two(list_a, list_b);
            i++;
        }
        else
        {
            rra_three(&list_b);
            show_me_two(list_a, list_b);
            i++;
        }
        step--;
        show_me_two(list_a, list_b);
        // usleep(500000);
    }
    return (i);
}
