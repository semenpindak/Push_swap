/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_regular.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:19:14 by calpha            #+#    #+#             */
/*   Updated: 2020/08/15 20:46:39 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int count_list(t_number **list_b)
{
	int num;
	int count;

    num = (*list_b)->n;
	count = 0;
	while (*list_b)
	{
		if ((*list_b)->next != NULL)
			*list_b = (*list_b)->next;
		count++;
		if (num == (*list_b)->n)
			break;
	}
	return (count);
}

static int find_max_number(t_number **list_b)
{
    int max;
	int n;

    max = (*list_b)->n;
    n = (*list_b)->n;
    while(*list_b)
    {
		*list_b = (*list_b)->next;
        if ((*list_b)->n > max)
            max = (*list_b)->n;
        if (n == (*list_b)->n)
            break;
    }
    // printf("find_max_number_right = %d\n", max);
    return (max);
}

int	merge_sort_regular(t_number **list_a, t_number **list_b)
{
	int i = 0;
    int n;
	int max = 0;

    n = count_list(list_b);

	// printf("max = %d\n", max);
    //  printf("n = %d\n", n);
    //  show_me_two(list_a, list_b);
    while (n)
    {
		max = find_max_number(list_a);
		if ((*list_b)->n > max)
		{
			while((*list_a)->n < max)
			{
				if ((*list_a)->n == max)
					break;
				else
					ra_three(&list_a);
			}
			ra_three(&list_a);
			i++;
			show_me_two(list_a, list_b);
			pa_three(&list_a, &list_b);
			i++;
			n--;
			show_me_two(list_a, list_b);
			if (n == 0)
				break;
		}
		if ((*list_a)->n > (*list_b)->n)
		{
			pa_three(&list_a, &list_b);
			show_me_two(list_a, list_b);
			i++;
			n--;
		}
		else
		{
			ra_three(&list_a);
			show_me_two(list_a, list_b);
			i++;
		}
		// usleep(500000);
    }
	return (i);
}
