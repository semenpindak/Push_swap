/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertsort_finish.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:45:08 by oem               #+#    #+#             */
/*   Updated: 2020/09/04 09:44:24 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int rotation(t_num **list_b)
{
	if ((*list_b)->rb < (*list_b)->lb)
	{
		(*list_b)->logic_a = 1;
		return ((*list_b)->rb);
	}
	else
	{
		(*list_b)->logic_a = 0;
		return ((*list_b)->lb);
	}
	return (0);
}

void	insertsort_finish(t_num **list_a, t_num **list_b, t_key *bonus)
{
	if (*list_b != NULL)
	{
		count_step_in_a(list_a, list_b);
		(*list_a)->step_a = rotation(list_b);
		rotation_stack_a(list_a, list_b, bonus, (*list_b)->logic_a);
		pa(&list_a, &list_b, bonus);
		debug_print_two(list_a, list_b, bonus);
	}
}
