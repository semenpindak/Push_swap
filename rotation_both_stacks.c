/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joint_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 01:05:08 by oem               #+#    #+#             */
/*   Updated: 2020/10/06 16:23:09 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotation_both_stacks(t_num **list_a, t_num **list_b, t_key *bonus, int spin)
{
	int step;

	if ((*list_a)->step_a == (*list_b)->step_b)
		step = (*list_a)->step_a;
	if ((*list_a)->step_a > (*list_b)->step_b)
		step = (*list_b)->step_b;
	else
		step = (*list_a)->step_a;
	while (step)
	{
		if (spin == 0)
		{
			rr(&list_a, &list_b, bonus);
			debug_print_two(list_a, list_b, bonus);
		}
		else
		{
			rrr(&list_a, &list_b, bonus);
			debug_print_two(list_a, list_b, bonus);
		}
		step--;
	}
}
