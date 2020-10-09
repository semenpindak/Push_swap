/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 07:15:23 by semen             #+#    #+#             */
/*   Updated: 2020/09/05 00:20:21 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_me(t_num *list_a, t_num *list_b, t_key *bonus)
{
	int n;

	n = count_list(list_a);
	ft_printf("n = %3d stack_a: ", n);
	while (n--)
	{
		if (list_a->status == 1 && bonus->key == 2)
			ft_printf("%c[%d;%dm%d%c[%dm ", 27, 1, 32, list_a->n, 27, 0);
		else
			ft_printf("%d ", list_a->n);
		list_a = list_a->next;
	}
	n = count_list(list_b);
	ft_printf("\nn = %3d stack_b: ", n);
	while (n--)
	{
		if (list_b->status == 1 && bonus->key == 2)
			ft_printf("%c[%d;%dm%d%c[%dm ", 27, 1, 33, list_b->n, 27, 0);
		else
			ft_printf("%d ", list_b->n);
		list_b = list_b->next;
	}
	ft_printf("\n");
}
