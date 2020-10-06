/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 01:02:42 by oem               #+#    #+#             */
/*   Updated: 2020/10/06 15:10:43 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotation_stack_a(t_num **list_a, t_num **list_b, t_key *bonus, int spin)
{
	int step;

	step = (*list_a)->step_a;
	while (step)
	{
		if (spin == 0)
		{
			ra(&list_a, bonus);
			debug_print_two(list_a, list_b, bonus);
		}
		else
		{
			rra(&list_a, bonus);
			debug_print_two(list_a, list_b, bonus);
		}
		step--;
	}
}
