/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 07:15:23 by semen             #+#    #+#             */
/*   Updated: 2020/08/29 23:00:17 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_me(t_number *list_a, t_number *list_b)
{
	int n;

	n = count_list(list_a);
	ft_printf("n = %3d stack_a: ", n);
	while (n--)
	{
		ft_printf("%d ", list_a->n);
		list_a = list_a->next;
	}
	n = count_list(list_b);
	ft_printf("\nn = %3d stack_b: ", n);
	while (n--)
	{
		ft_printf("%d ", list_b->n);
		list_b = list_b->next;
	}
	ft_printf("\n");
}
