/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_me_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 16:27:47 by semen             #+#    #+#             */
/*   Updated: 2020/08/25 19:18:37 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_me_b(t_number **list_b)
{
	int n;

	n = count_list_two(list_b);
	printf("n = %3d ", n);
	printf("stack_b: ");
	while (n--)
	{
		if (*list_b)
		{
			printf("%d ", (*list_b)->n);
			if ((*list_b)->next != NULL)
				*list_b = (*list_b)->next;
		}
		else
			break;
	}
	printf("\n");
}

