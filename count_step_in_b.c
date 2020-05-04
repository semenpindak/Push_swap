/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_step_in_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:17:41 by semen             #+#    #+#             */
/*   Updated: 2020/04/18 16:51:44 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_next_number_left(t_number *list_b)
{
    list_b = list_b->prev;
    return (list_b->n);
}

static int check_next_number_left_add(t_number *list_b)
{
    list_b = list_b->next;
    return (list_b->n);
}

static int count_to_range_left(t_number *list_b, int max, int min)
{
    int count;

    count = 0;
    while (list_b)
    {
        list_b = list_b->prev;
        if (max == list_b->n)
        {
            if (min == check_next_number_left(list_b))
                return (count);
            if (min == check_next_number_left_add(list_b))
                return (count);
        }
        count++;
    }
    printf("count_number_left = %d\n", count);
    return (-1);
}

static int find_middle_number_left(t_number *list_a, t_number *list_b)
{
    int min;
    int max;
    int middle;
    int n;

    min = -2147483647;
    max = 2147483647;
    middle = list_a->n;
    n = list_b->n;
    while (list_b)
    {
        if (list_b->n < max && list_b->n > middle)
            max = list_b->n;
        if (list_b->n > min && list_b->n < middle)
            min = list_b->n;
        list_b = list_b->prev;
        if (n == list_b->n)
            break;
    }
    printf("left - max = %d min = %d\n", max, min);
    return (count_to_range_left(list_b, max, min));
}


static int find_max_number_left(t_number *list_b, int *i)
{
    int max;
    int count;

    max = list_b->n;
    count = 0;
    int n = list_b->n;
    while(list_b)
    {
        if (list_b->prev != NULL)
        {
            list_b = list_b->prev;
            count++;
        }
        if (list_b->n > max)
        {
            max = list_b->n;
            *i = count;
        }
        if (n == list_b->n)
            break;
    }
    // printf("find_max_number_left = %d\n", max);
    return (max);
}

static int find_min_number_left(t_number *list_b, int *i)
{
    int min;
    int count;

    min = list_b->n;
    count = 0;
    int n = list_b->n;
    while(list_b)
    {
        if (list_b->n < min)
        {
            min = list_b->n;
            *i = --count;
        }
        if (list_b->prev != NULL)
        {
            list_b = list_b->prev;
            count++;
        }
        if (n == list_b->n)
            break;
    }
    // printf("find_min_number_left = %d\n", min);
    return (min);
}

static int check_next_number_right(t_number *list_b)
{
    list_b = list_b->next;
    return (list_b->n);
}

static int check_next_number_right_add(t_number *list_b)
{
    list_b = list_b->prev;
    return (list_b->n);
}

static int count_to_range_right(t_number *list_b, int max, int min)
{
    int count;

    count = 0;
    while (list_b)
    {
        if (max == list_b->n)
        {
            if (min == check_next_number_right(list_b))
                return (++count);
            if (min == check_next_number_right_add(list_b))
                return (count);
        }
        list_b = list_b->next;
        count++;
    }
    printf("count_number_right = %d\n", count);
    return (-1);
}

static int find_middle_number_right(t_number *list_a, t_number *list_b)
{
    int min;
    int max;
    int middle;
    int n;

    min = -2147483647;
    max = 2147483647;
    middle = list_a->n;
    n = list_b->n;
    while (list_b)
    {
        if (list_b->n < max && list_b->n > middle)
            max = list_b->n;
        if (list_b->n > min && list_b->n < middle)
            min = list_b->n;
        list_b = list_b->next;
        if (n == list_b->n)
            break;
    }
    printf("right - max = %d min = %d\n", max, min);
    return (count_to_range_right(list_b, max, min));
}


static int find_max_number_right(t_number *list_b, int *i)
{
    int max;
    int count;

    max = list_b->n;
    count = 0;
    int n = list_b->n;
    while(list_b)
    {
        if (list_b->next != NULL)
        {
            list_b = list_b->next;
            count++;
        }
        if (list_b->n > max)
        {
            max = list_b->n;
            *i = count;
        }
        if (n == list_b->n)
            break;
    }
    // printf("find_max_number_right = %d\n", max);
    return (max);
}

static int find_min_number_right(t_number *list_b, int *i)
{
    int min;
    int count;

    min = list_b->n;
    count = 0;
    int n = list_b->n;
    while(list_b)
    {
        count++;
        if (list_b->n < min)
        {
            min = list_b->n;
            *i = count;
        }
        if (list_b->next != NULL)
            list_b = list_b->next;
        if (n == list_b->n)
            break;
    }
    // printf("find_min_number_right = %d\n", min);
    return (min);
}


static int step_left(t_number *list_a, t_number *list_b)
{
    int a;
    int i;
    int x;

    a = list_a->n;
    x = 0;
    i = 0;
    if (a > (x = find_max_number_left(list_b, &i)))
        return (i);
    if (a < (x = find_min_number_left(list_b, &i)))
        return (i);

    // printf("step_right = %d", count);
    // printf("step_right = %d", a);
    return (find_middle_number_left(list_a, list_b));
}

static int step_right(t_number *list_a, t_number *list_b)
{
    int a;
    int i;
    int x;

    a = list_a->n;
    x = 0;
    i = 0;
    if (a > (x = find_max_number_right(list_b, &i)))
        return (i);
    if (a < (x = find_min_number_right(list_b, &i)))
        return (i);

    // printf("step_right = %d", count);
    // printf("step_right = %d", a);
    return (find_middle_number_right(list_a, list_b));
}

int count_step_in_b(t_number *list_a, t_number *list_b, int *logic)
{
    int count_l;
    int count_r;
    int rez = 0;

    count_l = step_left(list_a, list_b);
    printf("count_l = %d\n", count_l);
    count_r = step_right(list_a, list_b);
    printf("count_r = %d\n", count_r);
    // printf("a = %d\n", a);
    // printf("b = %d\n", b);
    if (count_l > count_r)
    {
        rez = count_r;
        *logic = 0;
    }
    else
    {
        rez = count_l;
        *logic = 1;
    }
    return (rez);
}
