/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 00:01:01 by semen             #+#    #+#             */
/*   Updated: 2020/08/24 19:47:44 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int count_list_two(t_number **list_b)
// {
// 	int num;
// 	int count;

//     num = (*list_b)->n;
// 	count = 0;
// 	while (*list_b)
// 	{
// 		if ((*list_b)->next != NULL)
// 			*list_b = (*list_b)->next;
// 		count++;
// 		if (num == (*list_b)->n)
// 			break;
// 	}
// 	return (count);
// }

int	merge_sort_first(t_number **list_a, t_number **list_b)
{
    int n;
    int i = 0;

    n = count_list_two(list_b);
    //  printf("n = %d\n", n);
    //  show_me_two(list_a, list_b);
    while (n)
    {
        pa_three(&list_a, &list_b);
        show_me_two(list_a, list_b);
        // usleep(100000);
        i++;
        n--;
    }
    return (i);
}
