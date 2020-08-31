/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_first_kv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 20:37:05 by oem               #+#    #+#             */
/*   Updated: 2020/08/31 00:02:03 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int merge_sort_first_kv(t_number **list_a, t_number **list_b, int i)
{
	int n;

	n = count_list_two(list_b);
	while (n)
	{
		ft_printf("exec ");
		pa_three(&list_a, &list_b);
		i++;
		ft_printf("move = %d\n", i);
		show_me_two(list_a, list_b);
		usleep(3000000);
		system("clear");
		n--;
	}
	return (i);
}
