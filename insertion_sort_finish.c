/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_finish.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:45:08 by oem               #+#    #+#             */
/*   Updated: 2020/09/02 22:49:57 by calpha           ###   ########.fr       */
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

void insertion_sort_finish(t_number **list_a, t_number **list_b)
{
	int step;

	step = 0;

		// show_me_two(list_a, list_b);
		count_step_in_a(list_a, list_b);
		// ft_printf("(*list_b)->rb = %d, (*list_b)->lb = %d\n", (*list_b)->rb, (*list_b)->lb);
		step = rotation(list_b);
		while (step)
		{
			if ((*list_b)->logic_a == 1)
			{
				ra_three(&list_a);
				// show_me_two(list_a, list_b);
			}
			else
			{
				rra_three(&list_a);
				// show_me_two(list_a, list_b);
			}
			step--;
		}
		pa_three(&list_a, &list_b);
		// show_me_two(list_a, list_b);
}
