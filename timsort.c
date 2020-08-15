/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 14:26:34 by semen             #+#    #+#             */
/*   Updated: 2020/08/15 20:54:27 by calpha           ###   ########.fr       */
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
    // printf("%d\n", list_b->n);
	while (list_b)
	{
        list_b->status = 1;
		if (list_b->next != NULL)
			list_b = list_b->next;
		if (num == list_b->n)
			break;
	}
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
        quantity = (n - 1) / q;

    printf("quantity = %d\n", quantity);

    count = insertion_sort_first(&list_a, &list_b, quantity);
    change_status_one(list_b);
    count += centering_stack_first(&list_a, &list_b);
    count += merge_sort_first(&list_a, &list_b);

    n--;
    while(n)
    {
        count += insertion_sort_regular(&list_a, &list_b, quantity);
        change_status_one(list_b);
        count += centering_stack_regular(&list_a, &list_b);
        count += merge_sort_regular(&list_a, &list_b);
        n--;
    }
    printf("%d", count);

}
