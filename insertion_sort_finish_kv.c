/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_finish_kv.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 20:10:58 by calpha            #+#    #+#             */
/*   Updated: 2020/09/02 22:34:38 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int rotation(t_number **list_b)
{
	if ((*list_b)->rb < (*list_b)->lb)
	{
		(*list_b)->logic_a = 0;
		return ((*list_b)->rb);
	}
	else
	{
		(*list_b)->logic_a = 1;
		return ((*list_b)->lb);
	}
	return (0);
}

int insertion_sort_finish_kv(t_number **list_a, t_number **list_b, int i)
{
    int step;

    step = 0;
    while (*list_b)
    {
        count_step_in_a(list_a, list_b);
        step = rotation(list_b);
        while (step)
	    {
		    if ((*list_b)->logic_a == 1)
		    {
                ft_printf("exec ");
                ra_three(&list_a);
                ft_printf("move = %d\n", ++i);
                show_me_two(list_a, list_b);
                usleep(3000000);
                system("clear");
		    }
		    else
		    {
                ft_printf("exec ");
                rra_three(&list_a);
                ft_printf("move = %d\n", ++i);
                show_me_two(list_a, list_b);
                usleep(3000000);
                system("clear");
		    }
		    step--;
	    }
        ft_printf("exec ");
        pa_three(&list_a, &list_b);
        ft_printf("move = %d\n", ++i);
        show_me_two(list_a, list_b);
        usleep(3000000);
        system("clear");
    }
    return (i);
}
