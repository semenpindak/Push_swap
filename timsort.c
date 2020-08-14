/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 14:26:34 by semen             #+#    #+#             */
/*   Updated: 2020/08/11 14:40:00 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int count_list(t_number *list_a)
// {
// 	int num;
// 	num = list_a->n;
// 	int count;

// 	count = 0;
// 	while (list_a)
// 	{
// 		if (list_a->next != NULL)
// 			list_a = list_a->next;
// 		count++;
// 		if (num == list_a->n)
// 			break;
// 	}
// 	return (count);
// }

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

	// pb(&list_a, &list_b);
    // pa(&list_b, &list_a);

    // sa(list_a);
    // sb(list_b);
    // ss(list_a, list_b);

    // ra(&list_a);
    // rb(&list_b);
    // rr(&list_a, &list_b);

    // rra(&list_a);
    // rrb(&list_b);
    // rrr(&list_a, &list_b);

    //  ДЕЛЕЖКА СТЕКА

    // int q = 0;
    // int n = 0;
    // int quantity = 0;

    // if ((n = count_list(list_a)) <= 100)
    //     q = 2;
    // else
    //     q = 5;

    // if (n % q == 0)
    //     quantity = n / q;
    // else
    //     quantity = (n - 1) / q;

    // printf("quantity = %d\n", quantity);

    //  ДЕЛЕЖКА СТЕКА

    // find_median_number(list_a);

    // insertion_sort_first(&list_a, &list_b);
    // change_status_one(list_b);
    // merge_sort_first(&list_a, &list_b);

    insertion_sort_regular(&list_a, &list_b);

    // change_status_one(list_b);


    // insertion_sort(&list_a, &list_b, quantity);

    // int nnn = 10;
	// while(nnn)
	// {
	// 	printf("status = %d, n = %d | ", list_a->status, list_a->n);
	// 	list_a = list_a->next;
	// 	nnn--;
	// }

}
