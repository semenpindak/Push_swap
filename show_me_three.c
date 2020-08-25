/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_me_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 06:41:04 by calpha            #+#    #+#             */
/*   Updated: 2020/08/25 19:19:43 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_me_three(t_number ***list_a, t_number ***list_b)
{
	int n;

	n = count_list_three(list_a);
	printf("n = %3d stack_a: ", n);
	while (n--)
	{
		printf("%d ", (**list_a)->n);
		if ((**list_a)->next != NULL)
			**list_a = (**list_a)->next;
	}
	printf("\n");
	n = count_list_three(list_b);
	printf("n = %3d stack_b: ", n);
	while (n--)
	{
		printf("%d ", (**list_b)->n);
		if ((**list_b)->next != NULL)
			**list_b = (**list_b)->next;
	}
	printf("\n");
}
