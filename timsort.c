/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 14:26:34 by semen             #+#    #+#             */
/*   Updated: 2020/05/04 14:37:43 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void search_struct_to_move(t_number **list_a, int *step_a, int *step_b, int *logic_a, int *logic_b)
{
    int min = 2147483647;
    int num = (*list_a)->n;
    while (*list_a)
    {
        if ((*list_a)->sum_steps < min)
        {
            min = (*list_a)->sum_steps;
            *step_a = (*list_a)->step_a;
            *step_b = (*list_a)->step_b;
            *logic_a = (*list_a)->logic_a;
            *logic_b = (*list_a)->logic_b;
        }
        *list_a = (*list_a)->next;
        if (num == (*list_a)->n)
            break;
    }
}

void insertion_sort(t_number **list_a, t_number **list_b, int quantity)
{
    int i;

    i = 0;
    int step_a = 0;
    int step_b = 0;
    int logic_a = 0;
    int logic_b = 0;

    // int n;
    while (*list_a)
    {
        quantity--;
        if (*list_b == NULL)
        {
            pb_three(&list_a, &list_b);
            // show_me_two(list_a, list_b);
            // i++;
        }
        // printf("do\n");
        // show_me_two(list_a, list_b);
        find_min_steps_from_a_to_b_three(list_a, list_b);
        // printf("posle\n");
        // show_me_two(list_a, list_b);
        search_struct_to_move(list_a, &step_a, &step_b, &logic_a, &logic_b);

        // c = count_step_in_b(list_a, list_b, &logic);

        if ((logic_a == 0 && logic_b == 0) || (logic_a == 1 && logic_b == 1))
        {
            int zn;
            zn = step_a - step_b < 0 ? -(step_a - step_b) : step_a - step_b;
            int max;
            max = step_a > step_b ? step_a : step_b;
            int q = max - zn;
            step_a = step_a - q;
            step_b = step_b - q;
            while(q)
            {
                if (logic_a == 0)
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
                q--;
                usleep(3000000);
                // show_me_two(list_a, list_b);
            }
        }
        while(step_a)
        {
            if (logic_a == 0)
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
            step_a--;
            usleep(3000000);
            // show_me_two(list_a, list_b);
        }
        while(step_b)
        {
            if (logic_b == 0)
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
            step_b--;
            usleep(3000000);
            // show_me_two(list_a, list_b);
        }
        pb_three(&list_a, &list_b);
        // i++;
        usleep(3000000);
        show_me_two(list_a, list_b);

        if (quantity == 1)
            break;
    }
    // printf("insert_sort count operation = %d\n", i);
}

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
    // find_median_number(list_a);

    insertion_sort(&list_a, &list_b, quantity);
    change_status_one(list_b);
    merge_sort(&list_a, &list_b);
    insertion_sort(&list_a, &list_b, quantity);

    // int nnn = 7;
	// while(nnn)
	// {
	// 	printf("status = %d, n = %d | ", list_b->status, list_b->n);
	// 	list_b = list_b->next;
	// 	nnn--;
	// }

}
