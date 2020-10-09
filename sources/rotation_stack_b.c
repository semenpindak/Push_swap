/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_stack_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 01:00:35 by oem               #+#    #+#             */
/*   Updated: 2020/10/06 15:10:43 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotation_stack_b(t_num **list_a, t_num **list_b, t_key *bonus, int spin)
{
	int step;

	step = (*list_b)->step_b;
	while (step)
	{
		if (spin == 0)
		{
			rb(&list_b, bonus);
			debug_print_two(list_a, list_b, bonus);
		}
		else
		{
			rrb(&list_b, bonus);
			debug_print_two(list_a, list_b, bonus);
		}
		step--;
	}
}
