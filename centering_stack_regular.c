/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centering_stack_regular.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:07:27 by calpha            #+#    #+#             */
/*   Updated: 2020/08/21 16:39:15 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void find_min_number_left(t_number **list_b, int *i)
{
    int min;
    int count;
    int n;

    min = 2147483647;
    count = 0;
    n = (*list_b)->n;
    while(*list_b)
    {
		if ((*list_b)->n < min)
        {
            min = (*list_b)->n;
            *i = count;
        }
        *list_b = (*list_b)->prev;
        count++;
        if (n == (*list_b)->n)
            break;
    }
}

static void find_min_number_right(t_number **list_b, int *i)
{
    int min;
    int count;
    int n;

    min = 2147483647;
    count = 0;
    n = (*list_b)->n;
    while(*list_b)
    {
		if ((*list_b)->n < min)
        {
            min = (*list_b)->n;
            *i = count;
        }
        *list_b = (*list_b)->next;
        count++;
        if (n == (*list_b)->n)
            break;
    }
}

static int find_min_number_stack_b(t_number **list_b, int *rotation_logic)
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

static void find_min_number_left_stack_a(t_number **list_a, int *i)
{
    int min;
    int count;
    int n;

    min = 2147483647;
    count = 0;
    n = (*list_a)->n;
    while(*list_a)
    {
		if ((*list_a)->n < min && (*list_a)->status == 1)
        {
            min = (*list_a)->n;
            *i = count;
        }
        *list_a = (*list_a)->prev;
        count++;
        if (n == (*list_a)->n)
            break;
    }
}

static void find_min_number_right_stack_a(t_number **list_a, int *i)
{
    int min;
    int count;
    int n;

    min = 2147483647;
    count = 0;
    n = (*list_a)->n;
    while(*list_a)
    {
		if ((*list_a)->n < min && (*list_a)->status == 1)
        {
            min = (*list_a)->n;
            *i = count;
        }
        *list_a = (*list_a)->next;
        count++;
        if (n == (*list_a)->n)
            break;
    }
}

static int find_min_number_stack_a(t_number **list_a, int *rotation_logic)
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

int centering_stack_regular(t_number **list_a, t_number **list_b)
{
    int i = 0;
	int step_a = 0;
    int step_b = 0;
	int rotation_logic_a;
    int rotation_logic_b;
    int sum = 0;
    int twist = 0;

    step_a = find_min_number_stack_a(list_a, &rotation_logic_a);
	step_b = find_min_number_stack_b(list_b, &rotation_logic_b);

    // printf("step_a = %d, step_b = %d\n", step_a, step_b);
    // printf("rotation_logic_a = %d, rotation_logic_b = %d\n", rotation_logic_a, rotation_logic_b);
    // usleep(2000000);
    // exit(0);
    if (rotation_logic_a == rotation_logic_b)
    {
        if (step_a == step_b)
        {
            while(step_a)
            {
                if (rotation_logic_a == 0)
                {
                    rr_three(&list_a, &list_b);
                    show_me_two(list_a, list_b);
                    i++;
                }
                else
                {
                    rrr_three(&list_a, &list_b);
                    show_me_two(list_a, list_b);
                    i++;
                }
                step_a--;
                // show_me_two(list_a, list_b);
                // usleep(3000000);
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
                    rr_three(&list_a, &list_b);
                    show_me_two(list_a, list_b);
                    i++;
                }
                else
                {
                    rrr_three(&list_a, &list_b);
                    show_me_two(list_a, list_b);
                    i++;
                }
                sum--;
                // show_me_two(list_a, list_b);
                // usleep(3000000);
            }
            while(twist)
            {
                if (rotation_logic_a == 0)
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
                twist--;
                // show_me_two(list_a, list_b);
                // usleep(3000000);
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
                    rr_three(&list_a, &list_b);
                    show_me_two(list_a, list_b);
                    i++;
                }
                else
                {
                    rrr_three(&list_a, &list_b);
                    show_me_two(list_a, list_b);
                    i++;
                }
                sum--;
        // show_me_two(list_a, list_b);
            // usleep(3000000);
            }
            while(twist)
            {
                if (rotation_logic_b == 0)
                {
                    rb_three(&list_b);
                    show_me_two(list_a, list_b);
                    i++;
                }
                else
                {
                    rrb_three(&list_b);
                    show_me_two(list_a, list_b);
                    i++;
                }
                twist--;
                // show_me_two(list_a, list_b);
                // usleep(3000000);
            }
        }
    }
    else
    {
        while(step_a)
        {
            if (rotation_logic_a == 0)
            {
                ra_three(&list_a);
                show_me_two(list_a, list_b);
                // usleep(1000000);
                i++;
            }
            else
            {
                rra_three(&list_a);
                show_me_two(list_a, list_b);
                // usleep(1000000);
                i++;
            }
            step_a--;
        }
        // usleep(500000);
        // show_me_two(list_a, list_b);
        while(step_b)
        {
            if (rotation_logic_b == 0)
            {
                rb_three(&list_b);
                show_me_two(list_a, list_b);
                // usleep(1000000);
                i++;
            }
            else
            {
                rrb_three(&list_b);
                show_me_two(list_a, list_b);
                // usleep(1000000);
                i++;
            }
        step_b--;
        }
    }
    // printf("z = %d, r = %d\n", step, rotation_logic);
    // exit(0);
    return (i);
}
