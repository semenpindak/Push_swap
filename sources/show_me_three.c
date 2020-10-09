/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_me_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 06:41:04 by calpha            #+#    #+#             */
/*   Updated: 2020/09/05 00:20:12 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_me_three(t_num ***list_a, t_num ***list_b, t_key *bonus)
{
	int n;

	n = count_list_three(list_a);
	printf("n = %3d stack_a: ", n);
	while (n--)
	{
		if ((**list_a)->status == 1 && bonus->key == 2)
			ft_printf("%c[%d;%dm%d%c[%dm ", 27, 1, 32, (**list_a)->n, 27, 0);
		else
			printf("%d ", (**list_a)->n);
		if ((**list_a)->next != NULL)
			**list_a = (**list_a)->next;
	}
	printf("\n");
	n = count_list_three(list_b);
	printf("n = %3d stack_b: ", n);
	while (n--)
	{
		if ((**list_b)->status == 1 && bonus->key == 2)
			ft_printf("%c[%d;%dm%d%c[%dm ", 27, 1, 33, (**list_b)->n, 27, 0);
		else
			printf("%d ", (**list_b)->n);
		if ((**list_b)->next != NULL)
			**list_b = (**list_b)->next;
	}
	printf("\n");
}
