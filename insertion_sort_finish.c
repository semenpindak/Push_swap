/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_finish.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:45:08 by oem               #+#    #+#             */
/*   Updated: 2020/09/02 13:21:16 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void insertion_sort_finish(t_number **list_a, t_number **list_b)
{
    // int step_a = 0;
    // int logic_a = 0;

    while (*list_b)
    {
        count_step_in_a(list_a, list_b);

		printf(" %d, %d\n", (*list_b)->rb, (*list_b)->lb);
        // search_struct_to_move(list_a, &step_a, &logic_a);
        // while(step_a)
        // {
        //     if (logic_a == 0)
        //         ra_three(&list_a);
        //     else
        //         rra_three(&list_a);
        //     step_a--;
        // }
        pa_three(&list_a, &list_b);
    }
}
