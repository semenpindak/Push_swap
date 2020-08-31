/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_regular_kv.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 20:39:30 by oem               #+#    #+#             */
/*   Updated: 2020/08/31 00:02:18 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int count_list_stack_a_status(t_number **list_a)
{
	int num;
	int count;

	num = (*list_a)->n;
	count = 0;
	while (*list_a)
	{
		if ((*list_a)->status == 1)
			count++;
		*list_a = (*list_a)->next;
		if (num == (*list_a)->n)
			break ;
	}
	return (count);
}

int	merge_sort_regular_kv(t_number **list_a, t_number **list_b, int i)
{
	int n;
	int n_stack_a = 0;

	n = count_list_two(list_b);
	n_stack_a = count_list_stack_a_status(list_a);
	while (n)
	{
		if ((*list_a)->n > (*list_b)->n)
		{
			ft_printf("exec ");
			pa_three(&list_a, &list_b);
			i++;
			ft_printf("move = %d\n", i);
			show_me_two(list_a, list_b);
			usleep(3000000);
			system("clear");

			n_stack_a++;
			n--;
		}
		if ((*list_b) != NULL && ((*list_b)->n > (*list_a)->n))
		{
			ft_printf("exec ");
			ra_three(&list_a);
			i++;
			ft_printf("move = %d\n", i);
			show_me_two(list_a, list_b);
			usleep(3000000);
			system("clear");

			n_stack_a--;
		}
		if (n_stack_a == 0)
		{
			while(n)
			{
				ft_printf("exec ");
				pa_three(&list_a, &list_b);
				i++;
				ft_printf("move = %d\n", i);
				show_me_two(list_a, list_b);
				usleep(3000000);
				system("clear");

				ft_printf("exec ");
				ra_three(&list_a);
				i++;
				ft_printf("move = %d\n", i);
				show_me_two(list_a, list_b);
				usleep(3000000);
				system("clear");

				n--;
			}
		}
		if (n == 0)
			break;
	}
	return (i);
}
