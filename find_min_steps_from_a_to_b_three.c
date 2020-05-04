/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_steps_from_a_to_b_three.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 00:44:42 by semen             #+#    #+#             */
/*   Updated: 2020/05/03 23:57:42 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	record_value_in_stack_a(t_number ***list_a)
{
	int num;
	num = (**list_a)->n;
	int count;

	count = 0;
	while (**list_a)
	{
		(**list_a)->la = count;
		if ((**list_a)->next != NULL)
			(**list_a) = (**list_a)->next;
		count++;
		if (num == (**list_a)->n)
			break;
	}
	count = 0;
	while (**list_a)
	{
		(**list_a)->ra = count;
		if ((**list_a)->prev != NULL)
			(**list_a) = (**list_a)->prev;
		count++;
		if (num == (**list_a)->n)
			break;
	}
}

static int count_list(t_number **list_a)
{
	int num;
	num = (*list_a)->n;
	int count;

	count = 0;
	while (*list_a)
	{
		if ((*list_a)->next != NULL)
			*list_a = (*list_a)->next;
		count++;
		if (num == (*list_a)->n)
			break;
	}
	return (count);
}

static void	fill_struct_resulting_values(t_number **list_a)
{
	if ((*list_a)->ra < (*list_a)->la)
	{
		(*list_a)->step_a =  (*list_a)->ra;
		(*list_a)->logic_a = 1;
	}
	else
	{
		(*list_a)->step_a = (*list_a)->la;
		(*list_a)->logic_a = 0;
	}
	if ((*list_a)->ra == (*list_a)->la)
	{
		(*list_a)->step_a = (*list_a)->ra;
		(*list_a)->logic_a = 2;
	}
	if ((*list_a)->rb < (*list_a)->lb)
	{
		(*list_a)->step_b = (*list_a)->rb;
		(*list_a)->logic_b = 1;
	}
	else
	{
		(*list_a)->step_b = (*list_a)->lb;
		(*list_a)->logic_b = 0;
	}
	if ((*list_a)->rb == (*list_a)->lb)
	{
		(*list_a)->step_b = (*list_a)->rb;
		(*list_a)->logic_b = 2;
	}
	(*list_a)->sum_steps = (*list_a)->step_a + (*list_a)->step_b;
}

void	find_min_steps_from_a_to_b_three(t_number **list_a, t_number **list_b)
{
	int n;

	// printf("f = yes\n");
	record_value_in_stack_a(&list_a);
	// printf("f = yes\n");
	n = count_list(list_a);
	// printf("f = yes\n");

	// show_me_two(list_a, list_b);
	// if (*list_b != NULL)
	// {
		while (n)
		{
			// printf("n = %d\n", n);
			// printf("do\n");
        	// show_me_two(list_a, list_b);
			count_step_in_b_for_struct_three(list_a, list_b);
			// printf("posle\n");
        	// show_me_two(list_a, list_b);
			// usleep(3000000);
			fill_struct_resulting_values(list_a);

				// printf("n = %3d | ", (*list_a)->n);
				// printf("ra = %3d ", (*list_a)->ra);
				// printf("la = %3d ", (*list_a)->la);
				// printf("step_a = %3d ", (*list_a)->step_a);
				// printf("logic_a = %3d |", (*list_a)->logic_a);
				// printf("rb = %3d ", (*list_a)->rb);
				// printf("lb = %3d ", (*list_a)->lb);
				// printf("step_b = %3d ", (*list_a)->step_b);
				// printf("logic_b = %3d |", (*list_a)->logic_b);
				// printf("sum_steps = %3d ", (*list_a)->sum_steps);
			// printf("(*list_b)->n = %3d\n", (*list_b)->n);

			*list_a = (*list_a)->next;
			n--;
		}
	// }
	show_me_two(list_a, list_b);
}
