/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 07:15:23 by semen             #+#    #+#             */
/*   Updated: 2020/08/24 20:42:42 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_me(t_number *list_a, t_number *list_b)
{
	int n;

	n = count_list(list_a);
	printf("n = %d stack_a: ", n);
	while (n--)
	{
		printf("%d ", list_a->n);
		list_a = list_a->next;
	}
	n = count_list(list_b);
	printf("\nn = %d stack_b: ", n);
	while (n--)
	{
		printf("%d ", list_b->n);
		list_b = list_b->next;
	}
	printf("\n");
}
