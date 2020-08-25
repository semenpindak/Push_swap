/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_me_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:40:54 by semen             #+#    #+#             */
/*   Updated: 2020/08/25 19:22:19 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_me_two(t_number **list_a, t_number **list_b)
{
	int n;

	n = count_list_two(list_a);
	printf("n = %3d stack_a: ", n);
	while (n)
	{
		printf("%d ", (*list_a)->n);
		if ((*list_a)->next != NULL)
			*list_a = (*list_a)->next;
		n--;
	}
	printf("\n");
	n = count_list_two(list_b);
	printf("n = %3d stack_b: ", n);
	while (n)
	{
		printf("%d ", (*list_b)->n);
		if ((*list_b)->next != NULL)
			*list_b = (*list_b)->next;
		n--;
	}
	printf("\n");
}
