/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 14:26:34 by semen             #+#    #+#             */
/*   Updated: 2020/08/23 18:59:59 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void change_status_one(t_number *list_b)
{
    int num;
	num = list_b->n;
    int count = 0;

	while (list_b)
	{
        list_b->status = 1;
        count++;
		list_b = list_b->next;
		if (num == list_b->n)
			break;
	}
    // printf("change_status_one = %d\n", count);
    // usleep(3000000);
}

// void count_status(t_number *list_a)
// {
//     int n = list_a->n;
//     int count = 0;
//     while(list_a)
//     {
//         if (list_a->status == 1)
//             count++;
//         list_a = list_a->next;
//         if (list_a->n == n)
//              break;
//     }
//     printf("count status= %d\n", count);
//     usleep(3000000);
// }

static int calculation_quantity(int count_assist, int n)
{
    int q;
    int quantity;
    int ret;

    q = 0;
    quantity = 0;
    ret = 0;
    if (n <= 100)
        q = 2;
    else
        q = 5;
    quantity = n / q;
    if (count_assist < q)
        return (quantity);
    else
    {
        count_assist--;
        ret = n - count_assist * quantity;
        return (ret);
    }
    return (-1);
}

void timsort(t_number *list_a, t_number *list_b)
{
    int count = 0;
    int q = 0;
    int n = 0;
    int quantity = 0;
    int count_assist = 1;

    if ((n = count_list(list_a)) <= 100)
        q = 2;
    else
        q = 5;

    quantity = calculation_quantity(count_assist, n);
    count = insertion_sort_first(&list_a, &list_b, quantity);
    change_status_one(list_b);
    count += centering_stack_first(&list_a, &list_b);
    count += merge_sort_first(&list_a, &list_b);
    q--;
    while(q)
    {
        count_assist++;
        quantity = calculation_quantity(count_assist, n);
        count += insertion_sort_regular(&list_a, &list_b, quantity);
        change_status_one(list_b);
        count += centering_stack_regular(&list_a, &list_b);
        count += merge_sort_regular(&list_a, &list_b);
        q--;
    }
    count += centering_stack_regular_a(&list_a, &list_b);

    printf("%d\n", count);
    // while(n)
    // {
    //     printf("(list_a-> = status) = %d | count list = %d | list_a->n = %d \n", list_a->status, n, list_a->n);
    //     list_a = list_a->next;
    //     n--;
    //     if (list_a->n % 10 == 0)
    //         printf("__________________\n");
    // }
}
