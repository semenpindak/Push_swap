/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_me_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:40:54 by semen             #+#    #+#             */
/*   Updated: 2020/09/05 00:20:04 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_me_two(t_num **list_a, t_num **list_b, t_key *bonus)
{
	int n;

	n = count_list_two(list_a);
	ft_printf("n = %3d stack_a: ", n);
	while (n)
	{
		if ((*list_a)->status == 1 && bonus->key == 2)
			ft_printf("%c[%d;%dm%d%c[%dm ", 27, 1, 32, (*list_a)->n, 27, 0);
		else
			ft_printf("%d ", (*list_a)->n);
		if ((*list_a)->next != NULL)
			*list_a = (*list_a)->next;
		n--;
	}
	ft_printf("\n");
	n = count_list_two(list_b);
	ft_printf("n = %3d stack_b: ", n);
	while (n)
	{
		if ((*list_b)->status == 1 && bonus->key == 2)
			ft_printf("%c[%d;%dm%d%c[%dm ", 27, 1, 33, (*list_b)->n, 27, 0);
		else
			ft_printf("%d ", (*list_b)->n);
		if ((*list_b)->next != NULL)
			*list_b = (*list_b)->next;
		n--;
	}
	ft_printf("\n");
}
