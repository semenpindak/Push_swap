/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_regular_kv.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 20:37:50 by oem               #+#    #+#             */
/*   Updated: 2020/08/31 00:02:08 by oem              ###   ########.fr       */
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

int insertion_sort_regular_kv(t_number **list_a, t_number **list_b, int quantity, int i)
{
    int step_a = 0;
    int step_b = 0;
    int logic_a = 0;
    int logic_b = 0;

    while (*list_a)
    {
        quantity--;
        if (*list_b == NULL)
        {
            i = pb_when_stack_b_null_kv(&list_a, &list_b, i);
            ft_printf("exec ");
		    pb_three(&list_a, &list_b);
		    i++;
		    ft_printf("move = %d\n", i);
		    show_me_two(list_a, list_b);
		    usleep(3000000);
            system("clear");
        }
        find_min_steps_from_a_to_b_three_regular(list_a, list_b);
        search_struct_to_move(list_a, &step_a, &step_b, &logic_a, &logic_b);
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
                    ft_printf("exec ");
		            rr_three(&list_a, &list_b);
		            i++;
		            ft_printf("move = %d\n", i);
		            show_me_two(list_a, list_b);
		            usleep(3000000);
                    system("clear");
                }
                else
                {
                    ft_printf("exec ");
		            rrr_three(&list_a, &list_b);
		            i++;
		            ft_printf("move = %d\n", i);
		            show_me_two(list_a, list_b);
		            usleep(3000000);
                    system("clear");
                }
                q--;
            }
        }
        while(step_a)
        {
            if (logic_a == 0)
            {
                ft_printf("exec ");
		        ra_three(&list_a);
		        i++;
		        ft_printf("move = %d\n", i);
		        show_me_two(list_a, list_b);
		        usleep(3000000);
                system("clear");
            }
            else
            {
                ft_printf("exec ");
		        rra_three(&list_a);
		        i++;
		        ft_printf("move = %d\n", i);
		        show_me_two(list_a, list_b);
		        usleep(3000000);
                system("clear");
            }
            step_a--;
        }
        while(step_b)
        {
            if (logic_b == 0)
            {
                ft_printf("exec ");
		        rb_three(&list_b);
		        i++;
		        ft_printf("move = %d\n", i);
		        show_me_two(list_a, list_b);
		        usleep(3000000);
                system("clear");
            }
            else
            {
                ft_printf("exec ");
		        rrb_three(&list_b);
		        i++;
		        ft_printf("move = %d\n", i);
		        show_me_two(list_a, list_b);
		        usleep(3000000);
                system("clear");
            }
            step_b--;
        }
        ft_printf("exec ");
		pb_three(&list_a, &list_b);
        i++;
		ft_printf("move = %d\n", i);
		show_me_two(list_a, list_b);
		usleep(3000000);
        system("clear");
        if (quantity == 1)
            break;
    }
    return(i);
}
