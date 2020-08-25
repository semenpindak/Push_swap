/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 00:01:01 by semen             #+#    #+#             */
/*   Updated: 2020/08/25 19:54:47 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int merge_sort_first(t_number **list_a, t_number **list_b)
{
	int n;
	int i;

	n = count_list_two(list_b);
	i = 0;
	while (n)
	{
		// printf("command");
		pa_three(&list_a, &list_b);
		show_me_two(list_a, list_b);
		// printf("\ncounter %d", i++);
		// usleep(1000000);
		// system("clear");
		i++;
		n--;
	}
	return (i);
}
