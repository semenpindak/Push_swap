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

void	insertsort_finish(t_num **list_a, t_num **list_b, t_key *bonus)
{
	if (*list_b != NULL)
	{
		count_step_in_a(list_a, list_b);
		(*list_b)->logic_a = (*list_b)->rb < (*list_b)->lb ? 1 : 0;
		(*list_a)->step_a = (*list_b)->rb < (*list_b)->lb ? (*list_b)->rb : (*list_b)->lb;
		rotation_stack_a(list_a, list_b, bonus, (*list_b)->logic_a);
		pa(&list_a, &list_b, bonus);
		debug_print_two(list_a, list_b, bonus);
	}
}
