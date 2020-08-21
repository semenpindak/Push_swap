/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 14:26:34 by semen             #+#    #+#             */
/*   Updated: 2020/08/21 20:06:12 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int count_list(t_number *list_a)
{
	int num;
	num = list_a->n;
	int count;

	count = 0;
	while (list_a)
	{
		if (list_a->next != NULL)
			list_a = list_a->next;
		count++;
		if (num == list_a->n)
			break;
	}
	return (count);
}

void change_status_one(t_number *list_b)
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

void count_status(t_number *list_a)
{
    int n = list_a->n;
    int count = 0;
    while(list_a)
    {
        if (list_a->status == 1)
            count++;
        list_a = list_a->next;
        if (list_a->n == n)
             break;
    }
    printf("count status= %d\n", count);
    usleep(3000000);
}

void timsort(t_number *list_a, t_number *list_b)
{
    int count = 0;
    int q = 0;
    int n = 0;
    int quantity = 0;

    if ((n = count_list(list_a)) <= 100)
        q = 2;
    else
        q = 5;

    if (n % q == 0)
        quantity = n / q;
    else
        quantity = n / q + 1;

    // quantity = n / q;
    // printf("quantity = %d\n", quantity);
    // printf("q = %d\n", q);
    // usleep(3000000);

    count = insertion_sort_first(&list_a, &list_b, quantity);
    change_status_one(list_b);
    count += centering_stack_first(&list_a, &list_b);
    count += merge_sort_first(&list_a, &list_b);



    q--;
    while(q)
    {
        // printf("DO____quantity = %d\n", quantity);
        // usleep(3000000);
        count += insertion_sort_regular(&list_a, &list_b, quantity);
        // printf("POSLE_quantity = %d\n", quantity);
        // printf("q = %d\n", q);
        // count_status(list_a);
        // usleep(3000000);
        change_status_one(list_b);
        // printf("111111\n");
        // usleep(3000000);
        count += centering_stack_regular(&list_a, &list_b);
        // printf("111111\n");
        // usleep(3000000);
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
